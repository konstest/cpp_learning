//c++ -o code code.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
/*
	Глава 5 Упражнение 2 - 5. Перевод температуры из Целься в Кельвины и наоборот.
*/

double ctok(double c)
//Преобразует шкалу Кельвина в шкалу Цельсия
{
	if (c < -273.15)
		{
		cerr << "ОШИБКА! Введённая температура ниже абсолютного нуля!\n";
 		exit(1);
		}
	double f = (9.0/5.0)*c + 32;
	return f;
}

int main () {
	double c = 0;				// объявляем переменную для ввода
	//INPUT
	cout << "Введите температуру по Цельсию: ";
	cin >> c;						// вводим температуру в переменную ввода
	//COMPUTING
	double k = ctok(c);	// преобразуем температуру
	//OUTPUT
	cout << "По Фаренгейту: " 	<< k << endl;

	return 0;
}


