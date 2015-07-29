//
// Заглолвочный файл
//
// c++ -o code code.cpp GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp -lfltk -lfltk_images -std=c++11

#include "std_lib_facilities.h"
#include "GUI/Simple_window.h"    // if we want that "Next" button
#include "GUI/Graph.h"
#include <cmath>

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

