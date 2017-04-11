//c++ -o code code.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
/*
	Глава 4 Упражнение 8. Удваивание на каждой из 64-х клеток зёрна риса. 
*/

int main () {
	int rice_count=1;
	cout << "1: 1\n";
	for (int i = 1; i < 32; i++)
		{
		rice_count*=2;
		cout << i+1 << ": " << rice_count << endl;
		}
	return 0;
}

