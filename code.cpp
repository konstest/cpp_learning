//
// Глава 14. Упражнение 8. Определить класс Octagon, реализующий правильный восьмиугольник. Напишите
//тестовую программу, выполняющую все его функции-члены (определённые вами или унаследованные от класса Shape).
//
// clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "code.h"

static const double PI = 3.14159265359;

//------------------------------------------------------------------------------

unsigned int randint(int arg)
{
	return rand() % arg;
}

int rounding(double val)
{
	return ( (val - (int)val) >= 0.5 ) ? val+1 : val;
}


Point rotation(const Point& P, int angle, int r)
{
	double x = P.x - r*cos(angle*(PI/180));
	double y = P.y - r*sin(angle*(PI/180));
	return Point(rounding(x),rounding(y));
}

Octagon::Octagon(const Point& P, int rr ): r(rr)
{
	add(P);
}

void Octagon::draw_lines() const
{
	Point P1, P2;
	vector<Point> tochki;
    if (color().visibility()) {
		for (int i=0; i<8; i++) {
			P1 = rotation(point(0),i*45,r);
			P2 = rotation(point(0),(i+1)*45,r);
			tochki.push_back(P1);
			tochki.push_back(P2);
			fl_line(P1.x,P1.y,P2.x,P2.y);
		}
	}
    if (fill_color().visibility()) {
        fl_color(fill_color().as_int());
        fl_begin_complex_polygon();
        for(int i=0; i<tochki.size(); ++i){
            fl_vertex(tochki[i].x, tochki[i].y);
        }
        fl_end_complex_polygon();
        fl_color(color().as_int());    // reset color
    }
}

//------------------------------------------------------------------------------

int main ()
try
{
	Simple_window win(Point(10,10),1800,1000,"Chapter 14.");

	srand (time(NULL));

	Octagon Oct(Point(300,300),100);
	ostringstream oss;
	Point P = Oct.center();
	oss << P.x << "," << P.y;
	Text lable(Point(P.x-35,P.y),oss.str());
	lable.set_font_size(20);
	win.attach(Oct);
	win.attach(lable);
	win.wait_for_button();
	lable.set_label("");
	Oct.set_center(Point(600,400));
	win.wait_for_button();
	Oct.set_radius(175);
	win.wait_for_button();
	Oct.set_color(Color(Color::blue));
	win.wait_for_button();
	Oct.set_style(Line_style(Line_style::dot,7));
	win.wait_for_button();
	Oct.set_fill_color(Color(Color::red));
	//the end...
	win.wait_for_button();
}
catch(exception& e) {
    return 1;
}
catch(...) {
    return 2;
}

