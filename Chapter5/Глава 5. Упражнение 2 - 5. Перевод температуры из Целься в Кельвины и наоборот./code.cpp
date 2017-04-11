//c++ -o code code.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
/*
	Глава 5 Упражнение 2. Перевод температуры из Целься в Кельвины и наоборот.
*/

double ctok(double c)
//Преобразует шкалу Кельвина в шкалу Цельсия
{
	if (c < 0)
		{
		cerr << "ОШИБКА! Введённая температура ниже абсолютного нуля!\n";
 		exit(1);
		}
	double k = c - 273.15;
	return k;
}

int main () {
	double c = 0;				// объявляем переменную для ввода
	//INPUT
	cin >> c;						// вводим температуру в переменную ввода
	//COMPUTING
	double k = ctok(c);	// преобразуем температуру
	//OUTPUT
	cout << k << endl;

	return 0;
}


