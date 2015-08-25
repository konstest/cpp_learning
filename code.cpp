//
// Глава 14. Упражнение 7. Определить класс Striped_Closed_Polilyne, используя приёмы из класса Striped_Rectangle.
// clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "code.h"

static const double PI = 3.14159265359;

unsigned int randint(int arg)
{
	return rand() % arg;
}

int rounding(double val)
{
	return ( (val - (int)val) >= 0.5 ) ? val+1 : val;
}

//------------------------------------------------------------------------------

bool intersection (Point A, Point B, Point C, Point D, Point& cross)
{
    double Znam = (D.y - C.y)*(B.x - A.x) - (D.x - C.x)*(B.y - A.y);
    if (Znam != 0) { // Если линии не параллельны...
        double Ua = ((D.x - C.x)*(A.y - C.y) - (D.y - C.y)*(A.x - C.x))/Znam;
        double Ub = ((B.x - A.x)*(A.y - C.y) - (B.y - A.y)*(A.x - C.x))/Znam;
        if ( 0 <= Ua && Ua <= 1 && 0 <= Ub && Ub <= 1) {
			double x = A.x + Ua*(B.x - A.x);
			double y = A.y + Ua*(B.y - A.y);
			cross.x = rounding(x);
			cross.y = rounding(y);
			return true;
        }
		else	//линии пересекаются за своими отезками
			return false;	
	}
	else
		return false;	//линии параллельны
}

//Упорядочиваем координаты пересечения с лева на права
void regulation(vector<Point> &P)
{
	bool swap = true;
	int data;
	while (swap) {
		swap = false;
		for (int i=1; i<P.size(); i++)
			if (P[i-1].x > P[i].x) {
				swap = true;
				data = P[i-1].x;
				P[i-1].x = P[i].x;
				P[i].x = data;
			}
	}
}

//------------------------------------------------------------------------------

void Striped_closed_Polilyne::draw_lines()	const
{
    if (color().visibility()) {
		Shape::draw_lines();    // first draw the "open poly line part"
	    fl_line(point(number_of_points()-1).x, 
	    point(number_of_points()-1).y,
	    point(0).x,
	    point(0).y);
    }
    if (fill_color().visibility()) {
	    Fl_Color oldc = fl_color();
        fl_color(fill_color().as_int());
	    fl_line_style(0,size);
    	//background.draw_lines();
    	//здесь фон в ручную расчитываю, так было сделано намерено, т.к.
    	//если оставить в классе переменную background типа Lines, то пришлось бы
    	//при добавлении каждой точки, функцией add(p) заново расчитывать для
    	//получившегося многоугольника фон. Что сильно бы сказывалось на производительности 
    	
    	//определяем края нашей фигуры(рамку)
    	int x_left = point(0).x, x_right = point(0).x, y_top = point(0).y, y_down = point(0).y;
    	for (int i=0; i<number_of_points(); i++) {	
        	if (x_right < point(i).x)
        		x_right = point(i).x;
        	if (x_left > point(i).x)
        		x_left = point(i).x;
        	if (y_top > point(i).y)
		    	y_top = point(i).y;
			if (y_down < point(i).y)
		    	y_down = point(i).y;
        }
        //рисуем линии(пока мысленно) сверху вниз с шагом f ищя их пересечения 
        //с нашей фигурой
    	for (int f = foot; y_top+f < y_down; f+=foot) {
	        vector<Point> p_crosses;
    		Point cross;
	    	for (int i=1; i < number_of_points(); i++)
	    		if ( intersection(Point(x_left,y_top+f),Point(x_right,y_top+f),
	    			point(i-1),point(i),cross) )
	    			p_crosses.push_back(cross);
    		if ( intersection(Point(x_left,y_top+f),Point(x_right,y_top+f),
    			point(number_of_points()-1),point(0),cross) )
    			p_crosses.push_back(cross);
    //упорядочиваем найденные точки пересечения слева на право в порядке возрастания
	    	regulation(p_crosses);
 			for (int i=0; i<p_crosses.size(); i++)
				for (int j=0; j<number_of_points(); j++)
			//Если линия пересечения попала в вершину много угольника, то
			// смотрим какая это вершина
					if (p_crosses[i].x == point(j).x && p_crosses[i].y == point(j).y) {
						int y_pred = point(number_of_points()-1).y;
						if (j > 0)
							y_pred = point(j-1).y;
						int y_posl = point(0).y;
						if (j < number_of_points()-1 )
							y_posl = point(j+1).y;
			//Если пред идущая вершина выше, а после идущая ниже или на оборот
			// (получается преломляющаяся в вершине point(j) линия), то удаляем
			// продублировавшуюся координату пересечения
						if ((y_pred >= point(j).y && y_posl <= point(j).y) ||
						(y_pred <= point(j).y && y_posl >= point(j).y)) {
							//удаляем одну из одинаковых координат
							//совпадающих с вершиной многоугольника
							p_crosses.erase(p_crosses.begin()+i);
							break;
						}
					}
	    	//И наконец рисуем линии фона!
			for (int i=1; i < p_crosses.size(); i+=2)
		        fl_line(p_crosses[i-1].x,y_top+f,p_crosses[i].x,y_top+f);
    	}
	    fl_color(oldc);      // reset color (to previous)
	    fl_line_style(0);    // reset line style to default
    }
}

//------------------------------------------------------------------------------

int main ()
try
{
	Simple_window win(Point(10,10),1800,1000,"Chapter 14.");

	Striped_closed_Polilyne MPoly;

	srand (time(NULL));

	MPoly.add(Point(randint(win.x_max()),randint(win.y_max())));

	MPoly.set_style(Line_style(Line_style::solid,5));
	MPoly.set_fill_color(Color::black);
	MPoly.set_color(Color::white);
	MPoly.size = 3;
	MPoly.foot = 7;
	win.attach(MPoly);
	win.wait_for_button();

	while (true) {
		MPoly.add(Point(randint(win.x_max()),randint(win.y_max())));
		MPoly.set_fill_color(randint(256));
		MPoly.set_color(randint(256));
		win.wait_for_button();
	}
}
catch(exception& e) {
    return 1;
}
catch(...) {
    return 2;
}

