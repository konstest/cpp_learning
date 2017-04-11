//
// Заглолвочный файл
//
// clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "std_lib_facilities.h"
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"
#include <list>

//------------------------------------------------------------------------------

struct Lines_window : Window {
    Lines_window(Point xy, int w, int h, const string& title );
private:
    // Data:
    Open_polyline lines;

    // Widgets:
    Button next_button;    // add (next_x,next_y) to lines
    Button quit_button;    // end program
    In_box next_x;
    In_box next_y;
    Out_box xy_out;
    Menu color_menu;
    Menu style_menu;
    Button style_menu_button;
    Button menu_button;


    void change_color(Color c) { lines.set_color(c); } 
    void hide_menu() { color_menu.hide(); menu_button.show(); } 
    void hide_style_menu() { style_menu.hide(); style_menu_button.show(); } 

    // actions invoked by callbacks:
    void red_pressed() { change_color(Color::red); hide_menu(); }
    void blue_pressed() { change_color(Color::blue); hide_menu(); } 
    void black_pressed() { change_color(Color::black); hide_menu(); } 
    void menu_pressed() { menu_button.hide(); color_menu.show(); }
    void next();
    void quit();
	void solid_pressed() { lines.set_style(Line_style::solid); hide_style_menu(); }
	void dash_pressed() { lines.set_style(Line_style::dash); hide_style_menu(); }
	void dot_pressed() { lines.set_style(Line_style::dot); hide_style_menu(); }
    void style_menu_pressed() { style_menu_button.hide(); style_menu.show(); }

    // callback functions:
    static void cb_red(Address, Address);
    static void cb_blue(Address, Address);
    static void cb_black(Address, Address); 
    static void cb_menu(Address, Address);
    static void cb_next(Address, Address);
    static void cb_quit(Address, Address);
    static void cb_style_menu(Address, Address);
    static void cb_solid(Address, Address);
    static void cb_dash(Address, Address);
    static void cb_dot(Address, Address); 

};

//------------------------------------------------------------------------------

