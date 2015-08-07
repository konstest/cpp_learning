//
// Глава 13. Упражнение 16-17. Покройте окно узорами в виде маленьких разноцветных шестиугольников.
// clear && c++ -o code code.cpp GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "code.h"

using namespace Graph_lib;

const double PI = 3.141592653589;

//------------------------------------------------------------------------------
unsigned int randint()
{
	return rand() % 256;
}

int rounding(double k)
{
	return ((k - int(k)) < 0.5 ) ? k : k+1;
}

Point rotation (int x, int y, int r, double angle)
{
	return	Point(x - r*cos((angle*PI)/180), y - r*sin((angle*PI)/180));
}

Regular_Polygon::Regular_Polygon(Point P, int dd, int cc) :d(dd), count(cc)
{
	if (cc<3) error("Number of angles less than three.");
	double angle = 360/cc;
	for (unsigned int i = 0; i < 360; i += angle)
		add(rotation ( P.x, P.y, dd, i));
}

void Regular_Polygon::draw_lines() const
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
		fl_line(point(number_of_points()-1).x,point(number_of_points()-1).y,
			point(0).x,point(0).y);
	}
}
//------------------------------------------------------------------------------

int main ()
try
{
    Simple_window win(Point(10,10),2000,2000,"Chapter 13.");
    
	srand (time(NULL));
	
	Vector_ref<Regular_Polygon> VP;
	int r = 50, k;

	Point R, P;

	double a = sqrt(2*r*r - 2*r*r*cos((120*PI)/180));	//находит расстояние до
	a = rounding(a);									//центра соседнего, прилегающего многоугольника
	double yy = 2*sqrt(r*r - (r/2)*r/2);
	yy = rounding(yy);

	while (true) {
		for (R.y = 0; R.y < win.y_max() + yy; R.y = R.y + yy)
		{
			for (R.x = 0; R.x < win.x_max(); R.x = R.x + 3*r)
			{
				k = randint();
				VP.push_back(new Regular_Polygon (R,r,6));
				VP[VP.size()-1].set_fill_color(Color(k));
				VP[VP.size()-1].set_color(Color(k));
				win.attach(VP[VP.size()-1]);
				P.x = R.x + a*cos((30*PI)/180);
				P.y = R.y - a*sin((30*PI)/180);
				k = randint();
				VP.push_back(new Regular_Polygon (P,r,6));
				VP[VP.size()-1].set_fill_color(Color(k));
				VP[VP.size()-1].set_color(Color(k));
				win.attach(VP[VP.size()-1]);
			}
		}
		win.wait_for_button();
	}

}
catch(exception& e) {
    // some error reporting
    return 1;
}
catch(...) {
    // some more error reporting
    return 2;
}

