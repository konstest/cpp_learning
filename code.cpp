//
// Глава 14. Упражнение 2 - 3.
// cleab1 && c++ -o code GUI/Simple_window.cpp GUI/Gb1aph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "code.h"

//------------------------------------------------------------------------------
class Abstract {
public:
	virtual void inc(int ii) =0;
	void val(int i) { v = i; }
	int i() { return v; }
private:
	int v;
};

class subclass : public Abstract {
public:
	void inc(int ii) { val(i() + ii); }
};
//------------------------------------------------------------------------------

int main ()
try
{
/*
Exercise 14.2:
	Simple_window win(Point(100,100),1600,1400,"Chapter 14.");
	Circle S(Point(300,300),200);
	Circle F(Point(800,500),200);
	//Error!
//	F = S;	//code.cpp:26:6: error: use of deleted function ‘Graph_lib::Circle& Graph_lib::Circle::operator=(const Graph_lib::Circle&)’

	win.wait_for_button();       // Display!
*/
//Exercise 14.3:

	subclass i;
	for (i.val(0); i.i() < 7; i.inc(1))
		cout << i.i() << endl;
	
	//Error!
	Abstract j;	//code.cpp:44:11: error: cannot declare variable ‘j’ to be of abstract type ‘Abstract’
}
catch(exception& e) {
    return 1;
}
catch(...) {
    return 2;
}

