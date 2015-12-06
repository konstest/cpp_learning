/*
 Chapter 16. Exercises 1-2.
	1. Make a My_window that’s a bit like Simple_window except that it has two buttons, next and quit.
	2. Make a window (based on My_window) with a 4-by-4 checkerboard of square buttons. When pressed, a button
performs a simple action, such as printing its coordinates in an output box, or turns a slightly different color (until another
button is pressed).

 clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code
*/

#include "code.h"
#include "cmath"

using namespace Graph_lib;
using namespace std;

//------------------------------------------------------------------------------

My_window::My_window(Point xy, int w, int h, const string& title)
    :Window(xy,w,h,title),
    quit_button(Point(x_max()-70,0), 70, 20, "Quit", cb_quit),
    out(Point(70,0), 70, 20, "output")
{
	attach(out);
    attach(quit_button);
    checkerboard.push_back(new Button(Point(0,20), w/2, h/2-20, "", 
    [](Address, Address pw) { reference_to<My_window>(pw).output(Board::a0); }));
    checkerboard.push_back(new Button(Point(w/2,20), w/2, h/2-20, "", 
    [](Address, Address pw) { reference_to<My_window>(pw).output(Board::a1); }));
    checkerboard.push_back(new Button(Point(0,h/2), w/2, h/2, "", 
    [](Address, Address pw) { reference_to<My_window>(pw).output(Board::b0); }));
    checkerboard.push_back(new Button(Point(w/2,h/2), w/2, h/2, "", 
    [](Address, Address pw) { reference_to<My_window>(pw).output(Board::b1); }));
    for (int i=0; i<checkerboard.size(); i++)
    	attach(checkerboard[i]);
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

void My_window::output(Board b)
{
	ostringstream oss;
    if (b == Board::a0) {
    	oss << "(0,20)";
    	out.put(oss.str());
    }
    if (b == Board::a1) {
    	oss << "(" <<  x_max()/2 << ",20)";
    	out.put(oss.str());
    }
    if (b == Board::b0) {
    	oss << "(0," << y_max()/2 << ")";
    	out.put(oss.str());
    }
    if (b == Board::b1) {
    	oss << "(" << x_max()/2 << "," << y_max()/2 << ")";
    	out.put(oss.str());
    }
    //redraw();
}

//------------------------------------------------------------------------------

int main()
try {
    My_window win(Point(100,100),900,600,"Exercises 1-2.");
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
