//
// Глава 13. Упражнение 1. Создать класс Arc, рисующий часть эллипса.
//
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

void rotation (Arc& A)
{
	int b = A.angle_begin(), e = A.angle_end();
	if (e<360) { b+=90; e+=90; } 
	else { b=0; e=90; }
	A.set_angle(b,e);
}

int main ()
try
{
	
    Simple_window win(Point(100,100),800,800,"Chapter 13. Exercise 1:");

    int w=50, h=50, b=0, e=90;

    Arc A(Point(50,50),w,h,b,e);
    A.set_color(Color::green);
    A.set_style(Line_style(Line_style::solid,4));
    win.attach(A);

	int i=h;
	for (;i<win.x_max(); i+=50) {
		A.set_major(i);
		A.set_minor(i);
		Mark m1(A.center(),'x');
	    win.attach(m1);
		rotation(A);
		win.wait_for_button();
	}

	for (;i>50; i-=50) {
		A.set_major(i);
		A.set_minor(i);
		Mark m1(A.center(),'x');
	    win.attach(m1);
		rotation(A);
		win.wait_for_button();
	}
    
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
