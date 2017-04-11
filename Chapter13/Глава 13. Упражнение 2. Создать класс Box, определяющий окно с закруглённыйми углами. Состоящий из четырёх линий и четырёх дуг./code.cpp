//
// Глава 13. Упражнение 2. Создать класс Box, определяющий окно с закруглённыйми углами.
// Состоящий из четырёх линий и четырёх дуг.
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

int main ()
try
{
	
    Simple_window win(Point(100,100),800,800,"Chapter 13. Exercise 1:");

    int w=50, h=50, b=0, e=90;

    Box B(Point(300,300),200,200,60,40);
    B.set_color(Color::blue);
    B.set_style(Line_style(Line_style::solid,6));
    win.attach(B);
    
    int i=200;
    for (;i<win.x_max()/2; i+=30) {
    	B.set_width(i);
    	B.set_height(i);
	    win.wait_for_button();
    }

    for (;i>30; i-=30) {
    	B.set_width(i);
    	B.set_height(i);
	    win.wait_for_button();
    }
    
	B.set_width(200);
	B.set_height(200);
	B.set_major(30);
	B.set_minor(30);

    i=30;
    for (;i<win.x_max(); i+=30) {
		B.set_major(i);
		B.set_minor(i);
	    win.wait_for_button();
    }

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
