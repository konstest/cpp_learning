//
// Глава 13. Упражнение 11. Элипс из фокусов которого уходят линий в точку на его границе.
// c++ -o code code.cpp GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp -lfltk -lfltk_images -std=c++11

#include "code.h"

using namespace Graph_lib;

const double PI = 3.14159265;	//Значение Пи

Point rotation(int x, int y, int width, int height, int angle)
{
	return Point(x - width*cos((angle*PI)/180), y - height*sin((angle*PI)/180));
}

//------------------------------------------------------------------------------
//	For CIRCLE
//North
Point n(const Ellipse& ellipse) {
	return Point(ellipse.point(0).x + ellipse.major(), ellipse.point(0).y);
}

//North-West
Point nw(const Ellipse& ellipse) {
//Представляем наш отрезок как вектор и поворачиваем его на заданный угол
	return rotation(ellipse.point(0).x + ellipse.major(),ellipse.point(0).y + ellipse.minor(),
	ellipse.major(), ellipse.minor(), 45);
}

//North-East
Point ne(const Ellipse& ellipse) {
	return rotation(ellipse.point(0).x + ellipse.major(),ellipse.point(0).y + ellipse.minor(),
	ellipse.major(), ellipse.minor(), 135);
}

//East
Point e(const Ellipse& ellipse) {
	return Point(ellipse.point(0).x + ellipse.major()*2, ellipse.point(0).y + ellipse.minor());
}

//South-East
Point se(const Ellipse& ellipse) {
	return rotation(ellipse.point(0).x + ellipse.major(),ellipse.point(0).y + ellipse.minor(),
	ellipse.major(), ellipse.minor(), 225);
}

//South
Point s(const Ellipse& ellipse) {
	return Point(ellipse.point(0).x + ellipse.major(), ellipse.point(0).y + ellipse.minor()*2);
}

//South-West
Point sw(const Ellipse& ellipse) {
	return rotation(ellipse.point(0).x + ellipse.major(),ellipse.point(0).y + ellipse.minor(),
	ellipse.major(), ellipse.minor(), 315);
}

//West
Point w(const Ellipse& ellipse) {
	return Point(ellipse.point(0).x, ellipse.point(0).y + ellipse.minor());
}

//Center Rectangle
Point center(const Ellipse& ellipse) {
	return ellipse.center();
}


//------------------------------------------------------------------------------

Arrow::Arrow (Point p1, Point p2)
: r1(r1), r2(r2)
{
	//Узнаём длину отрезка (нашей стрелки)
	double width_arrow = sqrt( double(pow(p2.x-p1.x,2) + pow(p2.y-p1.y,2)) );
	r1 = width_arrow/10;
	r2 = r1/2;
	add(p1);
	add(p2);
}

void Arrow::draw_lines()	const
{
	if (color().visibility()) {
		//Узнаём длину отрезка (нашей стрелки)
		double width_arrow = sqrt( double(pow(point(1).x-point(0).x,2) + pow(point(1).y-point(0).y,2)) );
		//через отношение ищем координаты нашей второй окружности лежащей на
		//расстоянии r1 от точки point(1), точки куда указывает стрелка
		double lambda = r1 / width_arrow;
		//Узнаём координаты второй окружности с радиусом r2
		int xM = (point(1).x + lambda*point(0).x)/(1+lambda);
		int yM = (point(1).y + lambda*point(0).y)/(1+lambda);
		//Вычислим координаты точек линий стрелки (>) для этого возмём единичный 
		//вектор от P1 до P2, повернём его на +90 градусов для P3 (-90 для P4) и умножим на r2.
		int P3x = xM + (point(1).y - yM)*r2/r1;
		int P3y = yM - (point(1).x - xM)*r2/r1;
		int P4x = xM - (point(1).y - yM)*r2/r1;
		int P4y = yM + (point(1).x - xM)*r2/r1;
		//рисуем указатель (>)
	    fl_line(point(1).x,point(1).y,P3x,P3y );
	    fl_line(point(1).x,point(1).y,P4x,P4y );
	}
	//Дорисовываем саму (длинную) линию стрелки
	Shape::draw_lines();
}

//------------------------------------------------------------------------------

int main ()
try
{
    Simple_window win(Point(10,10),800,600,"Chapter 13:");

    Arrow os_X(Point(200,300),Point(600,300),20,7);
    os_X.set_style(Line_style(Line_style::solid,4));
    win.attach(os_X);

    Arrow os_Y(Point(400,450),Point(400,150),20,7);
    os_Y.set_style(Line_style(Line_style::solid,4));
    win.attach(os_Y);

	Ellipse El(Point(400,300),150,100);
	El.set_color(Color::red);
	El.set_style(Line_style(Line_style::solid,4));
	win.attach(El);
	
	Line L1(El.focus1(),ne(El));
	L1.set_style(Line_style(Line_style::solid,4));
	L1.set_color(Color::yellow);
	win.attach(L1);

	Line L2(El.focus2(),ne(El));
	L2.set_style(Line_style(Line_style::solid,4));
	L2.set_color(Color::yellow);
	win.attach(L2);

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

//------------------------------------------------------------------------------
