/*
 Глава 15.
	Class definition drill:: 1-9.
 clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code
*/

#include "code.h"
#include "cmath"

bool if_alnum(char ch)
{
	string str = ";:\"'[]*&^%$#@!";
	for (int i=0; i<str.size(); i++)
		if (ch == str[i])	return true;
	return false;
}

//------------------------------------------------------------------------------
Person::Person(string n, int a) {
	if (a >= 0 && a <= 150)
		second_name = a;
	else
		error("ERROR! Age should be within [0:150]");

	for (int i=0; i<n.size(); i++)
		if ( if_alnum(n[i]) ) error("The name must not contain: ;:\"'[]*&^%$#@!");
	first_name = n;
}

//------------------------------------------------------------------------------
int main ()
try
{
	Person P;
	vector<Person> N;
	for (int i=0; i<3; i++) {
		cin >> P;
		N.push_back(P);
	}
	cout << endl;
	for (int i=0; i<3; i++)
		cout << N[i];
}
catch(exception& e) {
	cout << e.what() << endl;
    return 1;
}
catch(...) {
    return 2;
}

