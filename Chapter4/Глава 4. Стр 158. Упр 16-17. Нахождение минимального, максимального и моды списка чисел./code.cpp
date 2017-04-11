//c++ -o code code.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
/*
	Глава 4 Упражнение 16. Напишите программу определяющую моду набора положительных чисел.
	Мода — это число в последовательности чисел повторяющееся наибольшее количество раз.
*/

int main () {
	int i,j, value, moda=-1, max=0, count=0, min_v, max_v;
	vector<int> v;
	bool repeat_moda = false;
	
	//INPUT
	cout << "Введите последовательность положительных чисел:\n";
	while (cin>>value)
		{
		if (value < 0)
			{
			cout << "Ошибка!!! Вектор должен состоять из положительных чисел!\n";
			return 1;
			}
		v.push_back(value);
		}
		
	//COMPUTING
	min_v = v[0];
	max_v = v[0];
	while (v.size() > 0)
		{
		if (max_v < v[0]) max_v = v[0];
		if (min_v > v[0]) min_v = v[0];
		count = 0;
		for (j = 0; j < v.size(); j++)
			if (v[0] == v[j])
				count++;
		if (max == count)
			repeat_moda = true;			
		if (max < count && count > 1)
			{
			moda = v[0];
			max = count;
			repeat_moda = false;
			}
		v.erase(v.begin());
		}

	//OUTPUT
	cout << "Наименьшее число: " << min_v << endl;
	cout << "Наибольшее число: " << max_v << endl;
	if (!repeat_moda && moda != -1)
		cout << "Модой является - " << moda << " повторяется " << max << " раз(а).\n";
	else 
		cout << "В данном списке чисел нет МОДЫ.\n";
	return 0;
}

