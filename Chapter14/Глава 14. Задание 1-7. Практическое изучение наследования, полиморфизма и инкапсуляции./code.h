//
// Заглолвочный файл
//
// c++ -o code code.cpp GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp -lfltk -lfltk_images -std=c++11

#include "std_lib_facilities.h"
#include "GUI/Simple_window.h"    // if we want that "Next" button
#include "GUI/Graph.h"
#include <cmath>

//------------------------------------------------------------------------------


class Q {
public:
	virtual void f1() { inc(1); }
	void f2() { inc(2); }
	virtual void f3() { inc(3); }
	void inc(int ii) { i = ii; }
	int val() const { return i; }
private:
	int i;
};

struct W : Q {
	void f1() { inc(4); }
	void f2() { inc(5); } 
};

class E : public W {
public:
	void f3() { inc(6); }
};






class B1 {
public:
	virtual void vf() const { cout << "B1::vf()\n"; }
	void f() const { cout << "B1::f()\n"; }
	virtual void pvf() const { cout << "B1::pvf()\n"; }
};

struct D1 : B1 {
	void vf() const { cout << "D1::vf()\n"; }
	void f() const { cout << "D1::f()\n"; }
};

class D2 : public D1 {
public:
	void pvf() const { cout << "D2::pvf()\n"; }
};






struct B2 {
	virtual void pvf() const { cout << "B2::pvf()\n"; }
};

class D21 : public B2 {
public:
	string str = "STROKA";
	void pvf() const { cout << str << endl; }
};

class D22 : public B2 {
public:
	int k = 7;
	void pvf() const { cout << k << endl; }
};


//------------------------------------------------------------------------------

