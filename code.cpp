//
//	Глава 11. Упражнение 12. Изменение порядка слов в файле:
//	What you name? -> name? you What

#include "code.h"

using namespace std;

//------------------------------------------------------------------------------

string read_file(const string& filename)
{
	ifstream ist(filename.c_str());
	if (!ist) error("Don`t read this file: "+filename);
	char ch;
	string line;
	while (ist.get(ch)) {
		line += ch;
		if (ist.eof()) break;
	}
	return line;
}
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
		cout << v[i] << " ";
}

void revers_write(const string& filename, const vector<string>& v)
{
	ofstream out(filename.c_str());
	if (!out) error("Don`t read this file: "+filename);
	for (int i=v.size()-1; i>=0; i--)
		out << v[i] << " ";
}
//------------------------------------------------------------------------------

int main()
try
{
	string filename;
	cout << "Input filename: ";
	cin >> filename;
	string line = read_file(filename);
	vector<string> v = split(line);
	print(v);
	cout << endl;
	revers_write(filename,v);
	line = read_file(filename);
	v = split(line);
	print(v);
    return 0;
}
catch (...) {
    cerr << "Oops... exception...\n";
    return 1;
}

