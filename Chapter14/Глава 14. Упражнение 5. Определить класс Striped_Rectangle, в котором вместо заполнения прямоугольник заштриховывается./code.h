//
// Заглолвочный файл
//
// c++ -o code code.cpp GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp -lfltk -lfltk_images -std=c++11

#include "std_lib_facilities.h"
#include "GUI/Simple_window.h"    // if we want that "Next" button
#include "GUI/Graph.h"
#include <cmath>

//------------------------------------------------------------------------------

class Striped_Rectangle : public Rectangle {
public:
	Striped_Rectangle(Point p, int w, int h);
	void draw_lines()	const;
private:
	Lines	background;
};

//------------------------------------------------------------------------------

