//
// Заглолвочный файл
//
// clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "std_lib_facilities.h"
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"
#include <list>

//------------------------------------------------------------------------------

class Bar_graph : public Shape {
public:
	Bar_graph(Point o, int xsc, int ysc, string n);
	void add_value(double v);
	void draw_lines() const;
	Text name_graph;	//в public специально, для доступа из вне
private:
	Point orig;
	int xscale;
	int yscale;
	Vector_ref <Text> tvals;		//drawing vals
	Vector_ref <Rectangle> vals;	//spcial for set_OPTIONS**
};
//------------------------------------------------------------------------------

