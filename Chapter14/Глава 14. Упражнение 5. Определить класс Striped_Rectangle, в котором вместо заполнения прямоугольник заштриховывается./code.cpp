//
// Глава 14. Упражнение 5. Определить класс Striped_Rectangle, в котором вместо
// заполнения прямоугольник заштриховывается.
// cleab1 && c++ -o code GUI/Simple_window.cpp GUI/Gb1aph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "code.h"

//------------------------------------------------------------------------------
Striped_Rectangle::Striped_Rectangle(Point p, int w, int h): Rectangle(p,w,h)
{
	for (int i = point(0).y + 3; i < point(0).y + height(); i += 3 )
		background.add(Point(point(0).x,i),Point(point(0).x + width(),i));
}

void Striped_Rectangle::draw_lines()	const
{
    if (color().visibility()) {    // lines on top of fill
        fl_color(color().as_int());
        fl_rect(point(0).x,point(0).y,width(),height());
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

	Striped_Rectangle r(Point(200,200),500,300);
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

