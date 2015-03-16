#include <iostream>
#include <fstream>

using namespace std;

//c++ -o code code.cpp
int main () {
	string a;

	cout << "Вводите число: ";
	while (true)
		{
		cin >> a;
		if (a == "1") cout << "Один\n";
			else if (a == "2") cout << "Два\n";
				else if (a == "3") cout << "Три\n";
					else if (a == "4") cout << "Четыре\n";
						else if (a == "Один") cout << "1\n";
							else if (a == "Два") cout << "2\n";
								else if (a == "Три") cout << "3\n";
									else if (a == "Четыре") cout << "4\n";
										else cout << "Не знаю такого числа :(\n";
		}

return 0;
}

