//
// Заглолвочный файл
//
// clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "std_lib_facilities.h"
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"
#include <list>

//------------------------------------------------------------------------------

class Person {
private:
	string first_name;
	int second_name;
public:
	Person() {}
	Person(string n, int a);
	int		age() 	const { return second_name; }
	string	name()	const { return first_name; }
};

ostream& operator<<(ostream& os, Person& pe) {
	return os << pe.name() << " " << pe.age() << endl;
}

istream& operator>>(istream& is, Person& pe) {
	int age;
	string name;
	is >> name >> age;
	if (!is) {
		cout << "Error input format!\n";
		return is;
	}
	pe = Person(name,age);
	return is;
}

//------------------------------------------------------------------------------

