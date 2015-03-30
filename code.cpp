//c++ -o code code.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
/*
	Глава 4 Упражнение 19 - 21.
*/

int main () {
	bool search;
	string name;
	vector<string> names(14);
	names[0] = "Konstantin";
	names[1] = "Margarita";
	names[2] = "Irina";
	names[3] = "Sergey";
	names[4] = "Vadik";
	names[5] = "test";
	names[6] = "kos";
	names[7] = "Konstasdefntin";
	names[8] = "Marg34arita";
	names[9] = "Irdasfna";
	names[10] = "Se13rgey";
	names[11] = "Vfdadik";
	names[12] = "tfest";
	names[13] = "kdfsos";
	int score;
	vector<int> scores(14);
	scores[0] = 7;
	scores[1] = 6;
	scores[2] = 5;
	scores[3] = 4;
	scores[4] = 3;
	scores[5] = 2;
	scores[6] = 1;
	scores[7] = 7;
	scores[8] = 6;
	scores[9] = 5;
	scores[10] = 4;
	scores[11] = 3;
	scores[12] = 2;
	scores[13] = 1;

	//INPUT
	cout << "Для пойска введите количество баллов и нажмите [ENTER]:\n";
	while (cin >> score)
		{
		search = false;
		for (int i = 0; i < names.size(); i++)
			{
			if (score == scores[i])
				{
				cout << "(" << names[i] << "," << scores[i] << ")\n";
				search = true;
				}
			}
		if (!search)  cout << "Score not found!\n";
		}
	//COMPUTING
	

	return 0;
}


