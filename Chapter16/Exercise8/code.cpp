/*
 Chapter 16. Exercises 8.
	8. Provide a currency converter. Read the conversion rates from a file on startup. Enter an amount in an input window and
provide a way of selecting currencies to convert to and from (e.g., a pair of menus).

 clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code
*/

#include "code.h"
#include "cmath"
#include <ctime>	/* time_t, struct tm, difftime, time, mktime */

using namespace Graph_lib;
using namespace std;

//------------------------------------------------------------------------------

My_window::My_window(Point xy, int w, int h, const string& title, const string& filename)
    :Window(xy,w,h,title),
    quit_button(Point(x_max()-50,0), 50, 25, "Quit", 
[](Address, Address pw) { reference_to<My_window>(pw).quit(); }),
	conversion_button(Point(x_max()-85,60), 80, 25, "Conver...", 
[](Address, Address pw) { reference_to<My_window>(pw).conversion(); }),
    from_box(Point(w/2-100,0), 75, 30, ""),
    to_box(Point(w/2+100,0), 75, 30, ""),
	from_menu(Point(10,40), 40, 30, Menu::horizontal, "menu"),
	to_menu(Point(10,80), 40, 30, Menu::horizontal, "menu"),
	from_cash(Point(w/2-180,22), "from RUB:"),
	to_cash(Point(w/2+20,22), "to RUB:"),
	from_count(1),
	from_cost(1),
	to_count(1),
	to_cost(1)
{
    attach(quit_button);
    attach(conversion_button);
    attach(from_box);
    attach(to_box);
    from_cash.set_font_size(15);
    attach(from_cash);
    to_cash.set_font_size(15);
    attach(to_cash);
    to_box.put("0");

    ifstream ifs(filename.c_str());
    if (!ifs) error("Can't open ",filename);

    //setup RUB button
	from_menu.attach(new Button(Point(0,0),0,0,"RUB",
	[](Address, Address pw) {
		reference_to<My_window>(pw).fRUB();
	}
	));
	to_menu.attach(new Button(Point(0,0),0,0,"RUB",
	[](Address, Address pw) {
		reference_to<My_window>(pw).tRUB();
	}
	));
	//read data from file
    Conversion_rates cr;
    int i=0;
    while (ifs>>cr) {
    	rates.push_back(cr);
    	switch (i) {
    		case 0:
				from_menu.attach(new Button(Point(0,0),0,0,cr.name,
				[](Address, Address pw) {
					reference_to<My_window>(pw).f0();
				}
				));
				to_menu.attach(new Button(Point(0,0),0,0,cr.name,
				[](Address, Address pw) {
					reference_to<My_window>(pw).t0();
				}
				));
				break;
    		case 1:
				from_menu.attach(new Button(Point(0,0),0,0,cr.name,
				[](Address, Address pw) {
					reference_to<My_window>(pw).f1();
				}
				));
				to_menu.attach(new Button(Point(0,0),0,0,cr.name,
				[](Address, Address pw) {
					reference_to<My_window>(pw).t1();
				}
				));
				break;
    		case 2:
				from_menu.attach(new Button(Point(0,0),0,0,cr.name,
				[](Address, Address pw) {
					reference_to<My_window>(pw).f2();
				}
				));
				to_menu.attach(new Button(Point(0,0),0,0,cr.name,
				[](Address, Address pw) {
					reference_to<My_window>(pw).t2();
				}
				));
				break;
    		case 3:
				from_menu.attach(new Button(Point(0,0),0,0,cr.name,
				[](Address, Address pw) {
					reference_to<My_window>(pw).f3();
				}
				));
				to_menu.attach(new Button(Point(0,0),0,0,cr.name,
				[](Address, Address pw) {
					reference_to<My_window>(pw).t3();
				}
				));
				break;
    		case 4:
				from_menu.attach(new Button(Point(0,0),0,0,cr.name,
				[](Address, Address pw) {
					reference_to<My_window>(pw).f4();
				}
				));
				to_menu.attach(new Button(Point(0,0),0,0,cr.name,
				[](Address, Address pw) {
					reference_to<My_window>(pw).t4();
				}
				));
				break;
    		case 5:
				from_menu.attach(new Button(Point(0,0),0,0,cr.name,
				[](Address, Address pw) {
					reference_to<My_window>(pw).f5();
				}
				));
				to_menu.attach(new Button(Point(0,0),0,0,cr.name,
				[](Address, Address pw) {
					reference_to<My_window>(pw).t5();
				}
				));
				break;
    		case 6:
				from_menu.attach(new Button(Point(0,0),0,0,cr.name,
				[](Address, Address pw) {
					reference_to<My_window>(pw).f6();
				}
				));
				to_menu.attach(new Button(Point(0,0),0,0,cr.name,
				[](Address, Address pw) {
					reference_to<My_window>(pw).t6();
				}
				));
				break;
    		case 7:
				from_menu.attach(new Button(Point(0,0),0,0,cr.name,
				[](Address, Address pw) {
					reference_to<My_window>(pw).f7();
				}
				));
				to_menu.attach(new Button(Point(0,0),0,0,cr.name,
				[](Address, Address pw) {
					reference_to<My_window>(pw).t7();
				}
				));
				break;
    		case 8:
				from_menu.attach(new Button(Point(0,0),0,0,cr.name,
				[](Address, Address pw) {
					reference_to<My_window>(pw).f8();
				}
				));
				to_menu.attach(new Button(Point(0,0),0,0,cr.name,
				[](Address, Address pw) {
					reference_to<My_window>(pw).t8();
				}
				));
				break;
    		case 9:
				from_menu.attach(new Button(Point(0,0),0,0,cr.name,
				[](Address, Address pw) {
					reference_to<My_window>(pw).f9();
				}
				));
				to_menu.attach(new Button(Point(0,0),0,0,cr.name,
				[](Address, Address pw) {
					reference_to<My_window>(pw).t9();
				}
				));
				break;
    		case 10:
				from_menu.attach(new Button(Point(0,0),0,0,cr.name,
				[](Address, Address pw) {
					reference_to<My_window>(pw).f10();
				}
				));
				to_menu.attach(new Button(Point(0,0),0,0,cr.name,
				[](Address, Address pw) {
					reference_to<My_window>(pw).t10();
				}
				));
				break;
			default:
				break;
    	}
    	i++;
    }
    attach(from_menu);
    attach(to_menu);
}

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Conversion_rates& d)
{
    char ch = 0;
    Conversion_rates dd;

    int step = 0;
	while ( is.get(ch) || !is.eof() ) {
		
		switch(step) {
			case 0: {
				if (ch == '(')
					step = 1;
				else {
		            is.clear(ios_base::failbit);
		            return is;
					//error("ERROR! Wrong file format values.")
				}
				break;
			}
			case 1: {
				if (ch != ':')
					dd.full_name += ch;
				else
					step = 2;
				break;
			}
			case 2: {
				if (ch != ':') {
					if (isalpha(ch)) {
						is.putback(ch);
						//dd.name += ch;
						is >> dd.name;
					}
				}
				else
					step = 3;
				break;
			}
			case 3: {
				if (isdigit(ch)) {
					is.putback(ch);
					is >> dd.count;
					step = 4;
				}
				else {
					if (isspace(ch)) continue;
		            is.clear(ios_base::failbit);
		            return is;
					//error("ERROR! Wrong file format values.")
				}
				break;
			}
			case 4: {
				if (ch == ':')
					step = 5;
				else {
					if (isspace(ch)) continue;
		            is.clear(ios_base::failbit);
		            return is;
					//error("ERROR! Wrong file format values.")
				}
				break;
			}
			case 5: {
				if (isdigit(ch)) {
					is.putback(ch);
					is >> dd.cost;
					step = 6;
				}
				else {
					if (isspace(ch)) continue;
		            is.clear(ios_base::failbit);
		            return is;
					//error("ERROR! Wrong file format values.")
				}
				break;
			}
			case 6: {
				if (ch == '\n') {
					d = dd;
					return is;
				}
				break;
			}
		}	//endswitch(step)
	}	//endwhile()
	return is;
}

