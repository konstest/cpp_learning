//
// Глава 13. Задание с 1 по 5. Bug: при перемещении фотография не отображается 
//	над другими объектами типа: Rectangle и Image.
// c++ -o code code.cpp GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp -lfltk -lfltk_images -std=c++11

#include "GUI/Simple_window.h"    // if we want that "Next" button
#include "GUI/Graph.h"
#include "std_lib_facilities.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

int main ()
try
{
	//Task #1
	int size=800;
    Simple_window win(Point(100,100),size,1000,"My window");
    
    //#2
    Lines grid;
    int x_size=size, y_size=size;
    for (int i=0;i<x_size;i+=100)
    	grid.add(Point(i,0),Point(i,y_size));
    for (int i=0;i<=y_size;i+=100)
    	grid.add(Point(0,i),Point(x_size,i));
	win.attach(grid);
	
	//#3
	Vector_ref<Rectangle> R;
    for (int i=0;i<size;i+=100) {
    	R.push_back(new Rectangle(Point(i,i),100,100));
    	R[R.size()-1].set_fill_color(Color::red);
    	win.attach(R[R.size()-1]);
    }

	Image I1(Point(200,0),"1C_logo.jpg");
	Image I2(Point(500,0),"1C_logo.jpg");
	Image I3(Point(500,300),"1C_logo.jpg");
	win.attach(I1);
	win.attach(I2);
	win.attach(I3);
	
	Image my_docha(Point(0,700),"positive.jpg");
	win.attach(my_docha);
	win.put_on_top(my_docha);
	for (int y=100; y<size; y+=100) {
		for (int x=100; x<size; x+=100) {
		    win.wait_for_button();
			my_docha.move(100,0);
		}
		my_docha.move(-800,-100);
	}
	
    win.wait_for_button();               // Display!
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
