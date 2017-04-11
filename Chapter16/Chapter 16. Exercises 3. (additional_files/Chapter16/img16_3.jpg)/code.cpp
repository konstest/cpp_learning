/*
 Chapter 16. Exercises 3.
	Place an Image on top of a Button; move both when the button is pushed. Use this random number generator from
std_lib_facilities.h to pick a new location for the “image button”:


 clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code
*/

#include "code.h"
#include "cmath"
#include <random>

using namespace Graph_lib;
using namespace std;

const int width = 100;		// width of movable button
const int heigth = 100;		// heigth of movable button
//------------------------------------------------------------------------------

My_window::My_window(Point xy, int w, int h, const string& title, const string& file_name)
    :Window(xy,w,h,title),
    quit_button(Point(x_max()-70,0), 70, 20, "Quit", cb_quit),
    movable_button(Point(w/2,h/2), width, heigth, "catch me",
[](Address, Address pw) { reference_to<My_window>(pw).move(); }),
    img(Point(w/2,h/2), file_name, Suffix::jpg)
{
	srand (time(NULL));
    attach(quit_button);
    attach(movable_button);
    attach(img);
}

//------------------------------------------------------------------------------

void My_window::cb_quit(Address, Address pw)    // "the usual"
{
       reference_to<My_window>(pw).quit();
} 

//------------------------------------------------------------------------------

void My_window::quit()
{
    hide();        // curious FLTK idiom for delete window
}

//------------------------------------------------------------------------------

int rand_int(int min, int max)
{
	return rand() % max + min;
}

//------------------------------------------------------------------------------

void My_window::move()
{
	Point P = movable_button.loc;	// remember the current position
	int x = rand_int(-P.x,x_max()-P.x-width);	// calculate a new
	int y = rand_int(-P.y,y_max()-P.y-heigth);	//				location
	movable_button.move(x,y);
	img.move(x,y);
}

//------------------------------------------------------------------------------

int main()
try {
    My_window win(Point(100,100),900,600,"Exercises 1-2.","additional_files/Chapter16/img16_3.jpg");
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
