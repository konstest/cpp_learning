/* 
 * Chapter 18. Try 18.4.2
 * clear; c++ -o code code.cpp -std=c++11 && ./code
 */

#include <iostream> 
#include "code.h"

using namespace std;

X glob(2);
X copy(X a) { return a; }
X copy2(X a) { X aa = a; return aa; }
X& ref_to(X& a) { return a; }
X* make(int i) { X a(i); return new X(a); }
struct XX { X a; X b; };

int main()
{
    cout << "Start program!\n";
    cout << "X loc {4};\n";
	X loc {4};	// local variable
    cout << "X loc2 {loc};\n";
	X loc2 {loc};	// copy construction
    cout << "loc = X{5};\n";
	loc = X{5};	// copy assignment
    cout << "loc2 = copy(loc);\n";
	loc2 = copy(loc);	// call by value and return
    cout << "loc2 = copy2(loc);\n";
	loc2 = copy2(loc);
    cout << "X loc3 {6};\n";
	X loc3 {6};
    cout << "X& r = ref_to(loc);\n";
	X& r = ref_to(loc);	// call by reference and return
    cout << "delete make(7);\n";
	delete make(7);
    cout << "delete make(8);\n";
	delete make(8);
    cout << "vector<X> v(4);\n";
	vector<X> v(4);	// default values
    cout << "XX loc4;\n";
	XX loc4;
    cout << "X* p = new X{9};\n";
	X* p = new X{9};	// an X on the free store
    cout << "delete p;\n";
	delete p;
    cout << "X* pp = new X[5];\n";
	X* pp = new X[5];	// an array of Xs on the free store
    cout << "delete[] pp;\n";
	delete[] pp;

    cout << "End programm!\n";

    return 0;
}
