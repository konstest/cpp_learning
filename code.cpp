#include <iostream>
#include <fstream>

using namespace std;

//c++ -o code code.cpp
int main () {
	cout << "Введите количество целых чисел, которые будите вводить: ";
	int n;
	cin >> n;
	cout << "Введите три целых числа через пробел: ";
	int A[20],i;
	for (i=0; i<n; i++)
		cin >> A[i];

					for (i=0; i<n; i++)
						cout << A[i] << ' ';
					cout << endl;

	int buf;
	bool k=false;
	i=0;
	while (true) {
		if (A[i] > A[i+1]) {
			buf=A[i];
			A[i]=A[i+1];
			A[i+1]=buf;
			k=true;
			}
		i++;
		if (i==n-1)
			if (k) { i=0; k=false; }
				else {
					for (int j=0; j<n; j++)
						cout << A[j] << ' ';
					cout << endl;
					return 0;
					}
		}
return 0;
}

