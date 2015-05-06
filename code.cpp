#include "std_lib_facilities.h"

using namespace std;
/*
	c++ -o code code.cpp -std=c++11
	Глава 8. Упражнение 7. Реализация сразу же с собственным классом.
*/

//------------------------------------------------------------------------------
class info {
public:
	string name;
	double age;
	info(): name(""), age(0) {}	//конструктор
};

const int people_count = 5;		// Колличество вводимых людей в программу

//------------------------------------------------------------------------------
//Проверка на наличие совпадений ФИО
bool is_install(const info& t, const vector<info>& x)
{
	for (int i=0; i<x.size(); i++)
		if (x[i].name == t.name) return true;
	
	return false;
}
//------------------------------------------------------------------------------
// Создание из потока ввода вектора типа info
vector<info> input_info()
{
	vector<info> x;
	cout << "Вводите ФИО(латиницей) и возраст через запятую ',':\n";
	for (int i=0; i<people_count; i++)	{
		info t;
		cout << i+1 << ": ";
		while (char ch = cin.get())							// Сперва
			if ( ch != ',')	{								// вводим
				if (isalpha(ch) || ch == ' ') t.name+=ch;	// ФИО
			}												// далее
			else break;										// после запятой
		if ( !(cin >> t.age) ) error("Возраст должен быть целым числом!");
		if (!is_install(t,x)) x.push_back(t);
		else error("Уже введено такое ФИО: ",t.name);
	}
	return x;
}

//------------------------------------------------------------------------------
// условие сортировки
bool sor (info a, info b)
{
	return (a.name < b.name);
}
//------------------------------------------------------------------------------
// Вывод на экран вектора
void print_info(const vector<info>& x)
{
	for (int i=0; i<x.size(); i++)
		cout << i+1 << ": " << x[i].name << ", " << x[i].age << endl;
}

//------------------------------------------------------------------------------
int main ()
try {
	vector<info> f = input_info();
//	print_info(f);
	sort(f.begin(),f.end(),sor);
	cout << "Вектор после сортировки:\n";
	print_info(f);
	
	return 0;
}
catch (exception& e) {
	//Во время отладки программы данное исключение помогало определить причину
	//сегментации программы, выдавая сообщения вида: Ошибка: std::bad_alloc.
  cerr << "Ошибка: " << e.what() << '\n'; 
  return 1;
}

