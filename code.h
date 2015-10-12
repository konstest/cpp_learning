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
};

class Test_controller : Controller {
public:
	void show();
	void on() 	{ switcher = true; }
	void off()	{ switcher = false; }
	bool is_switcher()	{ return switcher; }
	int	 is_level()	{ return level; }
	void set_level(int lvl)	{ level = lvl; }
	Test_controller(): switcher(true), level(0) {}
private:
	bool switcher;
	int level;
};

class Set_controller : Controller {
public:
	void set_color(Color, Shape&);
	void set_style(Line_style, Shape&);	//third "thing" to control
};

