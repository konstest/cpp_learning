/*
 Chapter 15. Exercise 8.
8. Here is a collection of heights in centimeters together with the number of people in a group of that height (rounded to the
nearest 5cm): (170,7), (175,9), (180,23), (185,17), (190,6), (195,1). How would you graph that data? If you can’t think
of anything better, do a bar graph. Remember to provide axes and labels. Place the data in a file and read it from that file.

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
void Bar_graph::add_value(double v, string val_name)
{
	int k = vals.size();
	
	//draw rectangles
	vals.push_back( new Rectangle( Point(orig.x+k*xscale+1,orig.y-v*yscale),
		Point(orig.x+(k+1)*xscale,orig.y-1) ) );
	vals[k].set_color(k);
	vals[k].set_fill_color(k);

	//draw tvals
	ostringstream os;
	os << v;
	tvals.push_back(new Text(Point(orig.x+k*xscale+xscale/20,orig.y-v*yscale-5),
								os.str() ));
	tvals[k].set_color(k);
	tvals[k].set_font_size(xscale/3);

	//draw tvals_name
	tvals_name.push_back(new Text(Point(orig.x+k*xscale+xscale/20,orig.y+xscale/3),
								val_name ));
	tvals_name[k].set_color(k);
	tvals_name[k].set_font_size(xscale/3);
	
	//draw name_graph
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
		tvals_name[i].draw();
	}
	name_graph.draw();

}
	
//------------------------------------------------------------------------------

struct Heights {
    int cents, count;
};

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Heights& d)
// assume format: ( year : young middle old )
{
    char ch1 = 0;
    char ch2 = 0;
    char ch3 = 0;
    Heights dd;

    if (is >> ch1 >> dd.cents >> ch2 >> dd.count >> ch3) {
        if (ch1!= '(' || ch2!=',' || ch3!=')') {
            is.clear(ios_base::failbit);
            return is;
        }
    }
    else
        return is;
    d = dd;
    return is;
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
    const int y_scale = (ylength-ymax/10)/50;	// scaling factor
	const int x_scale = 50;
	
    Axis x(Axis::x,orig, xlength, xlength/x_scale, "one notch == 1");
    x.set_color(Color::red);
    x.label.set_font_size(20);
    x.label.move(xlength/2.3,0);
    win.attach(x);
    Axis y(Axis::y,Point(x_orig, ylength+20), ylength, ylength/y_scale, "1:50");
    win.attach(y);
    y.set_color(Color::red);
    y.label.set_font_size(10);

	Bar_graph gisto(orig,x_scale,y_scale,"Collection of heights");
	gisto.name_graph.set_color(64);
	win.attach(gisto);
	
    string file_name = "values";
    ifstream ifs(file_name.c_str());
    if (!ifs) error("can't open ",file_name);

    Heights d;
	ostringstream os;
    while (ifs>>d) {
    	os << d.cents;
		gisto.add_value(d.count, os.str());
		os.str("123");
    }


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

