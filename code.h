//
// Заглолвочный файл
//
// clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "std_lib_facilities.h"
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"

using namespace Graph_lib;

struct Pseudo_window : Simple_window {
    Pseudo_window(Point xy, int w, int h, const string& title );
private:
	Image cross_image;
	Out_box	smetka;
};

