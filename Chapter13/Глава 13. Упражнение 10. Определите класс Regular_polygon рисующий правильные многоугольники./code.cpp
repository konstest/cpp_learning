//
// Глава 13. Упражнение 10. Определите класс Regular_polygon рисующий правильные многоугольники.
// clear && c++ -o code code.cpp GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "code.h"

using namespace Graph_lib;

const double PI = 3.141592653589;

//------------------------------------------------------------------------------
Point rotation (int x, int y, int r, double angle)
{
	return	Point(x - r*cos((angle*PI)/180), y - r*sin((angle*PI)/180));
}

Regular_Polygon::Regular_Polygon(Point P, int dd, int cc) :d(dd), count(cc)
{
	if (cc<3) error("Number of angles less than three.");
	double angle = 360/cc;
	for (unsigned int i = 0; i < 360; i += angle)
		add(rotation ( P.x - dd, P.y, dd, i));
}

void Regular_Polygon::draw_lines() const
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

	int count = 3, max_count = 30, size = 100;
	Point P(300,200);
	Vector_ref<Regular_Polygon> RP;
	RP.push_back(new Regular_Polygon(P,size,count));
	RP[0].set_style(Line_style(Line_style::solid,3));
	win.attach(RP[0]);
    win.wait_for_button();

	for (unsigned int i = 1; i < max_count; i++)
	{
		RP[i-1].set_color( Color::invisible );
		RP.push_back(new Regular_Polygon(Point(P.x + i, P.y + i), size + i, count + i));
		RP[i].set_style(Line_style(Line_style::solid,3));
		win.attach(RP[i]);
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

