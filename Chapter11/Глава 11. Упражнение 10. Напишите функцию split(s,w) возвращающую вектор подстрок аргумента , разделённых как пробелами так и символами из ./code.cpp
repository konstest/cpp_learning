//
//	Глава 11. Упражнение 10. Напишите функцию split(s,w) возвращающую вектор подстрок
//	аргумента $s, разделённых как пробелами так и символами из $w.
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

void whitespace(string& s, const string spliters)
{
	for (int i=0; i<s.size(); i++)
		for (int j=0; j<spliters.size(); j++)
			if (s[i] == spliters[j]) s[i]=' ';
}

//------------------------------------------------------------------------------

int main()
try
{
	string str;
	cout << "Input line:\n";
	getline(cin,str);
	whitespace(str,"!@#$%^&*()№?_+-:.,/{}[]`~");
	print(split(str));
    return 0;
}
catch (...) {
    cerr << "Oops... exception...\n";
    return 1;
}

