//
// Заглолвочный файл
//
// c++ -o code code.cpp GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp -lfltk -lfltk_images -std=c++11

#include "std_lib_facilities.h"
#include "GUI/Simple_window.h"    // if we want that "Next" button
#include "GUI/Graph.h"
#include <cmath>

//------------------------------------------------------------------------------

class Immobile_Circle : public Circle {
public:
	Immobile_Circle(Point p, int r): Circle(p,r) { };
	void move(int dx, int dy) { int k = 0; };
};

//------------------------------------------------------------------------------

