//
// Заглолвочный файл
//
// clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "std_lib_facilities.h"
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"
#include <list>

//------------------------------------------------------------------------------

class Conversion_rates {
	public:
	string	full_name;
	string	name;
	int		count;
	double	cost;
};

istream& operator>>(istream&, Conversion_rates& );

class My_window : public Window {
private:
    Button quit_button;		// end program
    Button conversion_button;		// calculate cash
    In_box from_box;
    Out_box to_box;
    Text from_cash;
    Text to_cash;
	int		from_count;
	double	from_cost;
	int		to_count;
	double	to_cost;
    vector<Conversion_rates> rates;
    Menu from_menu;
    Menu to_menu;

    void quit() { hide(); }	// curious FLTK idiom for delete window
    void conversion();

    void fRUB();
    void f0();
    void f1();
    void f2();
    void f3();
    void f4();
    void f5();
    void f6();
    void f7();
    void f8();
    void f9();
    void f10();

    void tRUB();
    void t0();
    void t1();
    void t2();
    void t3();
    void t4();
    void t5();
    void t6();
    void t7();
    void t8();
    void t9();
    void t10();

public:
    My_window(Point xy, int w, int h, const string& title, const string& filename);
};

//------------------------------------------------------------------------------

