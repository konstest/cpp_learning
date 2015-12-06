//
// Заглолвочный файл
//
// clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "std_lib_facilities.h"
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"
#include <list>

//------------------------------------------------------------------------------

struct My_window : Window {
    My_window(Point xy, int w, int h, const string& title );
private:
    enum Board { a0, a1, b0, b1 };
 
    // Widgets:
    Out_box	out;
    Button quit_button;    // end program
	Vector_ref<Button> checkerboard;

    void output(Board);
    void quit();

    // callback functions:
    static void cb_quit(Address, Address);
};

//------------------------------------------------------------------------------

