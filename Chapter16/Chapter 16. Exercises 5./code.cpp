/*
 Chapter 16. Exercises 5.
	5. Write a program that draws a shape of your choice and moves it to a new point each time you click “Next.” The new
point should be determined by a coordinate pair read from an input stream.


 clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code
*/

#include "code.h"
#include "cmath"
#include <random>

using namespace Graph_lib;
using namespace std;

//------------------------------------------------------------------------------

My_window::My_window(Point xy, int w, int h, const string& title)
    :Window(xy,w,h,title),
    quit_button(Point(x_max()-70,0), 70, 20, "Quit", 
[](Address, Address pw) { reference_to<My_window>(pw).quit(); }),
    next_button(Point(x_max()-310,0), 70, 20, "Next", 
[](Address, Address pw) { reference_to<My_window>(pw).next(); }),
    items_menu(Point(0,0), 70, 20, Menu::vertical, "Shapes"),
    x(Point(150,0), 50, 20, "X: "),
    y(Point(250,0), 50, 20, "Y: ")
{
    attach(quit_button);
    attach(next_button);
    attach(x);
    attach(y);
    items_menu.attach(new Button(Point(0,0),0,0,"Circle",
    [](Address, Address pw) { reference_to<My_window>(pw).circle_create(); } ));
    items_menu.attach(new Button(Point(0,0),0,0,"Square",
    [](Address, Address pw) { reference_to<My_window>(pw).square_create(); } ));
    items_menu.attach(new Button(Point(0,0),0,0,"Triangle",
    [](Address, Address pw) { reference_to<My_window>(pw).triangle_create();}));
    items_menu.attach(new Button(Point(0,0),0,0,"Hexagon",
    [](Address, Address pw) { reference_to<My_window>(pw).hexagon_create(); }));
    attach(items_menu);
}

//------------------------------------------------------------------------------
//	Create Circle

void My_window::circle_create()
{
    vec.push_back(new Circle(Point(x.get_int()+length,y.get_int()+length),length));
    vec[vec.size()-1].set_color(Color::red);
    attach(vec[vec.size()-1]);
    items_menu.hide();
    redraw();
}

//------------------------------------------------------------------------------
//	Create Square

void My_window::square_create()
{
    vec.push_back(new Rectangle(Point(x.get_int(),y.get_int()),length*2,length*2));
    vec[vec.size()-1].set_color(Color::blue);
    attach(vec[vec.size()-1]);
    items_menu.hide();
    redraw();
}

//------------------------------------------------------------------------------
//	Create Triangle

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

void My_window::triangle_create()
{
	vec.push_back(new Triangle(Point(x.get_int(),y.get_int()),length*2,60));
	vec[vec.size()-1].set_color(Color(Color::yellow));
	vec[vec.size()-1].set_style(Line_style(Line_style::solid,2));
    attach(vec[vec.size()-1]);
    items_menu.hide();
    redraw();
}

//------------------------------------------------------------------------------
//	Create Hexagon
Hexagon::Hexagon(Point cc, int dd) :d(dd)
{
	add(Point(cc.x-dd,cc.y));
	int d2 = dd/2;
	add(Point(cc.x-dd/2,cc.y-sqrt(dd*dd-d2*d2)));
	add(Point(cc.x+dd/2,cc.y-sqrt(dd*dd-d2*d2)));
	add(Point(cc.x+dd,cc.y));
	add(Point(cc.x+dd/2,cc.y+sqrt(dd*dd-d2*d2)));
	add(Point(cc.x-dd/2,cc.y+sqrt(dd*dd-d2*d2)));
}

void Hexagon::draw_lines() const
{
	if (color().visibility()) {
		fl_line(point(number_of_points()-1).x,point(number_of_points()-1).y,
			point(0).x,point(0).y);
		Shape::draw_lines();
	}
}

void My_window::hexagon_create()
{
	vec.push_back(new Hexagon(Point(x.get_int()+length,y.get_int()),length));
	vec[vec.size()-1].set_fill_color(Color(Color::green));
    attach(vec[vec.size()-1]);
    items_menu.hide();
    redraw();
}

//------------------------------------------------------------------------------

void My_window::next()
{
	Point to_xy = Point(x.get_int(),y.get_int());
	Point from_xy = vec[vec.size()-1].point(0);
	vec[vec.size()-1].move(to_xy.x-from_xy.x,to_xy.y-from_xy.y);
    redraw();
}

//------------------------------------------------------------------------------

int main()
try {
    My_window win(Point(100,100),900,600,"Exercises 1-2.");
    return gui_main();
}
catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Some exception\n";
    return 2;
}

//------------------------------------------------------------------------------
