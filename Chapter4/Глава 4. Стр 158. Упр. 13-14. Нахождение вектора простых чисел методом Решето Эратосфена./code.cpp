//c++ -o code code.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
/*
						//https://ru.wikipedia.org/wiki/Решето_Эратосфена
	Глава 4 Упражнение 11. Нахождение вектора простых чисел от 1 до 100 методом ЭРАТОСФЕНА.
	Просто́е число́ — это натуральное (целое положительное) число, имеющее ровно два различных натуральных делителя. Другими словами, число p простое, если оно больше 1 и делится только на 1 и на p.
*/
int main () {
	int value,i;
	cout << "Введите максимум, до которого нужно расчитать вектор простых чисел: ";
	cin>>value;
	//Создаём вектор размерностью value, в котором пока все значения равны "1"
	vector<int> primes;
	for (i = 0; i < value; i++)
		primes.push_back(1);

	//Оставляем в инициализированном выше векторе единицы только на позициях простых чисел
	int p = 2, step=0;
	bool deleting=true;
	while (deleting)
		{
		deleting=false;
		if (step < 2)
			{
			for (i = 2*p; i < value; i+=p )
				if (primes[i] == 1)
					{
					primes[i] = 0;
					deleting = true;
					}
			}
		else //С третьего шага начинаем удалять составныечисла числа начиная с позиции p*p
				// т.к. до этой позиции они уже удалены
			{
			for (i = p*p; i < value; i+=p )
				if (primes[i] == 1)
					{
					primes[i] = 0;
					deleting = true;
					}
			}
				
		for (i = p + 1; i < value; i++)
			if (primes[i] == 1 )
				{
				p = i;
				break;
				}
		step++;
		}
	//Выводим вектор на экран
	int j = 0;
	for (i=1; i < primes.size(); i++)
		if (primes[i] == 1)
			{
			cout << j+1 << ": " << i << endl;
			j++;
			}
	cout << "Количество выполненых итераций: " << step << endl;
	return 0;
}

