/*
 Chapter 15. Exercise 5.
	“Animate” (as in §15.5) the series 1–1/3+1/5–1/7+1/9–1/11+ . . . . 
	It is known as Leibniz’s series and converges to pi/4.
 clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code
*/

#include "code.h"
#include "cmath"

using namespace std;

//------------------------------------------------------------------------------

double term(double x, int n) { return pow(-1,x)/n; }    // nth term of series

//------------------------------------------------------------------------------

double expN(double x)
{
	if (x == 0) return 0;
    double sum = 1;
    for (int i=3,j=1; j < x; i+=2,j++)
    	sum += term(j,i);
    return sum;
}

//------------------------------------------------------------------------------

int main()
try
{
    const int xmax = 600;      	// window size
    const int ymax = 400;

    const int x_orig = 20;		// position of (0,0)
    const int y_orig = ymax-ymax/10; 
    const Point orig(x_orig,y_orig);

    const int n_iterations = 50;  // The number of iterations

    Simple_window win(Point(100,100),xmax,ymax,"exp approximation");
 
    const int xlength = xmax-40;   // make the axis a bit smaller than the window
    const int ylength = ymax-40;
    const int y_scale = ylength-ymax/10;	// scaling factor
	int x_scale;
	
    Axis y(Axis::y,Point(x_orig, ylength+20), ylength, ylength/y_scale, "one notch == 1");
    win.attach(y);
    y.set_color(Color::red);

	int n = 1;
    while ( n < n_iterations ) {
        ostringstream ss;
        ss << "exp approximation; n==" << n;
        win.set_label(ss.str());
        // get next compution
        x_scale = xlength/n;
        Function e(expN,0,n,orig,n,x_scale,y_scale);
        win.attach(e);
	    Axis x(Axis::x,Point(x_orig,y_orig), xlength, n, "one notch == 1");
 	    x.set_color(Color::red);
        win.attach(x);
        if (!win.wait_for_button())
            break; // User asked to quit
        win.detach(e);
        win.detach(x);
        n++;
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

//------------------------------------------------------------------------------

