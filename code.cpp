//c++ -o code code.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
/*
	Глава 6. Упражнение 4. Использование конструкторов при инициализации
	объектов класса.
*/

class Name_value {
public:
	string name;
	int score;
	Name_value(string n) :name(n), score(0) {}
	Name_value(int s) :name("test"), score(s) {}
	Name_value(string n, int s) :name(n), score(s) {}
};

int main () {
	bool search;
	int score;

	//the test initialization
	Name_value t0("QWER");
	Name_value t1(7);

//инициализация
	vector<Name_value> v;						//don`t working
	v.push_back(Name_value("Konstantin",7));
	v.push_back(Name_value("Margarita",6));
	v.push_back(Name_value("Irina",9));
	v.push_back(Name_value("Sergey",3));
	v.push_back(Name_value("Vadik"));		// Vadik,0
	v.push_back(Name_value(9));					// test, 9
	v.push_back(Name_value("Kos",5));
	v.push_back(Name_value("Garry",3));
	v.push_back(Name_value("KOnst)df2",5));
	v.push_back(Name_value("Margo",2));
	v.push_back(Name_value("Indiana",5));
	v.push_back(Name_value("Djonse",3));
	v.push_back(Name_value("Djonce",1));
	v.push_back(Name_value("Bionce",4));

	//INPUT
	cout << "Для пойска введите количество баллов и нажмите [ENTER]:\n";
	while (cin >> score)
		{
		search = false;
		for (int i = 0; i < v.size(); i++)
			{
			if (score == v[i].score)
				{
				cout << "(" << v[i].name << "," << v[i].score << ")\n";
				search = true;
				}
			}
		if (!search)  cout << "Score not found!\n";
		}
	//COMPUTING
	

	return 0;
}

