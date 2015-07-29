//
// Заглолвочный файл
//
// c++ -o code code.cpp GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp -lfltk -lfltk_images -std=c++11

#include "std_lib_facilities.h"
#include "GUI/Simple_window.h"    // if we want that "Next" button
#include "GUI/Graph.h"
#include <cmath>

//------------------------------------------------------------------------------

struct Regular_Polygon : Shape {
	Regular_Polygon (Point P, int dd, int cc);
	void draw_lines() const;
private:
	int d;	//width from center to point
	int count;	//number of angles
};
//------------------------------------------------------------------------------

