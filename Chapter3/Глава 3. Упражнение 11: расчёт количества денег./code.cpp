//c++ -o code code.cpp
#include <iostream>
#include <fstream>

using namespace std;

string ending(int c, int graduation) {
string end;
	if (graduation == 1) end="одно";
		else if (graduation == 5) end="пяти";
			else if (graduation == 10) end="десяти";
				else if (graduation == 25) end="25-";
					else if (graduation == 50) end="50-";
						else return "Не знаю монет такого достоинства!";
	while (c > 9) c/=10;
	if (c == 1) return end+"центовая монета.";
	if (2 <= c && c <= 4 || c == 23 ) return end+"центовые монеты.";	
	return end+"центовых монет.";
}

int main () {
	string operation;
	int c1,c5,c10,c25,c50;
	cout << "Программа расчёта общего количества находящихся у вас денег.\n";
	cout << "Введите через пробел количество находящихся у вас\n 1- 5- 10- 25- 50-центовых монет: ";
	cin >> c1 >> c5 >> c10 >> c25 >> c50;
	cout << "У вас:\n";
	if (c1 > 0)	cout << c1 << " " << ending(c1,1) << endl;
	if (c5 > 0)	cout << c5 << " " << ending(c5,5) << endl;
	if (c10 > 0)	cout << c10 << " " << ending(c10,10) << endl;
	if (c25 > 0)	cout << c25 << " " << ending(c25,25) << endl;
	if (c50 > 0)	cout << c50 << " " << ending(c50,50) << endl;
	cout << "Общая стоимость ваших монет равна " << c50*50+c25*25+c10*10+c5*5+c1 << " центам\n";
	if ( (c50*50+c25*25+c10*10+c5*5+c1)/100 > 0 )
	cout << "Или $" << (double)(c50*50+c25*25+c10*10+c5*5+c1)/100 << " долларов\n";
return 0;
}

