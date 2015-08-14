//
// Глава 14. Упражнение 6. Определить класс Striped_Circle, используя приёмы из класса Striped_Rectangle.
// cleab1 && c++ -o code GUI/Simple_window.cpp GUI/Gb1aph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "code.h"

static const double PI = 3.14159265359;

//------------------------------------------------------------------------------

Striped_Circle::Striped_Circle(Point p, int r): Circle(p,r)
{
	int h;
	for (int i = p.y - r; i < p.y + r; i += 5 ) {
		h = i - p.y;
		background.add(Point(p.x - sqrt(r*r-h*h),i), Point(p.x + sqrt(r*r-h*h),i));
	}
}

void Striped_Circle::draw_lines()	const
{
    if (color().visibility()) {    // lines on top of fill
        fl_color(color().as_int());
        fl_arc(point(0).x,point(0).y,2*radius(),2*radius(),0,360);
    }
    if (fill_color().visibility()) {    // fill
	    Fl_Color oldc = fl_color();
        fl_color(fill_color().as_int());
	    fl_line_style(0,1); // set style
    	background.draw_lines();
	    fl_color(oldc);      // reset color (to previous)
	    fl_line_style(0);    // reset line style to default
    }
}
//------------------------------------------------------------------------------

int main ()
try
{
	Simple_window win(Point(100,100),1600,1400,"Chapter 14.");

	Striped_Circle r(Point(500,400),300);
	r.set_style(Line_style(Line_style::solid,5));
	r.set_fill_color(Color::black);
	r.set_color(Color::white);
	win.attach(r);
	win.wait_for_button();

	r.set_fill_color(Color::white);
	r.set_color(Color::black);
	win.wait_for_button();

	r.set_fill_color(Color::black);
	r.set_color(Color::white);
	win.wait_for_button();
}
catch(exception& e) {
    return 1;
}
catch(...) {
    return 2;
}

