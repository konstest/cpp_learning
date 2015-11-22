/*
 Chapter 15. Exercise 4.
	Graph a sine (sin()), a cosine (cos()), the sum of those (sin(x)+cos(x)), and the sum of the squares of those
	(sin(x)*sin(x)+cos(x)*cos(x)) on a single graph. Do provide axes and labels.
 clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code
*/

#include "code.h"
#include "cmath"

//------------------------------------------------------------------------------
//Создаёт точки в соответствии с установленными параметрами 
void MyFunction::generate_point(Fct f)
{
    if (r2-r1<=0) error("bad graphing range");
    if (count <=0) error("non-positive graphing count");
	double r = r1;
	double dist = (r2 - r1)/count;
	for (; r < r2; r += dist )
		xy.push_back(Point(orig.x+r*xscale,orig.y-f(r)*yscale));
	label.move(xy[xy.size()/10].x+10,xy[xy.size()/10].y+10);
}

//constructor
MyFunction::MyFunction(Fct f, double r1_, double r2_, Point orig_,
    int count_, double xscale_, double yscale_)
:r1(r1_), r2(r2_), orig(orig_),	count(count_), xscale(xscale_), yscale(yscale_),
label(Point(0,0),"")
{
	generate_point(f);
}

//Переустанавливает параметры класса и пересчитывает точки
void MyFunction::reset(Fct f, double r1_, double r2_, Point orig_,
    int count_, double xscale_, double yscale_)
{
	r1 = r1_; r2 = r2_; xscale = xscale_; yscale = yscale_;
	orig = orig_; count = count_;
	xy.erase(xy.begin(),xy.end());
	generate_point(f);
}

//Рисуем
void MyFunction::draw_lines() const
{
	for (int i=1; i<xy.size(); i++)
		fl_line(xy[i-1].x,xy[i-1].y,xy[i].x,xy[i].y);
	label.draw_lines();
}

double sc(double x) { return cos(x)+sin(x); }
double sc_square(double x) { return cos(x)*cos(x)+sin(x)*sin(x); }

//------------------------------------------------------------------------------

int main()
try
{
    const int xmax = 600;      // window size
    const int ymax = 400;

    const int x_orig = xmax/2; // position of (0,0) is center of window
    const int y_orig = ymax/2; 
    const Point orig(x_orig,y_orig);

    const int r_min = -10;     // range [-10:11) 
    const int r_max = 11;

    const int n_points = 400;  // number of points used in range

    const int x_scale = 30;    // scaling factors
    const int y_scale = 30;

    Simple_window win0(Point(100,100),xmax,ymax,"Function graphing");
    
    win0.set_label("sin, cos, sin+cos, sin^2+cos^2");

    const int xlength = xmax-40;   // make the axis a bit smaller than the window
    const int ylength = ymax-40;

    Axis x(Axis::x,Point(20,y_orig), xlength, xlength/x_scale, "one notch == 1");
    Axis y(Axis::y,Point(x_orig, ylength+20), ylength, ylength/y_scale, "one notch == 1");
    win0.attach(x);
    win0.attach(y);
    x.set_color(Color::red);
    y.set_color(Color::red);

    x.label.move(-160,0);
    x.label.set_font_size(10);
    y.label.set_font_size(10);
    x.notches.set_color(Color::dark_red);

	const int count = 200;
    MyFunction f1(sin,   r_min,r_max,orig,count,x_scale,y_scale); // sin()
	f1.set_color(Color::yellow);
	f1.label.set_font_size(15);
	f1.label.set_label("Cos(x)");
    win0.attach(f1);

    MyFunction f2(cos,   r_min,r_max,orig,count,x_scale,y_scale); // sin()
	f2.set_color(Color::green);
	f2.label.set_font_size(15);
	f2.label.set_label("Sin(x)");
    win0.attach(f2);

    MyFunction f3(sc,   r_min,r_max,orig,count,x_scale,y_scale);
	f3.set_color(Color::magenta);
	f3.label.set_font_size(15);
	f3.label.set_label("Cos(x)+Sin(x)");
	f3.label.move(110,20);
    win0.attach(f3);

    MyFunction f4(sc_square,   r_min,r_max,orig,count,x_scale,y_scale);
	f4.set_color(Color::cyan);
	f4.label.set_font_size(15);
	f4.label.set_label("Cos(x)*Cos(x)+Sin(x)*Sin(x)");
	f4.label.move(0,-20);
    win0.attach(f4);

    win0.wait_for_button();
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
