//
// Заглолвочный файл
//
// clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "std_lib_facilities.h"
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"
#include <list>

//------------------------------------------------------------------------------

class Iterator {
public:
	virtual double* next() {}
};

class Vector_iterator : public Iterator {
public:
	double* next();
	Vector_iterator(vector<double>& init): v(init) { it = v.begin();}
private:
	std::vector<double>::iterator it;		//создаём итератор, через который будем получать доступ к элементам вектора
	vector<double>	v;
};


class List_iterator : public Iterator {
public:
	double* next();
	List_iterator(list<double>& init): l(init) { it = l.begin();}
private:
	std::list<double>::iterator it;		//создаём итератор, через который будем получать доступ к элементам вектора
	list<double>	l;
};

