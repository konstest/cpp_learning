//
// Глава 13. Упражнение 13. Матрица из раздела 13.10, только без линий, окаймляющих каждую ячейку.
// c++ -o code code.cpp GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp -lfltk -lfltk_images -std=c++11

#include "code.h"

using namespace Graph_lib;

rotate (int x, int y, int r, int angle)
{
	return Point(x - r*cos(angle/180),y - r*sin(angle/180));
}

Triangle::Triangle(Point P0, int ww, int aa): w(ww), angle(aa)
{
	if (color().visibility()) {
		Point P1 = rotation(P0.x,P0.y,w,angle);
		Point P2 = rotation(P0.x,P0.y,w,angle+60);
		fl_line(P0.x,P0.y,P1.x,P1.y);
		fl_line(P1.x,P1.y,P2.x,P2.y);
		fl_line(P2.x,P2.y,P0.x,P0.y);
	}
}

int main ()
try
{
    Simple_window win(Point(10,10),800,600,"Chapter 13:");

	Triangle T(Point(100,100),50,180);
	T.set_style(Line_style::solid,4);
	win.attach(T);
	
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
