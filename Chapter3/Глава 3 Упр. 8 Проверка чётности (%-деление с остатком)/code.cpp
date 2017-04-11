#include <iostream>
#include <fstream>

using namespace std;

//c++ -o code code.cpp
int main () {

	cout << "Введите число для проверки чётности: ";
	int a;
	cin >> a;
	
	if ( a%2 == 0 ) cout << "Число " << a << " чётное :)\n";
		else cout << "Число " << a << " не чётное :(\n";

return 0;
}

