/*
 Chapter 15. Exercise 6-7.
6. Design and implement a bar graph class. Its basic data is a vector<double> holding N values, and each value should
	be represented by a “bar” that is a rectangle where the height represents the value.
7. Elaborate the bar graph class to allow labeling of the graph itself and its individual bars. Allow the use of color.
 clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code
*/

#include "code.h"
#include "cmath"

using namespace std;

//------------------------------------------------------------------------------

Bar_graph::Bar_graph(Point o, int xsc, int ysc, string n)
: orig(o), xscale(xsc), yscale(ysc), name_graph(o,n)
{
	name_graph.set_font_size(xscale/2);
}

//Добавляем элемент(столбец) гистограммы
// y = v * yscale
void Bar_graph::add_value(double v)
{
	int k = vals.size();
	vals.push_back( new Rectangle( Point(orig.x+k*xscale+1,orig.y-v*yscale),
		Point(orig.x+(k+1)*xscale,orig.y-1) ) );
	vals[k].set_color(k);
	vals[k].set_fill_color(k);

	ostringstream os;
	os << v;
	tvals.push_back(new Text(Point(orig.x+k*xscale+xscale/20,orig.y-v*yscale-5),
								os.str() ));
	tvals[k].set_color(k);
	tvals[k].set_font_size(xscale/3);
	
	name_graph.move(xscale/3,0);
	if (name_graph.point(0).y > orig.y-v*yscale-5 ) {
		if (name_graph.point(0).y != orig.y) 
			name_graph.move(0,orig.y-name_graph.point(0).y);	//ставим в изночальное orig.y
		name_graph.move(0,orig.y-orig.y-v*yscale-xscale/2);		//перемещаем с начального orig.y куда задумали
	}
}

void Bar_graph::draw_lines() const
{
	for (int i=0; i<vals.size(); i++) {
		vals[i].draw();
		tvals[i].draw();
	}
	name_graph.draw_lines();
}
	
//------------------------------------------------------------------------------

int main()
try
{
    const int xmax = 600;      	// window size
    const int ymax = 400;

    const int x_orig = 20;		// position of (0,0)
    const int y_orig = ymax-ymax/10; 
    const Point orig(x_orig,y_orig);

    Simple_window win(Point(100,100),xmax,ymax,"exp approximation");
 
    const int xlength = xmax-40;   // make the axis a bit smaller than the window
    const int ylength = ymax-40;
    const int y_scale = ylength-ymax/10;	// scaling factor
	const int x_scale = 50;
	
    Axis x(Axis::x,orig, xlength, xlength/x_scale, "one notch == 1");
    x.set_color(Color::red);
    x.label.set_font_size(20);
    x.label.move(xlength/2.3,0);
    win.attach(x);
    Axis y(Axis::y,Point(x_orig, ylength+20), ylength, ylength/y_scale, "one notch == 1");
    win.attach(y);
    y.set_color(Color::red);
    y.label.set_font_size(10);

	Bar_graph gisto(orig,x_scale,y_scale,"My test graph");
	win.attach(gisto);
	
	gisto.add_value(0.5);
	gisto.add_value(0.3);
	gisto.add_value(0.7);
	gisto.add_value(0.9);
	gisto.add_value(0.1);
	gisto.add_value(0.3);
	gisto.add_value(0.2);
	gisto.add_value(0.4);
	gisto.add_value(0.6);
	gisto.add_value(0.8);

    win.wait_for_button();
}
catch(exception& e) {
    // some error reporting
    cerr << e.what() << endl;
    return 1;
}
catch(...) {
    // some more error reporting
    return 2;
}

//------------------------------------------------------------------------------

