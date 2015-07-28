//
// Глава 13. Упражнение 7. Создайте цветную диаграмму RGB (в качестве примера
// смотри http://www.1netcentral.com/rgb-color-chart.html )
// clear && c++ -o code code.cpp GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp -lfltk -lfltk_images -std=c++11 && ./code 

#include "code.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

int main ()
try
{
    Simple_window win(Point(10,10),1300,900,"Chapter 13. Exercise 6:");

	int gcount = 16;
	Vector_ref<Rectangle> vr;
	Vector_ref<Text> tr;
	ostringstream oss;
	for (int i=0; i<gcount; i++)
		for (int j=0; j<gcount; j++) {
			vr.push_back(new Rectangle(Point(i*80,j*40),80,40));
			vr[vr.size()-1].set_fill_color(j*gcount+i);
			win.attach(vr[vr.size()-1]);
			oss << showbase << hex << j*gcount+i;
			tr.push_back(new Text(Point(i*80+20,j*40+25),oss.str()) );
			tr[tr.size()-1].set_font_size(15);
			tr[tr.size()-1].set_color(j*gcount+i-3);
			oss.str("");
			win.attach(tr[tr.size()-1]);
		}
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

