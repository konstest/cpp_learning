//
// Заглолвочный файл
//
// clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "std_lib_facilities.h"
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"
#include <list>


//------------------------------------------------------------------------------
//Расчитывает положение указанной точки повёрнутой на указанный угол и радиус
Point rotation (Point P, int r, int angle);	

//------------------------------------------------------------------------------
// Класс рисующий часовую стрелку (в виде вытянутого треугольника)
struct Arrow : Closed_polyline {
	Arrow (Point P, int length, int width, int angle);
	void turn(int angle);	//turn arrow
private:
	Point center;
	int length;
	int width;
	int angle;	//angle
};

//------------------------------------------------------------------------------

class My_window : public Window {
private:
    Button quit_button;		// end program
    Arrow	second;			// second hand
    Arrow	minute;			// minute hand
    Arrow	hour;			// hour hand
    Text	current_date;	// date & time lable
    Circle	small;			// small circle
    Circle	big;			// big circle
    Vector_ref<Text> digits;// date & time lable

    void quit() { hide(); }	// curious FLTK idiom for delete window
    void turn();			// installation of our arrows to the position of localtime

	//additional_files/fltk_1.1_documentation.pdf page: 127
	static void timer_callback(void *userdata) {
		My_window *o = (My_window*)userdata;
		o->turn();
		o->redraw();
		Fl::repeat_timeout(0.1, timer_callback, userdata);
	}
public:
    My_window(Point xy, int w, int h, const string& title);
};

//------------------------------------------------------------------------------

