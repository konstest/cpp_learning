//c++ -o code code.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int name_to_value (string name);

int main () {
	int arg1, arg2;
	string num1, num2;
	char op;
	cout << "Введите два числа прописью и оператор (+-/*):\n";
	while (cin>>num1>>num2>>op)
		{
		arg1 = name_to_value(num1);
		arg2 = name_to_value(num2);
		if (arg1 == -1 || arg2 == -1) op = '!';
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
			case '!':
				break;
			default:
				cout << "Нет такого оператора - \'" << op << "\' !\n";
			}
		}
	return 0;
}

int name_to_value (string name)
{
	vector<string> number(10);
	number[0] = "zero";
	number[1] = "one";
	number[2] = "two";
	number[3] = "three";
	number[4] = "four";
	number[5] = "five";
	number[6] = "six";
	number[7] = "seven";
	number[8] = "eight";
	number[9] = "nine";
	for (int i = 0; i < 10; i++)
		if (number[i] == name) return i;
	cout << "Такого названия \'" << name << "\' числа не существует!\n";
	cout << "Введите два числа прописью и оператор (+-/*):\n";
	return -1;
}

