#include <iostream>       // std::cerr
#include <stdexcept>      // std::out_of_range
#include <vector>         // std::vector
#include <string>

using namespace std;
/*
	c++ -o code code.cpp -std=c++11
	try/catch-исключения. Глава 5. Упражнение 8-9. Ввод вектора V чисел и нахождение
	суммы первых N элементов. И создание вектора R разностей между соседними N-1
	элементами вектора V.
*/

int input(vector<double> &v)
{
//Вводим элементы вектора

	string element;
	while (cin >> element)
		if ( element != "|" )
			v.push_back(stod(element));
		else
			break;

	return 0;
}

int summ(vector<double> v, int N)
{
//вычисляем сумму первых N эл-ов вектора.
	double summ = 0;
	if (N > 1)
		{
		if (N > v.size()) throw runtime_error( "N = "+ to_string(N) +" больше чем "+ to_string(v.size()) + " элемента(ов) вектора." );
		cout << "Сумма первых " << N << " чисел:";
		for (int i = 0; i < N; i++)
			{
			if (i < N-1) cout << " " << v[i];
				else	cout << " и " << v[i];
			summ += v[i];
			}
		cout << " равна " << summ << ".\n";
		}
	else
		throw runtime_error("Количество чисел(N) должно быть больше 1 и меньше "+to_string(v.size()) );

	return 0;
}

vector<double> residual (vector<double> v, int N)
{//Нахождение разности рядом стоящих элементов с 1-ого по N-ый.
//т.е. vec: 1 3 2 5 6 7, N = 4, то разность: 1-3=-2, 3-2=1, 2-5=-3
	vector<double> r;
	for (int i=0; i<N-1; i++)
		r.push_back(v[i]-v[i+1]);
	
	return r;
}


//--------------------------------------------------------------------------------
int main () {

try {
	vector<double> v,r;
	unsigned int N;
//	cout << sizeof() << endl;
	//INPUT
	cout << "Вводите элементы вектора, | - означает конец ввода:\n";
	input(v);

	cout << "Пожайлуста, введите количество чисел(N), которые хотите просумировать (начиная с первого):\n";
	if ( !(cin >> N) )
		throw runtime_error( "Количество чисел(N) - есть число типа(int) от 2 до " + to_string( v.size() ) );

	//COMPUTING
	summ(v,N);
	r = residual(v,N);
	cout << "Вектор N-1 разностей между соседними величинами: ";
	for (int i=0; i<r.size(); i++)
		cout << r[i] << " ";
	cout << endl;
}

catch (out_of_range) {
//  cerr << "Значения элементов вектора должны входить в предел от -2147483647 до 2147483647" << '\n'; 
  cerr << "Значения элементов вектора должны входить в предел типа double" << endl; 
  return 1;
}
catch (invalid_argument) {
  cerr << "Елементы вектора - есть целочисленный(int) тип!" << '\n'; 
  return 2;
}
catch (exception& e) {
  cerr << "Ошибка: " << e.what() << '\n'; 
  return 3;
}

return 0;
}

