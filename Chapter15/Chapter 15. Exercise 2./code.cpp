/*
 Chapter 15. Exercise 2.
	Define a class Fct that is just like Function except that it stores its constructor arguments. Provide Fct with “reset”
	operations, so that you can use it repeatedly for different ranges, different functions, etc.
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
}

//constructor
MyFunction::MyFunction(Fct f, double r1_, double r2_, Point orig_,
    int count_, double xscale_, double yscale_)
:r1(r1_), r2(r2_), orig(orig_),	count(count_), xscale(xscale_), yscale(yscale_)
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
}

double one(double) { return 1; }

double slope(double x) { return x/2; }

double square(double x) { return x*x; }

double sloping_cos(double x) { return cos(x)+slope(x); }

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

    MyFunction f1(log,0.000001,r_max,orig,200,30,30); // log() logarithm, base e
    win0.attach(f1);
    
    win0.set_label("log, exp, sin and cos");

    const int xlength = xmax-40;   // make the axis a bit smaller than the window
    const int ylength = ymax-40;

    Axis x(Axis::x,Point(20,y_orig), xlength, xlength/x_scale, "one notch == 1");
    Axis y(Axis::y,Point(x_orig, ylength+20), ylength, ylength/y_scale, "one notch == 1");
    win0.attach(x);
    win0.attach(y);
    x.set_color(Color::red);
    y.set_color(Color::red);

    x.label.move(-160,0);
    x.notches.set_color(Color::dark_red);

    win0.wait_for_button();

    f1.reset(sin,   r_min,r_max,orig,200,30,30); // sin()
	f1.set_color(Color::yellow);
    win0.wait_for_button();
	f1.reset(cos,   r_min,r_max,orig,200,30,30); // cos()
	f1.set_color(Color::blue);
    win0.wait_for_button();
	f1.reset(exp,   r_min,r_max,orig,200,30,30); // exp() exponential e^x
	f1.set_color(Color::black);
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
