/*
 Chapter 16. Exercises 10.
	10. Provide a program where you can choose among a set of functions (e.g., sin() and log()), provide parameters for those
functions, and then graph them.

 clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code
*/

#include "code.h"

using namespace Graph_lib;
using namespace std;

//------------------------------------------------------------------------------
//Constructor
Graphics_window::Graphics_window(Point P, int width, int height, const string& lable):
    Window (P,width,height,lable),
    quit_button (Point(x_max()-80,0),80,30,"Quit", [](Address, Address pw) 
            { reference_to<Graphics_window>(pw).quit(); } ),
    functions_menu (Point(0,0),80,30,Menu::vertical,""),
    r_min_box (Point(140,0),100,30,"r_min:"),
    r_max_box (Point(300,0),100,30,"r_max:"),
    x_scale_box (Point(140,35),100,30,"x_scale"),
    y_scale_box (Point(300,35),100,30,"y_scale:"),
    x (Axis::x, Point(width/8,height/2), width*6/8,0,"X"),
    y (Axis::y, Point(width/2,height*7/8), height*6/8,0,"Y")
{
    srand (time(NULL));
    attach(quit_button);
    functions_menu.attach(new Button(Point(0,0),0,0,"Sin()",[](Address, Address pw)
                { reference_to<Graphics_window>(pw).f(sin); } ));
    functions_menu.attach(new Button(Point(0,0),0,0,"Cos()",[](Address, Address pw)
                { reference_to<Graphics_window>(pw).f(cos); } ));
    functions_menu.attach(new Button(Point(0,0),0,0,"Log()",[](Address, Address pw)
                { reference_to<Graphics_window>(pw).f(log); } ));
    functions_menu.attach(new Button(Point(0,0),0,0,"Exp()",[](Address, Address pw)
                { reference_to<Graphics_window>(pw).f(exp); } ));
    functions_menu.attach(new Button(Point(0,0),0,0,"Acos()",[](Address, Address pw)
                { reference_to<Graphics_window>(pw).f(acos); } ));
    functions_menu.attach(new Button(Point(0,0),0,0,"Asin()",[](Address, Address pw)
                { reference_to<Graphics_window>(pw).f(asin); } ));
    functions_menu.attach(new Button(Point(0,0),0,0,"Atan()",[](Address, Address pw)
                { reference_to<Graphics_window>(pw).f(atan); } ));

    attach(functions_menu);
    attach(r_min_box);
    attach(r_max_box);
    attach(x_scale_box);
    attach(y_scale_box);
    x.set_color(Color::red);
    y.set_color(Color::red);
    attach(x);
    attach(y);
}

/////////////////////////////////////////////////////////////////////////////////////
//  Random
 
int rand_int(int min, int max)
{
    return rand() % max + min;
}

/////////////////////////////////////////////////////////////////////////////////////
//  Get string tyoe value
string  In_box::get_string()
{
    Fl_Input& pi = reference_to<Fl_Input>(pw);
    const char* p = pi.value();
    return p;
}

/////////////////////////////////////////////////////////////////////////////////////
//  Converting string to int
int str_to_int(string str)
{
    stringstream ss;
    ss << str;
    int value = 0;
    ss >> value;
    return value;
}

/////////////////////////////////////////////////////////////////////////////////////
//  Draw the selected function
void Graphics_window::f(Fct g)
{
    int r_min = str_to_int(r_min_box.get_string());
    int r_max = str_to_int(r_max_box.get_string());
    int x_scale = str_to_int(x_scale_box.get_string());
    int y_scale = str_to_int(y_scale_box.get_string());
    funcs.push_back(new Function(g,r_min,r_max,Point(x_max()/2,y_max()/2),200,x_scale,y_scale));
    funcs[funcs.size()-1].set_color(rand_int(0,256));
    attach(funcs[funcs.size()-1]);
    redraw();
}

//------------------------------------------------------------------------------
int main()
try {
    Graphics_window win(Point(100,100),800,600,"Chapter 16. The functions drawing.");
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

