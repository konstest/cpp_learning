//c++ -o code code.cpp
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;
/*
	Глава 4 Упражнение 18. Решение квадратичного уравнения вида ax^2 + bx + c = 0
*/

int main () {
	int i;
	double A, B, C, D, x1, x2;
	bool repeat_moda = false;
	
	//INPUT
	cout << "Решение квадратичного уравнения вида A*(x^2) + B*x + C = 0\n";
	cout << "введите А: ";
	cin >> A;
	cout << "введите B: ";
	cin >> B;
	cout << "введите C: ";
	cin >> C;
		
	//COMPUTING
	cout << "Вычисляем решение уравнения " << A << "*(x^2) + " << B << "*x + " << C <<" = 0\n";
	D = B*B - 4*A*C;
	if (D > 0)
		{
		x1 = (-B + sqrt(D))/(2*A);
		x2 = (-B - sqrt(D))/(2*A);	
		//OUTPUT
		cout << "Корни квадратного уравнения равны:\n";
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
		}
	else
		cout << "Отрицательный дискриминант!\n";

	return 0;
}

