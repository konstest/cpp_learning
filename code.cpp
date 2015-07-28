//
// Глава 13. Упражнение 9. Покройте часть окна узорами в виде объектов класса Hexagon.
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
	
	Vector_ref<Hexagon> vh;
	int d = 40, k = 0, SQRT = sqrt(d*d-(d/2)*(d/2));
	for (unsigned int i = 0; i < win.x_max(); i = i + d*3)
		for (unsigned int j = 0; j < 5; j++) {
			vh.push_back(new Hexagon( Point(i+d, j * SQRT * 2 + SQRT ), d));
			vh[vh.size()-1].set_style(Line_style(Line_style::solid,4));
			win.attach(vh[vh.size()-1]);
		}

	for (unsigned int i = d+d/2; i < win.x_max(); i = i + d*3)
		for (unsigned int j = 0; j < 5; j++) {
			vh.push_back(new Hexagon( Point(i+d, j * SQRT * 2), d));
			vh[vh.size()-1].set_style(Line_style(Line_style::solid,4));
			vh[vh.size()-1].set_color(Color::red);
			win.attach(vh[vh.size()-1]);
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

