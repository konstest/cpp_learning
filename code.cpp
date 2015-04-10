#include <iostream>       // std::cerr
#include <stdexcept>      // std::out_of_range
#include <vector>         // std::vector
#include <string>

using namespace std;
/*
	c++ -o code code.cpp -std=c++11
	try/catch-исключения. Глава 5. Упражнение 10. Нахождение последовательности
	Фибоначи, а так же последнего числа этой последовательности, которое можно 
	записать в переменную типа int.
*/

//0xffffffff = 4294967295
const unsigned int uint_max_vol = (unsigned long)0xffffffff;


vector<unsigned long> create_fibo_vector()
{//Создаём вектор Фибоначчи
	vector<unsigned long> V;
	V.push_back(1);
	V.push_back(1);
	int i = 1;
	long element = V[0] + V[1];
	while ( element <= uint_max_vol )
	{
		V.push_back(element);
		i++;
		element = V[i-1] + V[i];
	}
	return V;
}

int output_fibo_vector(vector<unsigned long> V)
{//Выводим на экран вектор
	cout << "Вектор Фибоначчи:\n";
	for (unsigned int i = 0; i < V.size(); i++)
		cout << V[i] << " ";
	cout << "...\nПоследние число Фибоначчи, которо можно записать в переменную \
	типа int: " << V[V.size()-1] << " < int_max(" << uint_max_vol << ")\n";
}

//--------------------------------------------------------------------------------
int main () {

try {
	vector<unsigned long> V;

	//INPUT
	//COMPUTING
	V = create_fibo_vector();
	//OUTPUT
	output_fibo_vector(V);
}
catch (exception& e) {
	//Во время отладки программы данное исключение помогало определить причину
	//сегментации программы!
  cerr << "Ошибка: " << e.what() << '\n'; 
  return 1;
}

return 0;
}

