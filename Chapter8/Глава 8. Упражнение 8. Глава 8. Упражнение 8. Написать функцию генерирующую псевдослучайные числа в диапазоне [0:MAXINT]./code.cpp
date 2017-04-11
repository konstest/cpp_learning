#include "std_lib_facilities.h"

using namespace std;
/*
	c++ -o code code.cpp -std=c++11
	Глава 8. Упражнение 8. Написать функцию генерирующую псевдослучайные числа
	в диапазоне [0:MAXINT].
*/

//------------------------------------------------------------------------------

unsigned int randint()
{
	return rand() % (unsigned int)0xffffffff;
}

//------------------------------------------------------------------------------
int main ()
try {
	srand (time(NULL));
	cout << "Введите количество чисел, для генерации: ";
	int n=0;
	cin >> n;
	for (int i=0; i<n; i++)
		cout << i+1 << ": " << randint() << endl;
//	cout << (unsigned int)0xffffffff << endl;
	return 0;
}
catch (exception& e) {
  cerr << "Ошибка: " << e.what() << '\n'; 
  return 1;
}

