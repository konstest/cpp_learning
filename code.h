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
    My_window(Point xy, int w, int h, const string& title, const string& );
private:
    // Widgets:
    Button quit_button;		// end program
    Button movable_button; 	// on random location
    Image img;
    void quit();
    void move();

    // callback functions:
    static void cb_quit(Address, Address);
};

//------------------------------------------------------------------------------


