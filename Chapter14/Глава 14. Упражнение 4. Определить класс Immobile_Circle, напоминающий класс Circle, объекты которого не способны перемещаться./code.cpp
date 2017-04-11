//
// Глава 14. Упражнение 4. Определить класс Immobile_Circle, напоминающий класс Circle,
// объекты которого не способны перемещаться.
// cleab1 && c++ -o code GUI/Simple_window.cpp GUI/Gb1aph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "code.h"

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

int main ()
try
{
	Simple_window win(Point(100,100),1600,1400,"Chapter 14.");

	Immobile_Circle ic(Point(500,500),200);
	ic.set_style(Line_style(Line_style::solid,4));
	ic.set_color(Color::red);
	win.attach(ic);
	win.wait_for_button();

	ic.move(50,50);
	win.wait_for_button();
	ic.move(50,-50);
	win.wait_for_button();
	ic.move(-50,-50);
	win.wait_for_button();
}
catch(exception& e) {
    return 1;
}
catch(...) {
    return 2;
}

