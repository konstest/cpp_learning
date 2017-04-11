#include <iostream>
#include <fstream>

using namespace std;

//c++ -o code code.cpp
int main () {
	cout << "Введите через пробел val1 и val2: ";
	int val1,val2;
	cin >> val1 >> val2;
	if (val1 == val2) cout << "val1 = val2\n";
		else if (val1 > val2) cout << "val1 > val2\n";
			else cout << "val1 < val2\n";
	cout << "val1 + val2 = " << val1+val2 << endl;
	cout << "val1 - val2 = " << val1-val2 << endl;
	cout << "val1 * val2 = " << val1*val2 << endl;
	cout << "val1 / val2 = " << val1/val2 << endl;
return 0;
}
