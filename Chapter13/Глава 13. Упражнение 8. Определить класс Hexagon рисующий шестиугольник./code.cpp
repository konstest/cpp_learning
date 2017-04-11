//
// Глава 13. Упражнение 8. Определить класс Hexagon рисующий шестиугольник.
// clear && c++ -o code code.cpp GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "code.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

Hexagon::Hexagon(Point cc, int dd) :d(dd)
{
	add(Point(cc.x-dd,cc.y));
	int d2 = dd/2;
	add(Point(cc.x-dd/2,cc.y-sqrt(dd*dd-d2*d2)));
	add(Point(cc.x+dd/2,cc.y-sqrt(dd*dd-d2*d2)));
	add(Point(cc.x+dd,cc.y));
	add(Point(cc.x+dd/2,cc.y+sqrt(dd*dd-d2*d2)));
	add(Point(cc.x-dd/2,cc.y+sqrt(dd*dd-d2*d2)));
}

void Hexagon::draw_lines() const
{
	if (color().visibility())
		fl_line(point(number_of_points()-1).x,point(number_of_points()-1).y,
			point(0).x,point(0).y);
	Shape::draw_lines();
}
//------------------------------------------------------------------------------

int main ()
try
{
    Simple_window win(Point(10,10),600,400,"Chapter 13.");
	
	Hexagon A(Point(300,250),100);
	A.set_style(Line_style(Line_style::solid,4));
	win.attach(A);

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

