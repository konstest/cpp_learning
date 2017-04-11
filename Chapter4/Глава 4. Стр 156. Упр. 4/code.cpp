//c++ -o code code.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
	int i=0, n=50, min=0, max=100;
	char answer;
	while (i<7)
		{
		cout << i+1 << ". Введи равно(=) или меньше(>) или больше(<), если число: " << n << "? ";
		cin>>answer;
		switch (answer)
		{
		case '=':
			cout << "Вы задумали: " << n << endl;
			return 0;
			break;
		case '>':
			max=n;
			n = ((max-min)/2) + min;
			i++;
			break;
		case '<':
			min=n;
			n = ((max-min)/2) + min;
			i++;
			break;
		default:
			cout << "Не знаю такого условия!\n";
		}
		}
	cout << "Вы задумали число: " << n;
	return 0;
}

