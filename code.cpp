//
//	Глава 11. Упражнение 9. Напишите функцию split(s) возвращающую вектор подстрок
//	аргумента $s, разделённых пробелами.
//

#include "code.h"

using namespace std;

//------------------------------------------------------------------------------

vector<string> split(const string& s)
{
	string word;
	vector<string> v;
	istringstream is(s);
	while (is >> word) v.push_back(word);
	return v;
}

//------------------------------------------------------------------------------

void print(const vector<string>& v)
{
	for (int i=0; i<v.size(); i++)
		cout << v[i] << endl;
}
//------------------------------------------------------------------------------

int main()
try
{
	string str;
	cout << "Input line:\n";
	getline(cin,str);
	print(split(str));
    return 0;
}
catch (...) {
    cerr << "Oops... exception...\n";
    return 1;
}

