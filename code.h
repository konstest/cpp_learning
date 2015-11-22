//
// Заглолвочный файл
//
// clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "std_lib_facilities.h"
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"
#include <list>

//------------------------------------------------------------------------------

class MyFunction : public Shape {
public:
    MyFunction(Fct f, double r1_, double r2_, Point orig_,
        int count_ = 100, double xscale_ = 25, double yscale_ = 25);
    void	reset(Fct f, double r1_, double r2_, Point orig_,
        int count_ = 100, double xscale_ = 25, double yscale_ = 25);
    Text	label;
    void	draw_lines() const;
private:
	void	generate_point(Fct f);
	double	r1;
	double	r2;
	Point	orig;
	int		count;
	double	xscale;
	double	yscale;
	vector<Point> xy;
};

//------------------------------------------------------------------------------

