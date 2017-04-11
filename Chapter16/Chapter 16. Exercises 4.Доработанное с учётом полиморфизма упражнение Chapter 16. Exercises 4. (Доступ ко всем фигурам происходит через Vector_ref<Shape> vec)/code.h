//
// Заглолвочный файл
//
// clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "std_lib_facilities.h"
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"
#include <list>

//------------------------------------------------------------------------------
//from 'svn update -r 97'
struct Triangle : Shape {
	Triangle(Point P, int ww, int angle);
	void draw_lines() const;
private:
	int w;		//side length
	int angle;	//angle
};

//from 'svn update -r 89'
struct Hexagon : Shape {
	Hexagon (Point cc, int dd);
	void set_size(int dd) { d = dd; }
	void draw_lines() const;
private:
	int d;	//width from center to point
};

//------------------------------------------------------------------------------

struct My_window : Window {
    My_window(Point xy, int w, int h, const string& title);
private:
    // Widgets:
    Button quit_button;		// end program
    Menu items_menu; 		// menu for create a shapes of SHAPE class
    In_box x;				// x, coordinates for shapes
    In_box y;				// y
    Vector_ref<Shape> vec;
    
    void quit() { hide(); }	// curious FLTK idiom for delete window

    // menu functions:
    void circle_create();
    void square_create();
    void triangle_create();
    void hexagon_create();

    const int length = 100;
};

//------------------------------------------------------------------------------


