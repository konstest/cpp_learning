#include "std_lib_facilities.h"

using namespace std;
/*
	c++ -o code code.cpp -std=c++11
	Глава 8. Упражнение 9. Написать функцию генерирующую псевдослучайные числа
	в диапазоне [a:b].
*/

//------------------------------------------------------------------------------

unsigned int rand_in_range(unsigned int a, unsigned int b)
{
	return rand() % b + a;
}

//------------------------------------------------------------------------------
int main ()
try {
	srand (time(NULL));
	cout << "Введите количество чисел, для генерации и диапазон (n a b): ";
	int n=0,a=0,b=0;
	cin >> n >> a >> b;
	for (int i=0; i<n; i++)
		cout << i+1 << ": " << rand_in_range(a,b) << endl;
//	cout << (unsigned int)0xffffffff << endl;
	return 0;
}
catch (exception& e) {
  cerr << "Ошибка: " << e.what() << '\n'; 
  return 1;
}

