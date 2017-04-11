//
// Заглолвочный файл
//
// clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "std_lib_facilities.h"
#include "GUI/Simple_window.h"    // if we want that "Next" button
#include "GUI/Graph.h"
#include <cmath>

//------------------------------------------------------------------------------

class Striped_closed_Polilyne : public Closed_polyline {
public:
	Striped_closed_Polilyne(): size(1), foot(3) {}
    void draw_lines() const;
    int size;
	int foot;
};

//------------------------------------------------------------------------------

