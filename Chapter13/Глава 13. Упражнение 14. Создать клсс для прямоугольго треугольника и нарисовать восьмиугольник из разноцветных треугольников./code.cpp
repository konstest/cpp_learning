//
// Глава 13. Упражнение 14. Создать клсс для прямоугольго треугольника и нарисовать восьмиугольник из разноцветных треугольников.
// c++ -o code code.cpp GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp -lfltk -lfltk_images -std=c++11

#include "code.h"

using namespace Graph_lib;

const double PI = 3.141592653;

Point rotation (int x, int y, int r, int angle)
{
	return Point(x - r*cos(angle*PI/180),y - r*sin(angle*PI/180));
}

Triangle::Triangle(Point P0, int ww, int aa): w(ww), angle(aa)
{
	add(P0);
	add(rotation(point(0).x,point(0).y,w,angle));
	add(rotation(point(0).x,point(0).y,w,angle+60));
}

void Triangle::draw_lines() const
{
	if (fill_color().visibility()) {
        fl_color(fill_color().as_int());
        fl_begin_complex_polygon();
        for(int i=0; i<number_of_points(); ++i){
            fl_vertex(point(i).x, point(i).y);
        }
        fl_end_complex_polygon();
        fl_color(color().as_int());    // reset color
    }
	if (color().visibility()) {
		Shape::draw_lines();
		fl_line(point(number_of_points()-1).x,point(number_of_points()-1).y,point(0).x,point(0).y);
	}
}

int main ()
try
{
    Simple_window win(Point(10,10),800,600,"Chapter 13:");

	int length = 150;
	Vector_ref<Triangle> VT;

	VT.push_back(new Triangle(Point(200,200),length,0));
	VT[VT.size()-1].set_fill_color(Color(Color::red));
	VT[VT.size()-1].set_style(Line_style(Line_style::solid,3));
	win.attach(VT[VT.size()-1]);
	VT.push_back(new Triangle(Point(200,200),length,60));
	VT[VT.size()-1].set_fill_color(Color(7));
	VT[VT.size()-1].set_style(Line_style(Line_style::solid,3));
	win.attach(VT[VT.size()-1]);
	VT.push_back(new Triangle(Point(200,200),length,120));
	VT[VT.size()-1].set_fill_color(Color(8));
	VT[VT.size()-1].set_style(Line_style(Line_style::solid,3));
	win.attach(VT[VT.size()-1]);
	VT.push_back(new Triangle(Point(200,200),length,180));
	VT[VT.size()-1].set_fill_color(Color(2));
	VT[VT.size()-1].set_style(Line_style(Line_style::solid,3));
	win.attach(VT[VT.size()-1]);

	VT.push_back(new Triangle(Point(350,200),length,120));
	VT[VT.size()-1].set_fill_color(Color(3));
	VT[VT.size()-1].set_style(Line_style(Line_style::solid,3));
	win.attach(VT[VT.size()-1]);
	VT.push_back(new Triangle(Point(350,200),length,180));
	VT[VT.size()-1].set_fill_color(Color(4));
	VT[VT.size()-1].set_style(Line_style(Line_style::solid,3));
	win.attach(VT[VT.size()-1]);
	VT.push_back(new Triangle(Point(350,200),length,240));
	VT[VT.size()-1].set_fill_color(Color(5));
	VT[VT.size()-1].set_style(Line_style(Line_style::solid,3));
	win.attach(VT[VT.size()-1]);
	VT.push_back(new Triangle(Point(200-150*cos(240*PI/180),200-150*sin(240*PI/180)),length,180));
	VT[VT.size()-1].set_fill_color(Color(6));
	VT[VT.size()-1].set_style(Line_style(Line_style::solid,3));
	win.attach(VT[VT.size()-1]);

    win.wait_for_button();
}
catch(exception& e) {
    // some error reporting
    return 1;
}
catch(...) {
    // some more error reporting
    return 2;
}

//------------------------------------------------------------------------------

