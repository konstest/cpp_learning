/*
 Chapter 16. Drill.
1. Make a completely new project with linker settings for FLTK (as described in Appendix D).
2. Using the facilities of Graph_lib, type in the line-drawing program from §16.5 and get it to run.
3. Modify the program to use a pop-up menu as described in §16.7 and get it to run.
4. Modify the program to have a second menu for choosing line styles and get it to run.

 clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code
*/

#include "code.h"
#include "cmath"

using namespace Graph_lib;
using namespace std;

//------------------------------------------------------------------------------

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window(xy,w,h,title),
    color_menu(Point(x_max()-70,30),70,20,Menu::vertical,"color"),
    style_menu(Point(0,30),70,20,Menu::vertical,"style"),
    menu_button(Point(x_max()-80,30), 80, 20, "color menu", cb_menu),
    style_menu_button(Point(0,30), 80, 20, "style menu", cb_style_menu),
    next_button(Point(x_max()-150,0), 70, 20, "Next point", cb_next),
    quit_button(Point(x_max()-70,0), 70, 20, "Quit", cb_quit),
    next_x(Point(x_max()-310,0), 50, 20, "next x:"),
    next_y(Point(x_max()-210,0), 50, 20, "next y:"),
    xy_out(Point(100,0), 100, 20, "current (x,y):")
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    xy_out.put("no point");
    color_menu.attach(new Button(Point(0,0),0,0,"red",cb_red));
    color_menu.attach(new Button(Point(0,0),0,0,"blue",cb_blue));
    color_menu.attach(new Button(Point(0,0),0,0,"black",cb_black));
    attach(color_menu);
    color_menu.hide();
    attach(menu_button);
    style_menu.attach(new Button(Point(0,0),0,0,"solid",cb_solid));
    style_menu.attach(new Button(Point(0,0),0,0,"dash",cb_dash));
    style_menu.attach(new Button(Point(0,0),0,0,"dot",cb_dot));
    attach(style_menu);
    style_menu.hide();
    attach(style_menu_button);
    attach(lines);
}

//------------------------------------------------------------------------------

void Lines_window::cb_quit(Address, Address pw)    // "the usual"
{  
       reference_to<Lines_window>(pw).quit();
} 

//------------------------------------------------------------------------------

void Lines_window::quit()
{
    hide();        // curious FLTK idiom for delete window
}

//------------------------------------------------------------------------------

void Lines_window::cb_next(Address, Address pw)     // "the usual"
{  
       reference_to<Lines_window>(pw).next();
} 

//------------------------------------------------------------------------------

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point(x,y));

    // update current position readout:
    stringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

      redraw();
}

//------------------------------------------------------------------------------

void Lines_window::cb_red(Address, Address pw)      // "the usual"
{  
    reference_to<Lines_window>(pw).red_pressed();
} 

//------------------------------------------------------------------------------

void Lines_window::cb_blue(Address, Address pw)     // "the usual"
{  
    reference_to<Lines_window>(pw).blue_pressed();
} 

//------------------------------------------------------------------------------

void Lines_window::cb_black(Address, Address pw)    // "the usual"
{  
    reference_to<Lines_window>(pw).black_pressed();
} 

//------------------------------------------------------------------------------

void Lines_window::cb_menu(Address, Address pw)     // "the usual"
{  
    reference_to<Lines_window>(pw).menu_pressed();
} 

//------------------------------------------------------------------------------

void Lines_window::cb_solid(Address, Address pw)     // "the usual"
{  
    reference_to<Lines_window>(pw).solid_pressed();
} 

//------------------------------------------------------------------------------

void Lines_window::cb_dash(Address, Address pw)     // "the usual"
{  
    reference_to<Lines_window>(pw).dash_pressed();
} 

//------------------------------------------------------------------------------

void Lines_window::cb_dot(Address, Address pw)     // "the usual"
{  
    reference_to<Lines_window>(pw).dot_pressed();
} 

//------------------------------------------------------------------------------

void Lines_window::cb_style_menu(Address, Address pw)     // "the usual"
{  
    reference_to<Lines_window>(pw).style_menu_pressed();
} 

//------------------------------------------------------------------------------

int main()
try {
    Lines_window win(Point(100,100),600,400,"lines");
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
