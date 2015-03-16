#include <iostream>
#include <fstream>
//#include <string.h>

using namespace std;

//c++ -o code code.cpp
//*Steinbeck* *Heminway* *Fitzgerald*
int main () {

	cout << "Введите через пробел три значения: ";
	string a,b,c;
	cin >> a >> b >> c;
	
	if ( a < b && b<c) cout << a << ", " << b << ", " << c <<endl;
	if ( a < c && c<b) cout << a << ", " << c << ", " << b <<endl;
	if ( c < b && b<a) cout << c << ", " << b << ", " << a <<endl;
	if ( c < a && a<b) cout << c << ", " << a << ", " << b <<endl;
	if ( b < c && c<a) cout << b << ", " << c << ", " << a <<endl;
	if ( b < a && a<c) cout << b << ", " << a << ", " << c <<endl;
	
return 0;
}

