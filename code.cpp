//c++ -o code code.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
/*
	Глава 4 Упражнение 15. Нахождение N-ого количества простых чисел
	Просто́е число́ — это натуральное (целое положительное) число, имеющее ровно два различных натуральных делителя. Другими словами, число p простое, если оно больше 1 и делится только на 1 и на p.
*/

int main () {
	int value, i;
	vector<int> primes;
	bool not_prime;
	primes.push_back(1);
	cout << "Введите количество простых чисел которое нужно расчитать: ";
	cin>>value;
	i = 2;
	while (primes.size() < value)
		{
		not_prime = false;
		for (int j = 2; j < i; j++)
			if (i%j == 0) //Если число делится число меньше себя без остатка, то
				{
				not_prime = true;  // это не простое число
				break;
				}
		if (!not_prime) primes.push_back(i);
		i++;
		}
	for (int i=0; i < primes.size(); i++)
		cout << i+1 << ": " << primes[i] << endl;
	return 0;
}

