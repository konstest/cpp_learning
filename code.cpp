//c++ -o code code.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
/*
	Глава 4 Упражнение 11. Нахождение вектора простых чисел от 1 до 100
	Просто́е число́ — это натуральное (целое положительное) число, имеющее ровно два различных натуральных делителя. Другими словами, число p простое, если оно больше 1 и делится только на 1 и на p.
*/

int main () {
	int value;
	vector<int> primes;
	bool not_prime;
	primes.push_back(1);
	cout << "Введите максимум, до которого нужно расчитать вектор простых чисел: ";
	cin>>value;
	for (int i = 2; i <= value; i++)
		{
		not_prime = false;
		for (int j = 2; j < i; j++)
			if (i%j == 0) //Если число делится число меньше себя без остатка, то
				{
				not_prime = true;  // это не простое число
				break;
				}
		if (!not_prime) primes.push_back(i);
		}
	for (int i=0; i < primes.size(); i++)
		cout << i+1 << ": " << primes[i] << endl;
	return 0;
}

