/*
 Глава 14. Упражнение 12.
		Модифицируйте класс Binary_tree так, чтобы он рисовал свои узлы с помощью
 виртуальной функции. Затем выведите из класса Binary_tree новый класс, в котором
 эта виртуальная функция замещается так, что узлы изображаются иначе (например,
 в виде треугольников).
 clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code
*/

#include "code.h"

const double PI = 3.141592653589;

//------------------------------------------------------------------------------
//	Округление числа с плавающей точкой
unsigned int rounding(double k)
{
	return ( (k-(int)k) < 0.5 ) ? k : k+1;
}

// Поворачиваем точку P на угол angle с радиусом R
Point rotation(Point P, double angle, int R)
{
	double x = P.x - (double)R * cos((angle*PI)/180);
	double y = P.y - (double)R * sin((angle*PI)/180);
	return Point(rounding(x),rounding(y));
}

//конструктор создания правильной n- угольной звезды
Star::Star(Point cc, int nn, int pp, int RR, int AA)
:center_xy(cc), n(nn), p(pp), R(RR), r(0), A(AA)
{ }

//Конструктор создания звезды с ручной установкой радиуса внутренней окружности 
Star::Star(Point cc, int nn, int pp, int RR, int rr, int AA)
:center_xy(cc), n(nn), p(pp), R(RR), r(rr), A(AA)
{ }

// Отрисовка звезды
void Star::draw_lines() const
{
	double angle = 360/n;	//определяем угол вершин
	double a = 0 + A;
	vector<Point> P;
	if (r == 0) {
		for (int i = 0; i < n; i++) {						//
			P.push_back( rotation(center_xy, a, R) );			//ищем координаты
			a = a + angle;									//вершин правильной
		}													//звезды
	}
	else {
		for (int i = 0; i < n; i++) {						//ищем координаты вершин
			P.push_back( rotation(center_xy, a, R) );			//на внешней и
			P.push_back( rotation(center_xy, a+angle/2, r) );	//на внутренней окружностях
			a = a + angle;									//
		}													//
	}

	int np = P.size();
	if (r == 0) {//Рисование правильной звезды, не заполненной
		if (color().visibility())
			for (int i = 0; i < np; i++)
				if (i+p < np - 1)//рисуется линия от точки минуя p кол-во вершин
					fl_line(P[i].x,P[i].y,P[i+p+1].x,P[i+p+1].y);
				else
					fl_line(P[i].x,P[i].y,P[i+p-(np-1)].x,P[i+p-(np-1)].y);
	}
	else {//рисуем звезду с установленным внутренним радиусом
		if (fill_color().visibility()) {				//
		    fl_color(fill_color().as_int());			//
		    fl_begin_complex_polygon();					//заполняем цветом
		    for(int i=0; i<np; ++i)						//внутреннюю часть
		        fl_vertex(P[i].x, P[i].y);				//звезды
		    fl_end_complex_polygon();					//
		    fl_color(color().as_int());		// reset color	//
		}

		if (color().visibility()) {
		    for (unsigned int i=1; i<np; ++i)
		        fl_line(P[i-1].x,P[i-1].y,P[i].x,P[i].y);
		    fl_line(P[np-1].x,P[np-1].y,P[0].x,P[0].y);
		}
	}
}

// Установка радиуса внутренней окружности
void Star::set_intradius(int rr)
{
	if (rr < R-10) r = rr;
	else error ("Слишком большой радиус внтуренний окружности");
}

// Установка числа вершин пропуская которые соединяются рёбрами вершины, т.е.
// в 5- конечной звезде через 1, в 7 уже можно и через 2, в 9 - 3, и.т.д.
void Star::set_num_across_vert(int pp)
{//Если рисуется не правильная звезда, а с вручную установленным радиусом, то
// изменение количества промежуточных вершин нам ничего даст, т.к. там прорисовка
// выполняется через дополнительный поворот координат лежащих на внутренней 
// окружности ещё на половину угла angle/2, т.е. по середине между вершинами
	if (r == 0) {
		if ( (3 + pp*2) <= n)	//проверяем корректность установки 
			p = pp;
		else
			error("Не правильное установка количества промежуточных вершин");
	}
}

//------------------------------------------------------------------------------
//Считает количество узлов на указанном уровне
int Binary_tree::nodes_count(int lvl)
{
	if (lvl < 3)
		return lvl;
	else {
		int k = 2;
		for (int i = 2; i < lvl; i++)
			k = k*2;
		return k;
	}
}

//------------------------------------------------------------------------------
//Конструктор в котором просчитывается 
Binary_tree::Binary_tree(Point xy, int l, Nodes_type t )
: level(l)
{
	int y=0, x=0;
	if (level > 0) {
	//Draw nodes:
		x = width*(nodes_count(level)-1);
		for (int i=level; i > 1; i--) {
			y = (i - 1)*height;
			for (int j = xy.x-x/2, k = 0; k < nodes_count(i); k++, j=j+x/(nodes_count(i)-1)){
				if (t == Nodes_type::circle)
					nodes.push_back(new Star(Point(j,xy.y+y), 14, 0, links_radius, 90));;
				if (t == Nodes_type::star)
					nodes.push_back(new Star(Point(j,xy.y+y), 5, 1, links_radius, 90));
				if (t == Nodes_type::triangle)
					nodes.push_back(new Star(Point(j,xy.y+y), 3, 0, links_radius, 90));
			}
			x = x - (x/(nodes_count(i)-1));
		}
		//root tree
		if (t == Nodes_type::circle)
			nodes.push_back(new Star(xy, 13, 0, links_radius, 90));;
		if (t == Nodes_type::star)
			nodes.push_back(new Star(xy, 5, 1, links_radius, 90));
		if (t == Nodes_type::triangle)
			nodes.push_back(new Star(xy, 3, 0, links_radius, 90));
	//Draw links:
		int count = nodes_count(level),d = 0,i = 0,c = 0;
		while ( count > 1 ) {
			d += count;
			c = i + count;
			while (i < d) {
				links.push_back(new Lines());
				Point P1 = nodes[i].center(), P2 = nodes[i+1].center(), P3 = nodes[c].center();
				links[links.size()-1].add( Point(P1.x,P1.y-links_radius), Point(P3.x,P3.y+links_radius) );
				links.push_back(new Lines());
				links[links.size()-1].add( Point(P2.x,P2.y-links_radius), Point(P3.x,P3.y+links_radius) );
				i += 2;
				c++;
			}
			count = count/2;
		}
	}
}

//------------------------------------------------------------------------------
//Отрисовка на экране
void Binary_tree::draw_lines()	const
{
	for (int i=0; i < nodes.size(); i++)
		nodes[i].draw_lines();
	for (int i=0; i < links.size(); i++)
		links[i].draw_lines();
}

//------------------------------------------------------------------------------
int main ()
try
{
	int w = 1920;
	int h = 1000;
	Simple_window win(Point((x_max() - w)/2,(y_max() - h)/2),w,h,"Chapter 14. Exam 12. Starship Troopers");

	Binary_tree	tree(Point(win.x_max()/2,50),6, Binary_tree::star);
	tree.set_color(Color::blue);
	tree.set_style(Line_style(Line_style::solid,3));
	win.attach(tree);
	win.wait_for_button();
}
catch(exception& e) {
    return 1;
}
catch(...) {
    return 2;
}

