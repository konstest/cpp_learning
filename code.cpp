//c++ -o code code.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
	string word;
//	vector<string> number;
	vector<string> number(10);
	number[0] = "zero";
	number[1] = "one";
	number[2] = "two";
	number[3] = "three";
	number[4] = "four";
	number[5] = "five";
	number[6] = "six";
	number[7] = "seven";
	number[8] = "eight";
	number[9] = "nine";
/*	cout << "Введите цифры прописью:\n";
	for (int i = 0; i < 10; i++)
		{
		cout << i << ": ";
		cin>>word;
		number.push_back(word);
		}
*/
	string num;
	cout << "Введите цифру прописью:\n";
	while (cin>>num)
		for (int i = 0; i < 10; i++)
			if (number[i] == num) cout << i <<endl;

	return 0;
}

