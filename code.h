//
// Заглолвочный файл
//
// clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "std_lib_facilities.h"
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"
#include <list>

//------------------------------------------------------------------------------
Point rotation (Point P, int r, int angle);
//Расчитывает длинну отрезка между точками
int length_calc(const Point &A, const Point &B);

struct Airplane : Closed_polyline {
	Airplane(Point P, int length, int angle = 0 );
	void turn(Point fulcrum, int angle);	//Поворот самолёта относительно точки P на угол: angle
	int l;
};

class My_window : public Window {
private:
    Button quit_button;		// end program
    Button start_button;
    Button stop_button;
	Airplane plane;

    void quit() { hide(); }	// curious FLTK idiom for delete window
    void start();
    void stop();

	//additional_files/fltk_1.1_documentation.pdf page: 127
	static void timer_callback(void *userdata) {
		static int angle = 1;
		My_window *o = (My_window*)userdata;
		o->plane.turn(Point(o->x_max()/2,o->y_max()/2),angle);
		o->redraw();
		Fl::repeat_timeout(0.01, timer_callback, userdata);
		angle += 1;
	}
public:
    My_window(Point xy, int w, int h, const string& title);
};

//------------------------------------------------------------------------------

