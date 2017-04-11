// Заглолвочный файл
//
// clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "std_lib_facilities.h"
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"
#include <list>
#include <FL/Fl_Output.H>

//------------------------------------------------------------------------------
class Graphics_window : public Window {
private:
    Button quit_button;
    Menu functions_menu;
    In_box r_min_box;
    In_box r_max_box;
    In_box x_scale_box;
    In_box y_scale_box;
    Axis x;
    Axis y;
    Vector_ref<Function> funcs;

public:
    Graphics_window(Point, int, int, const string&);
    void quit() { hide(); }
    void f(Fct);
};

//------------------------------------------------------------------------------
