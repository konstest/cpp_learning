/*
 Глава 14. Упражнение 10.
		Определите класс Pseudo_window, напоминающий класс window. 
 Постарайтесь не прилагать героических усилий. Он должен рисовать закруглённые 
 углы, сметки и управляющие пиктограммы. Возможно, вы сможете добавить какое-либо 
 фиктивное содержание, например изображение. На самом деле с этим изображением 
 ниего не надо делать. Допускается (и даже рекомендуется), чтобы оно появилось 
 в объекте класса Simple_window.
 clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code
*/

#include "code.h"

static const double PI = 3.14159265359;

//------------------------------------------------------------------------------
Pseudo_window::Pseudo_window(Point xy, int w, int h, const string& title ) :
	Simple_window(xy,w,h,title),
    cross_image(Point(x_max()-70,0),"additional_files/Chapter14/cross.jpg"),
    smetka(Point(10,y_max()/2), w-20, h/2-10, "")
{
	attach(cross_image);
	attach(smetka);
	box(FL_ROUNDED_BOX);
	border(0);
}

//------------------------------------------------------------------------------

int main ()
try
{
	int w = 640;
	int h = 480;
	Pseudo_window win(Point((x_max() - w)/2,(y_max() - h)/2),w,h,"Chapter 14. Pseudo_window.");

	Simple_window &Simple_W = win;
	
	Simple_W.wait_for_button();
}
catch(exception& e) {
    return 1;
}
catch(...) {
    return 2;
}

