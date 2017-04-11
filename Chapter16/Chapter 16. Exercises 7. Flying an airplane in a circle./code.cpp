/*
 Chapter 16. Exercises 7.
	7. Using the techniques developed in the previous exercises, make an image of an airplane “fly around” in a window. Have
a “Start” and a “Stop” button.

 clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code
*/

#include "code.h"
#include "cmath"
#include <ctime>	/* time_t, struct tm, difftime, time, mktime */

using namespace Graph_lib;
using namespace std;

//------------------------------------------------------------------------------

Point rotation (Point P, int r, int angle)
{
	static const double PI = 3.141592653;
	double x = P.x - r*cos(angle*PI/180);
	double y = P.y - r*sin(angle*PI/180);
	if ( (x-(int)x) >= 0.5) x++;
	if ( (y-(int)y) >= 0.5) y++;
	return Point(x,y);
}

//------------------------------------------------------------------------------
//Drawing airplane
Airplane::Airplane(Point P, int length, int angle)
: l(length)
{
	add(P);
	add(rotation(P,length*0.2,90+angle));
	Point K = rotation(P,length*0.8,270+angle);
	add(K);
	add(rotation(K,length*0.3,325+angle));
	add(rotation(K,length*0.3,215+angle));
	add(K);
	add(P);
	add(rotation(P,length*0.7,330+angle));
	add(rotation(P,length*0.7,210+angle));
}

//------------------------------------------------------------------------------
//Calculating lengths between the points
int length_calc(const Point &A, const Point &B)
{
	double l = sqrt(pow(B.x-A.x,2)+pow(B.y-A.y,2));
	if (l-(int)l >= 0.5 ) l++;
	return l;
}

//------------------------------------------------------------------------------
//Поворот самолёта относительно точки P на угол: angle

void Airplane::turn(Point fulcrum, int angle)
{
	Point P = rotation(fulcrum, length_calc(fulcrum,point(0)), angle);
	Airplane tmp(P, l, angle);

	for (int i=0; i<number_of_points(); i++)
		set_point(i,tmp.point(i));
}

//------------------------------------------------------------------------------

My_window::My_window(Point xy, int w, int h, const string& title)
    :Window(xy,w,h,title),
    quit_button(Point(x_max()-50,0), 50, 25, "Quit", 
[](Address, Address pw) { reference_to<My_window>(pw).quit(); }),
    start_button(Point(w/2-50,h/2-50), 100, 100, "Start fly", 
[](Address, Address pw) { reference_to<My_window>(pw).start(); }),
    stop_button(Point(w/2-50,h/2-50), 100, 100, "Stop fly", 
[](Address, Address pw) { reference_to<My_window>(pw).stop(); }),
	plane(Point(w/4,h/2), 200)
{
    attach(quit_button);
    attach(start_button);
    attach(stop_button);
	attach(plane);

	start_button.show();
	stop_button.hide();
    
	plane.set_fill_color(Color::blue);
	plane.set_style(Line_style(Line_style::solid,3));

//    Fl::add_timeout(1, timer_callback, (void*)this);
}

//------------------------------------------------------------------------------

void My_window::start()
{
	start_button.hide();
	stop_button.show();
	Fl::repeat_timeout(0.01, timer_callback, (void*)this);
}

void My_window::stop()
{
	start_button.show();
	stop_button.hide();
	Fl::remove_timeout(timer_callback, (void*)this);
}

//------------------------------------------------------------------------------

int main()
try {
    My_window win(Point(100,100),1000,900,"Chapter 16.");
	return gui_main();
}
catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Some exception\n";
    return 2;
}

//------------------------------------------------------------------------------
