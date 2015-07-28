//
// Заглолвочный файл
//
// c++ -o code code.cpp GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp -lfltk -lfltk_images -std=c++11

#include "std_lib_facilities.h"
#include "GUI/Simple_window.h"    // if we want that "Next" button
#include "GUI/Graph.h"
#include <cmath>
#include <istream>

//------------------------------------------------------------------------------

struct Box : Shape {

	Box (Point p, int w, int h, int a_w, int a_h, const string& text, Font f, int font_size)
		: w(w), h(h), a_w(a_w), a_h(a_h), lable(text), fnt(f), fnz(font_size)
	{
        add(Point(p.x,p.y));
	}

	void draw_lines()	const;

	void set_width(int ww) { w = ww; }
	void set_height(int hh) { h = hh; }
	void set_major(int ww) { a_w = ww; }
	void set_minor(int hh) { a_h = hh; }
	void set_text(string str) { lable = str; }

	int width()		const { return w; }
	int height()	const { return h; }
private:
	int w;			//ширина прямоуголька
	int h;			//высота прямоуголька
	int a_w;		//ширина дуги
	int a_h;		//высота дуги
	Font fnt;		//font
	int fnz;		//font size
	string lable;	//строка 
};

//------------------------------------------------------------------------------

struct Arrow : Shape {

	Arrow (Point p1, Point p2);
	Arrow (Point p1, Point p2, int r1, int r2): r1(r1), r2(r2)	{ add(p1); add(p2); }

	void draw_lines()	const;	//изменяем поведение

private:
	int r1;	//width 1
	int r2;	//width 2
};

//------------------------------------------------------------------------------

