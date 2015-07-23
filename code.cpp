//
// Глава 13. Упражнение 3. Создать класс Arrow рисующий стрелки.
// c++ -o code code.cpp GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp -lfltk -lfltk_images -std=c++11

#include "code.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

void Arc::draw_lines() const
{
    if (color().visibility())
        fl_arc(point(0).x,point(0).y,w+w,h+h,a_b,a_e);
}

//------------------------------------------------------------------------------

Point Arc::center()	const
{
	return Point(point(0).x+w,point(0).y+h);
}

//------------------------------------------------------------------------------
// Rotation дуги
void rotation (Arc& A)
{
	int b = A.angle_begin(), e = A.angle_end();
	if (e<360) { b+=90; e+=90; } 
	else { b=0; e=90; }
	A.set_angle(b,e);
}

//------------------------------------------------------------------------------

void Box::draw_lines() const
{
    if (color().visibility()) {
    	//draw arcs
        fl_arc(point(0).x,point(0).y,a_w+a_w,a_h+a_h,90,180);
        fl_arc(point(0).x+w-(a_w+a_w),point(0).y,a_w+a_w,a_h+a_h,0,90);
        fl_arc(point(0).x,point(0).y+h-(a_h+a_h),a_w+a_w,a_h+a_h,180,270);
        fl_arc(point(0).x+w-(a_w+a_w),point(0).y+h-(a_h+a_h),a_w+a_w,a_h+a_h,270,360);
		//draw lines
        fl_line(point(0).x,point(0).y+a_h,point(0).x,point(0).y+h-a_h);
        fl_line(point(0).x+w,point(0).y+a_h,point(0).x+w,point(0).y+h-a_h);
        fl_line(point(0).x+a_w,point(0).y,point(0).x+w-a_w,point(0).y);
        fl_line(point(0).x+a_w,point(0).y+h,point(0).x+w-a_w,point(0).y+h);
    }
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

//------------------------------------------------------------------------------

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
    Simple_window win(Point(10,10),1600,1200,"Chapter 13. Exercise 3:");

    int w=50, h=50, b=0, e=90;

    Arrow A(Point(400,700),Point(1000,150));
    A.set_color(Color::yellow);
    A.set_style(Line_style(Line_style::solid,9));
    win.attach(A);

    Arrow B(Point(400,700),Point(1000,150));
    B.set_color(Color::blue);
    B.set_style(Line_style(Line_style::solid,2));
    win.attach(B);

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
