/*
 Глава 14. Упражнение 15.

 clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code
*/

#include "code.h"
#include "cmath"

//------------------------------------------------------------------------------

double* Vector_iterator::next()
{
	if (it != v.end()) {
		it++;
		return &(*(it-1));
	}
	else
		return 0;
}

double* List_iterator::next()
{
	list<double>::iterator i;
	if (it != l.end()) {
		i = it;
		it++;
		return &(*(i));
	}
	else
		return 0;
}

void print(Iterator& itr)
{
	double *k = itr.next();
	while (k != 0) {
		cout << *k << endl;
		k = itr.next();
	}
}

//------------------------------------------------------------------------------
int main ()
try
{
	vector<double> k; 
	for (double i=0.25; i<=10; i+=0.75)
		k.push_back(i);
	Vector_iterator r(k);
	cout << "Vector:\n";
	print(r);

	list<double> t;
	for (double i=0.05; i<=10; i+=1.75)
		t.push_back(i);
	List_iterator l(t);
	cout << "\nList:\n";
	print(l);
}
catch(exception& e) {
    return 1;
}
catch(...) {
    return 2;
}

