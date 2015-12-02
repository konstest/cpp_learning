/*
 Chapter 15. Exercise 9.
9. Find another data set of Data_array (an inch is 2.54cm) and graph them with your program from the previous exercise. For
example, search the web for “height distribution” or “height of people in the United States” and ignore a lot of rubbish or
ask your friends for their Data_array. Ideally, you don’t have to change anything for the new data set. Calculating the scaling
from the data is a key idea. Reading in labels from input also helps minimize changes when you want to reuse code.

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

struct Data_array {
    string label;
    double value;
};

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Data_array& d)
// assume format: ( year : young middle old )
{
    char ch1 = 0;
    char ch2 = 0;
    char ch3 = 0;
    Data_array dd;

    if (is >> ch1 >> dd.label >> ch2 >> dd.value >> ch3) {
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
    const int xmax = 1000;      	// window size
    const int ymax = 600;

    const int x_orig = 20;		// position of (0,0)
    const int y_orig = ymax-ymax/10; 
    const Point orig(x_orig,y_orig);

    Simple_window win(Point(100,100),xmax,ymax,"exp approximation");
 
    const int xlength = xmax-40;   // make the axis a bit smaller than the window
    const int ylength = ymax-40;

    string file_name = "values.txt";
/*
(Qatar , 15.2)
(Obedinennye_Arabskie_Emiraty , 12.3)
(Bahrain , 11.1)
(South_Sudan , 5.3)
(Liberia , 4.5)
(Kuwait , 3.8)
(Singapore , 3.5)
(Niger , 3.5)
(Uganda , 3.2)
(Eritrea , 3.2)
(Yemen , 3.1)
(Mali , 3.1)
(Benin , 3.0)
(Malawi , 3.0)
(Burkina_Faso , 3.0)
(Jordan , 2.9)
(Iraq , 2.9)
(Angola , 2.9)
(Madagascar , 2.9)
(Tanzania , 2.9)
(Rwanda , 2.9)
(Burundi , 2.9)
(Ekvatorialnaya_Gvineya , 2.8)
(Gambia , 2.8)
(Demokraticheskaya_Respublika_Kongo , 2.8)
(Saudovskaya_Araviya , 2.7)
(Oman , 2.7)
(Congo , 2.7)
(Solomonovy_Ostrova , 2.7)
*/
    ifstream ifs(file_name.c_str());
    if (!ifs) error("can't open ",file_name);

	//Calculating the scaling factor
    Data_array d;
	vector<Data_array> v;
	double max = 0;	//ищем максимальное значение для расчёта коэффициента масштабирования
    while (ifs>>d) {
    	v.push_back(d);
    	if (d.value > max) max = d.value;
    }

	int k;
	if (v.size() == 0 )
		k = 1;
	else
		k = v.size();
	int x_scale = xlength/k;
    int y_scale = ylength/(max + max*0.1);	// scaling factor

    Axis x(Axis::x, orig, xlength, x_scale, "one notch == 1");
    x.set_color(Color::red);
    x.label.set_font_size(20);
    x.label.move(xlength/2.3,0);
    win.attach(x);

    Axis y(Axis::y,Point(x_orig, ylength+20), ylength, y_scale, "X");
    win.attach(y);
    y.set_color(Color::red);
    y.label.set_font_size(10);

	Bar_graph gisto(orig,x_scale,y_scale,"Population Growth Rate");
	gisto.name_graph.set_color(64);
	win.attach(gisto);

    for (int i=0; i<v.size(); i++)
		gisto.add_value(v[i].value, v[i].label);

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

