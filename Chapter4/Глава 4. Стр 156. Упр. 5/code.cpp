//c++ -o code code.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
	double arg1, arg2;
	char op;
	cout << "Введите два числа и оператор (+-/*):\n";
	while (cin>>arg1>>arg2>>op)
		switch (op)
			{
			case '+':
				cout << "Сумма " << arg1 << " и " << arg2 << " равна " << arg1 + arg2 << endl;
				break;
			case '-':
				cout << "Разница " << arg1 << " и " << arg2 << " равна " << arg1 - arg2 << endl;
				break;
			case '*':
				cout << "Произведение " << arg1 << " и " << arg2 << " равно " << arg1 * arg2 << endl;
				break;
			case '/':
				cout << "Частное " << arg1 << " и " << arg2 << " равно " << arg1 / arg2 << endl;
				break;
			}
	
	return 0;
}

