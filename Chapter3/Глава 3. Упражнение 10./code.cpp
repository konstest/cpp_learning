#include <iostream>
#include <fstream>

using namespace std;

//c++ -o code code.cpp
int main () {
	string operation;
	double a,b;
	cout << "Введите оператор и два числа (+ 3 0.7 = 3.7): ";
	cin >> operation >> a >> b;
	
	if (operation == "+") cout << a << "+" << b << "= " << a+b << endl;
		else if (operation == "-") cout << a << "-" << b << "= " << a-b << endl;
			else if (operation == "*") cout << a << "*" << b << "= " << a*b << endl;
				else if (operation == "/") cout << a << "/" << b << "= " << a/b << endl;
					else if (operation == "plus") cout << a << "+" << b << "= " << a+b << endl;
						else if (operation == "minus") cout << a << "-" << b << "= " << a-b << endl;
							else if (operation == "mul") cout << a << "*" << b << "= " << a*b << endl;
								else if (operation == "div") cout << a << "/" << b << "= " << a/b << endl;
									else cout << "Не знаю такого оператора :(, знаю: +,-,*,/,plus,minus,mul,div\n";

return 0;
}