//------------------------------------------------------------------------------
// Processing click on "Conversion" button:
void My_window::conversion()
{
	ostringstream rezult;
	int k = 0;
	if (from_box.get_int() >= 0)
		k = from_box.get_int();
	double cash = 0;
	if (from_cost != to_cost)
		cash = (k*(from_cost/from_count))/to_cost*to_count;
	else
		cash = k;
	rezult << cash;
	to_box.put(rezult.str());
}

//------------------------------------------------------------------------------
//from

void My_window::fRUB()
{
	from_cash.set_label("from RUB:");
	redraw();
	from_count = 1;
	from_cost = 1;
}

void My_window::f0()
{
	from_cash.set_label("from "+rates[0].name+":");
	redraw();
	from_cost = rates[0].cost;
	from_count = rates[0].count;
}

void My_window::f1()
{
	from_cash.set_label("from "+rates[1].name+":");
	redraw();
	from_cost = rates[1].cost;
	from_count = rates[1].count;
}

void My_window::f2()
{
	from_cash.set_label("from "+rates[20].name+":");
	redraw();
	from_cost = rates[2].cost;
	from_count = rates[2].count;
}

void My_window::f3()
{
	from_cash.set_label("from "+rates[3].name+":");
	redraw();
	from_cost = rates[3].cost;
	from_count = rates[3].count;
}

