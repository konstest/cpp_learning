//
// Глава 13. Упражнение 1. Создать класс Arc, рисующий часть эллипса.
//
// c++ -o code code.cpp GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp -lfltk -lfltk_images -std=c++11

#include "std_lib_facilities.h"
#include "GUI/Simple_window.h"    // if we want that "Next" button
#include "GUI/Graph.h"

//------------------------------------------------------------------------------

struct Arc : Shape {
	//p - центрб, w,h - дистанции от центра по ширине и по высоте, a - угол
	Arc (Point p, int w, int h, int a_b, int a_e)
        : w(w), h(h), a_b(a_b), a_e(a_e)
    { 
        add(Point(p.x-w,p.y-h));
    }
	
	void draw_lines()	const;
	
	void set_major(int ww) { w = ww; }
	void set_minor(int hh) { h = hh; }
	void set_angle(int aa_b, int aa_e) { a_b = aa_b; a_e = aa_e; }
	
	int angle_begin()	const { return a_b; }
	int angle_end()		const { return a_e; }
	
	Point	center()	const;

private:
	int w;	//ширина
	int h;	//высота
	int a_b;	//начальный угол
	int a_e;	//конечный угол
};

//------------------------------------------------------------------------------

