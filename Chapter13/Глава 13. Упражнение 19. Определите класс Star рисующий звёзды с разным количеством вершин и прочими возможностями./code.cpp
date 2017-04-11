//
// Глава 13. Упражнение 19. Определите класс Star рисующий звёзды с разным количеством вершин и прочими возможностями.
// Измененая команда компиляции, а именно code.cpp добавлена в конец.
// clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "code.h"

using namespace Graph_lib;

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
:center(cc), n(nn), p(pp), R(RR), r(0), A(AA)
{ }

//Конструктор создания звезды с ручной установкой радиуса внутренней окружности 
Star::Star(Point cc, int nn, int pp, int RR, int rr, int AA)
:center(cc), n(nn), p(pp), R(RR), r(rr), A(AA)
{ }

// Отрисовка звезды
void Star::draw_lines() const
{
	double angle = 360/n;	//определяем угол вершин
	double a = 0 + A;
	vector<Point> P;
	if (r == 0) {
		for (int i = 0; i < n; i++) {						//
			P.push_back( rotation(center, a, R) );			//ищем координаты
			a = a + angle;									//вершин правильной
		}													//звезды
	}
	else {
		for (int i = 0; i < n; i++) {						//ищем координаты вершин
			P.push_back( rotation(center, a, R) );			//на внешней и
			P.push_back( rotation(center, a+angle/2, r) );	//на внутренней окружностях
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
		    for(int i=0; i<np; ++i)		//внутреннюю часть
		        fl_vertex(P[i].x, P[i].y);		//звезды
		    fl_end_complex_polygon();					//
		    fl_color(color().as_int());	// reset color	//
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

int main ()
try
{
    Simple_window win(Point(50,50),800,600,"Chapter 13.");

	Text T(Point(100,50),"True star.");
	T.set_font_size(20);
	win.attach(T);
	
	Star A(Point(200,200),5,1,100,90);
	A.set_color(Color::blue);
	A.set_style(Line_style(Line_style::solid,2));
	win.attach(A);
	win.wait_for_button();
	
	ostringstream os;
	for (int i = 5; i < 18; i++) {
		os.str("");
		os << i*10;
		T.set_label("Turn the star by "+os.str()+" degrees.");
		A.set_angle(i*10);
		win.wait_for_button();
	}

	T.set_label("True star.");
	A.set_angle(90);
	A.set_num_vert(5);
	A.set_num_across_vert(1);
	win.wait_for_button();

	T.set_label("6 point star.");
	A.set_num_vert(6);
	win.wait_for_button();

	T.set_label("7 point star.");
	A.set_num_vert(7);
	A.set_num_across_vert(1);
	win.wait_for_button();

	T.set_label("6 point star and across 2 ribs.");
	A.set_num_across_vert(2);
	win.wait_for_button();

	T.set_label("8 point star.");
	A.set_num_vert(8);
	A.set_num_across_vert(1);
	win.wait_for_button();

	T.set_label("8 point star and across 2 ribs.");
	A.set_num_vert(8);
	A.set_num_across_vert(2);
	win.wait_for_button();

	T.set_label("9 point star.");
	A.set_num_vert(9);
	A.set_num_across_vert(1);
	win.wait_for_button();

	T.set_label("9 point star and across 2 ribs.");
	A.set_num_vert(9);
	A.set_num_across_vert(2);
	win.wait_for_button();

	T.set_label("9 point star and across 3 ribs.");
	A.set_num_vert(9);
	A.set_num_across_vert(3);
	win.wait_for_button();

	//Теперь меняем внутренний радус
	os.str("");
	os << A.radius()/4;
	T.set_label("True star with internal radius: "+os.str());
	A.set_num_vert(5);
	A.set_num_across_vert(1);
	A.set_intradius(A.radius()/4);
	win.wait_for_button();
	
	T.set_label("6 point star with internal radius: "+os.str());
	A.set_num_vert(6);
	win.wait_for_button();

	T.set_label("10 point star with internal radius: "+os.str()+" as a snowflake :)");
	A.set_num_vert(10);
	win.wait_for_button();

	T.set_label("Change color.");
	A.set_fill_color(Color::red);
	win.wait_for_button();

	A.set_fill_color(Color::green);
	A.set_intradius(A.radius()/2);
	win.wait_for_button();

	A.set_fill_color(Color::yellow);
	A.set_intradius(A.radius()/5);
	win.wait_for_button();

	T.set_label("Good bay!");
	A.set_num_vert(20);
	A.set_fill_color(Color::white);
	win.wait_for_button();
}
catch(exception& e) {
    // some error reporting
    return 1;
}
catch(...) {
    // some more error reporting
    return 2;
}

