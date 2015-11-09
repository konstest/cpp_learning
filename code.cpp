/*
 Глава 15.
	Function graphing drill: 1-5.
	Separate Shape for each function to be graphed: 1-9.
 clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code
*/

#include "code.h"
#include "cmath"

//------------------------------------------------------------------------------
double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return cos(x)+slope(x); }

//------------------------------------------------------------------------------
int main ()
try
{		//x_win = x_max()*0.7
    const int xmax = 600;    	// window size
    const int ymax = 600;
    const Point orig(xmax/2,ymax/2);

    const int xlength = 400;    // length of axes
    const int ylength = 400;

    const int xoffset = (xmax-xlength)/2; // distance from left hand side of window to y axis
    const int yoffset = (ymax-ylength)/2;  // distance from bottom of window to x axis

    const double xscale = 20;					// scale of x values
    const double yscale = 20;					// scale of y values 

	Simple_window win(Point((1920-xmax)/2,(1080-ymax)/2),xmax,ymax,"Chapter 15. Exercises.");

    Axis x(Axis::x, Point(xoffset,ymax/2), xlength, xlength/xscale,"1 == 20 pixels");
    x.label.move(-100,0);
    x.label.set_font_size(15);
    x.set_color(Color::red);
	win.attach(x);

    Axis y(Axis::y, Point(xmax/2,ymax-yoffset), ylength, ylength/xscale,"1 == 20 pixels");
    y.label.move(20,0);
    y.label.set_font_size(15);
    y.set_color(Color::red);
	win.attach(y);
	
	const int x_range = -10;
	const int y_range = 11;
	const int points_count = 400;

    Function s1(one, x_range, y_range, orig, points_count, xscale, yscale);
    Text ts(Point(100,ymax/2-40),"one");
    ts.set_font_size(15);
	win.attach(s1);
	win.attach(ts);

    Function s2(slope, x_range, y_range, orig, points_count, xscale, yscale);
    Text ts2(Point(100,ymax/2+ymax/4-20),"x/2");
    ts2.set_font_size(15);
	win.attach(s2);
	win.attach(ts2);

    Function s3(square, x_range, y_range, orig, points_count, xscale, yscale);
    Text ts3(Point(xmax/2-100,20),"x*x");
	ts3.set_font_size(15);
	win.attach(s3);
	win.attach(ts3);

    Function s4(cos, x_range, y_range, orig, points_count, xscale, yscale);
    s4.set_color(Color::blue);
	win.attach(s4);

    Function s5(sloping_cos, x_range, y_range, orig, points_count, xscale, yscale);
    x.label.move(0,10);
    x.notches.set_color(Color::dark_red);
    win.attach(s5);

	win.wait_for_button();
}
catch(exception& e) {
    return 1;
}
catch(...) {
    return 2;
}

