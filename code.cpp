//c++ -o code code.cpp
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;
/*
	Глава 5. Упражнение 7. Решение квадратичного уравнения вида ax^2 + bx + c = 0, с обработкой исключения.
*/

//Тип, созданный специально для сообщения о отрицательном дискриминанте
class negative_root { };

int abc(double A, double B, double C)
{
	double D, x1, x2;
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
	else	// Генерируем исключение
		{
		throw negative_root();
		cout << "D = " << D << endl;
		}
return 0;
}

int main () {
try {
	double A, B, C, D;
	//INPUT
	cout << "Решение квадратичного уравнения вида A*(x^2) + B*x + C = 0\n";
	cout << "введите А: ";
	cin >> A;
	cout << "введите B: ";
	cin >> B;
	cout << "введите C: ";
	cin >> C;

	//COMPUTING
	abc(A,B,C);
}
catch (negative_root) {
	cerr << "ОШИБКА! Отрицательный дискриминант!\n";
}
	return 0;
}

