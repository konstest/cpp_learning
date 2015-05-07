//c++ -o code -std=c++11 code.cpp
//
// Глава 9. Упражнение 3. Перегрузить в созданном класск Name_pairs операторы <<, ==, !=.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Name_pairs {
public:
			Name_pairs();		// конструктор
	void read_names(const string&, const string );// ввод из std::in имён в vector<string> name
	void	read_ages(const string& );	// ввод из std::in возрастов для введённых имён
//	void	print()	const;		// перегрузили оператором <<
	void	sort();				// сортирует элементы векторов в алфавитном пор.
	vector<string>	names;
	vector<double>	ages;

private:
	bool is_set(const string& name)	const;
};

//------------------------------------------------------------------------------
//Конструктор без параметров
const	vector<string> default_names(0);	// пустые вектора для создания 
const	vector<double> default_ages(0);		// объекта класса через конструктор

Name_pairs::Name_pairs()	
	:names(default_names), ages(default_ages)
	{ }

//------------------------------------------------------------------------------
// Проверка для обхода дубликатаимёнв векторе
bool	Name_pairs::is_set(const string& name)	const
{
	for (int i=0; i<names.size(); i++)
		if (names[i] == name) return true;
	return false;
}

//------------------------------------------------------------------------------
// ввод из std::in имён в vector<string> name
void	Name_pairs::read_names(const string& comment, const string end_read_name)
{
	cout << comment;
	string name;
	cin >> name;
	while (name != end_read_name ) {
		if (!is_set(name)) names.push_back(name);
		else cout << "Имя [" << name << "] уже есть в программе!\n";
		cin >> name;
	}
}

//------------------------------------------------------------------------------
// ввод из std::in возрастов для введённых имён
void	Name_pairs::read_ages(const string& comment)
{
	cout << comment;
	double age;
	for (int i=0; i<names.size(); i++) {
		cout << i+1 << ": " << names[i] << ", ";
		if ( !(cin >> age) ) error ("Возраст должен быть числом!");
		ages.push_back(age);
	}
}

//------------------------------------------------------------------------------

void	Name_pairs::sort()				// сортирует элементы векторов в алфавитном пор.
{
	vector<string> old_names = names; //сохраняем изначальное состояние имён
	vector<double> temp_ages(ages.size());
	std::sort(names.begin(), names.end());
	for (int i=0; i<names.size(); i++)
		for(int j=0; j<old_names.size(); j++)
			if (names[i] == old_names[j]) {
				temp_ages[i] = ages[j];
				break;
			}
	ages = temp_ages;
}

//------------------------------------------------------------------------------
// Вывод объекта типа Name_pairs на экран
ostream& operator<<(ostream& os, const Name_pairs& P)
{
	string output;
	for (int i=0; i<P.names.size(); i++)
		output +=  to_string(i+1) + ": (" + P.names[i] + ", "
		+ to_string(P.ages[i]) +")\n";
	return os << output;
}

//------------------------------------------------------------------------------
// Сравнение объектов типа Name_pairs
bool operator==(const Name_pairs& A, const Name_pairs& B)
{
	if (A.names.size() == B.names.size()) {
		for (int i=0; i<A.names.size(); i++)
			if (A.names[i] != B.names[i] ||
			 A.ages[i] != B.ages[i] ) return false;
		return true;
	}
	return false;
}

bool operator!=(const Name_pairs& A, const Name_pairs& B)
{
	return !(A==B);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
int main()
try {
	Name_pairs T;
	const string end_read_name = ".";
	T.read_names("Введи, через пробел, ФИО(латиницей) и в конце поставьте "+
	end_read_name+"\n",end_read_name);
	T.read_ages("Теперь введи возраст каждого:\n");
	T.sort();
	cout << T;
	Name_pairs R = T;
	if (R == T) cout << "Objets is equal.\n";
	else cout << "Is not equal this objects!\n";
    return 0;
}
catch (exception& e) {
    cerr << "Ошибка: " << e.what() << endl; 
	return 1;
}
//------------------------------------------------------------------------------