void My_window::f4()
{
	from_cash.set_label("from "+rates[4].name+":");
	redraw();
	from_cost = rates[4].cost;
	from_count = rates[4].count;
}

void My_window::f5()
{
	from_cash.set_label("from "+rates[5].name+":");
	redraw();
	from_cost = rates[5].cost;
	from_count = rates[5].count;
}

void My_window::f6()
{
	from_cash.set_label("from "+rates[6].name+":");
	redraw();
	from_cost = rates[6].cost;
	from_count = rates[6].count;
}

void My_window::f7()
{
	from_cash.set_label("from "+rates[7].name+":");
	redraw();
	from_cost = rates[7].cost;
	from_count = rates[7].count;
}

void My_window::f8()
{
	from_cash.set_label("from "+rates[8].name+":");
	redraw();
	from_cost = rates[8].cost;
	from_count = rates[8].count;
}

void My_window::f9()
{
	from_cash.set_label("from "+rates[9].name+":");
	redraw();
	from_cost = rates[9].cost;
	from_count = rates[9].count;
}

void My_window::f10()
{
	from_cash.set_label("from "+rates[10].name+":");
	redraw();
	from_cost = rates[10].cost;
	from_count = rates[10].count;
}

//to

void My_window::tRUB()
{
	to_cash.set_label("from RUB:");
	redraw();
	to_count = 1;
	to_cost = 1;
}

void My_window::t0()
{
	to_cash.set_label("from "+rates[0].name+":");
	redraw();
	to_count = rates[0].count;
	to_cost = rates[0].cost;
}

void My_window::t1()
{
	to_cash.set_label("from "+rates[1].name+":");
	redraw();
	to_count = rates[1].count;
	to_cost = rates[1].cost;
}

void My_window::t2()
{
	to_cash.set_label("from "+rates[2].name+":");
	redraw();
	to_count = rates[2].count;
	to_cost = rates[2].cost;
}

void My_window::t3()
{
	to_cash.set_label("from "+rates[3].name+":");
	redraw();
	to_count = rates[3].count;
	to_cost = rates[3].cost;
}

void My_window::t4()
{
	to_cash.set_label("from "+rates[4].name+":");
	redraw();
	to_count = rates[4].count;
	to_cost = rates[4].cost;
}

void My_window::t5()
{
	to_cash.set_label("from "+rates[5].name+":");
	redraw();
	to_count = rates[5].count;
	to_cost = rates[5].cost;
}

void My_window::t6()
{
	to_cash.set_label("from "+rates[6].name+":");
	redraw();
	to_count = rates[6].count;
	to_cost = rates[6].cost;
}

void My_window::t7()
{
	to_cash.set_label("from "+rates[7].name+":");
	redraw();
	to_count = rates[7].count;
	to_cost = rates[7].cost;
}

void My_window::t8()
{
	from_cash.set_label("from "+rates[8].name+":");
	redraw();
	from_count = rates[8].count;
	from_cost = rates[8].cost;
}

void My_window::t9()
{
	to_cash.set_label("from "+rates[9].name+":");
	redraw();
	to_count = rates[9].count;
	to_cost = rates[9].cost;
}

void My_window::t10()
{
	to_cash.set_label("from "+rates[10].name+":");
	redraw();
	to_count = rates[10].count;
	to_cost = rates[10].cost;
}

//------------------------------------------------------------------------------

int main()
try {
    My_window win(Point(100,100),600,120,"Chapter 16.","additional_files/Chapter16/values16_8.txt");
	return gui_main();
}
catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Some exception\n";
    return 2;
}

//------------------------------------------------------------------------------
