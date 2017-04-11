#include <iostream>       // std::cerr
#include <stdexcept>      // std::out_of_range
#include <vector>         // std::vector
#include <string>

using namespace std;
/*
	c++ -o code code.cpp -std=c++11
	Глава 8. Упражнение 5. Реализовать две функции меняющие последовательность
	чисел на обратную в векторе.
*/

//------------------------------------------------------------------------------
//Не изменяю первоначального вектора создаёт новый вектор собратной
// последовательностью элементов
vector<int> swap_x(vector<int> v)
{
	vector<int> x;
	for (int i=v.size(); i>0; i--)
		x.push_back(v[i-1]);
	return x;
}
//------------------------------------------------------------------------------
//Изменяет последовательность элементов на обратную в переданном ей векторе

void swap_y(vector<int>& v)
{
	for (int i=0; i<v.size()/2; i++)
		swap(v[i],v[v.size()-i-1]);
}
//------------------------------------------------------------------------------
//Вывод вектора на экран
void print(const string& comment, const vector<int>& v)
{
	cout << comment << endl;
	for (int i=0; i< v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

//------------------------------------------------------------------------------
int main ()
try {
	vector<int> f;
	cout << "Вводите элементы вектора: ";
	int elem;
	while (cin >> elem){
		f.push_back(elem);
	}
	
	vector<int> f2 = swap_x(f);
	print ("Вектор f после f2 = swap_x(f):",f);
	swap_y(f);
	print ("Вектор f после swap_y(f):",f);
	print ("Вектор f2:",f2);
	
	return 0;
}
catch (exception& e) {
	//Во время отладки программы данное исключение помогало определить причину
	//сегментации программы, выдавая сообщения вида: Ошибка: std::bad_alloc.
  cerr << "Ошибка: " << e.what() << '\n'; 
  return 1;
}

