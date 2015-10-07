//
// Заглолвочный файл
//
// clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "std_lib_facilities.h"
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"
#include <list>

//------------------------------------------------------------------------------

class Controller {
public:
	virtual void on() 	{}
	virtual void off()	{}
	virtual void set_level(int)	{}
	virtual void show()	{}
private:
	bool switcher;
	
};

class Test_controller : Controller {
	void show();
}
