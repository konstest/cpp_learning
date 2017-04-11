//
//	Глава 11. Упражнение 11. Изменить порядок следования символов в фале:
//	qweasdzxc -> cxzdsaewq
//

#include "code.h"

using namespace std;

//------------------------------------------------------------------------------

void print(string& line)
{
	for (int i=0; i<line.size(); i++)
		cout << line[i] ;
}

//------------------------------------------------------------------------------

string read_file(const string& filename)
{
	ifstream f(filename.c_str());
	if (!f) error ("Don`t read this file: "+filename);
	char ch;
	string line;
	while (f.get(ch)) {
		line += ch;
		if (f.eof()) break;
		if (f.fail()) error ("ERROR read file: "+filename);
	}
	return line;
}

//------------------------------------------------------------------------------

void write_file(const string& filename, const string& str)
{
	ofstream f(filename.c_str());
	if (!f) error ("Don`t read this file: "+filename);
	for (int i=str.size()-1; i>=0; i--)
		f << str[i];
}
//------------------------------------------------------------------------------

int main()
try
{
	string filename;
	cout << "Input filename: ";
	cin >> filename;
	string line = read_file(filename);
	print(line);
	write_file(filename,line);
	line = read_file(filename);
	cout << endl;
	print(line);
    return 0;
}
catch (...) {
    cerr << "Oops... exception...\n";
    return 1;
}

