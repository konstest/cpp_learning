#include "std_lib_facilities.h"

using namespace std;
/*
	c++ -o code code.cpp -std=c++11
	Глава 8. Упражнение 12. Написать функцию находящую min, max, среднее
	значение и медиану переданного ей по ссылке вектора.
*/

//------------------------------------------------------------------------------

vector<int> make_vector(int n, unsigned int a, unsigned int b)
{
	srand (time(NULL));
	vector<int> t;
	for (int i=0; i<n; i++)
		t.push_back(rand() % b + a);
	return t;
}

//------------------------------------------------------------------------------

void print ( const vector<int>& v)
{
	for (int i=0; i<v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

//------------------------------------------------------------------------------
struct results {
	int min;
	int max;
	double average;
	double median;
};
//------------------------------------------------------------------------------
// Вычисление минимума, максимум, среднего и медианы вектора.
results computing (vector<int>& v)
{
	results T;
	int v_size = v.size();
	sort(v.begin(), v.end());
	T.min = v[0];
	T.max = v[v_size-1];
	double summ = 0;
	for (int i=0; i < v_size; i++)
		summ += (double)v[i];
	T.average = summ/v_size;
	if (v_size%2 == 0) {	// если чётное кол-во элементов, то
		T.median = ((double)v[v_size/2-1] + (double)v[v_size/2])/2;
	}
	else {					// если не чётное
		T.median = v[v_size/2];
	}
	return T;
}
//------------------------------------------------------------------------------
int main ()
try {
	cout << "Введите количество чисел, для генерации и диапазон (n a b): ";
	int n=0,a=0,b=0;
	cin >> n >> a >> b;
	vector<int> f = make_vector(n,a,b);		//создаём вектор
	print(f);
	results R = computing(f);
	print(f);
	cout << "Min: " << R.min << endl;
	cout << "Max: " << R.max << endl;
	cout << "Avarage: " << R.average << endl;
	cout << "Median: " << R.median << endl;
	return 0;
}
catch (exception& e) {
  cerr << "Ошибка: " << e.what() << '\n'; 
  return 1;
}

