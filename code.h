//
// Заглолвочный файл
//
// clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "std_lib_facilities.h"
#include "GUI/Simple_window.h"    // if we want that "Next" button
#include "GUI/Graph.h"
#include <cmath>

//------------------------------------------------------------------------------

class Octagon : public Shape {
public:
	Octagon(const Point& P, int rr );
    void draw_lines() const;
    int radius() const { return r; }
    Point center() { return point(0); }
    void set_center(const Point& P) { set_point(0,P); }
    void set_radius(int rr) { r = rr; };
private:
    int r;
};

//------------------------------------------------------------------------------

