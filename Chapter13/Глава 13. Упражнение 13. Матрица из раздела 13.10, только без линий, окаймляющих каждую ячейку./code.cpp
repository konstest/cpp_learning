//
// Глава 13. Упражнение 13. Матрица из раздела 13.10, только без линий, окаймляющих каждую ячейку.
// c++ -o code code.cpp GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp -lfltk -lfltk_images -std=c++11

#include "code.h"

using namespace Graph_lib;


int main ()
try
{
    Simple_window win(Point(10,10),800,600,"Chapter 13:");

	Vector_ref<Rectangle> vr;
	
	for (unsigned int i = 0; i < 16; i++)
		for (unsigned int j = 0; j < 16; j++)
		{
			vr.push_back(new Rectangle(Point(i*20,j*20),20,20));
			vr[vr.size()-1].set_fill_color(i*16+j);
			vr[vr.size()-1].set_color(i*16+j);
			win.attach(vr[vr.size()-1]);
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

//------------------------------------------------------------------------------
