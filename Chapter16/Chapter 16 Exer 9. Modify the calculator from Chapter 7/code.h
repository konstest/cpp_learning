//
// Заглолвочный файл
//
// clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "std_lib_facilities.h"
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"
#include <list>
#include <FL/Fl_Output.H>

//------------------------------------------------------------------------------

class Calculator_window : public Window {
private:
    Button calculate_button;
    Text equal_sign;
    In_box input_expression;
    Out_box out_rezult;
    void calculate();

public:
    Calculator_window(Point xy, int w, int h, const string& title);
};

//------------------------------------------------------------------------------

