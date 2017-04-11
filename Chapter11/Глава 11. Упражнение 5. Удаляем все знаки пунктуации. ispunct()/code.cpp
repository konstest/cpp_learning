//
//	Глава 11. Упражнение 5. Удаляем все знаки пунктуации. ispunct()
//
/*
	cout << showbase;
	cout << '\t' << dec << birth_year << endl;
	cout << '\t' << hex << birth_year << endl;
	cout << '\t' << oct << birth_year << endl;
	cout << birth_year << endl;
	cout << "Input:" << endl;
	cin.unsetf(ios::dec|ios::oct|ios::hex);
	cin.unsetf();
	cin >> a >> b >> c;
	cout << a << " " << b << " " << c << endl;
	cout << "(общий)\t\t"<< 1234567.89 << endl;
	cout << "(фиксированный)\t"<< fixed << 1234567.89 << endl;
	cout << "(научный)\t"<< scientific << 1234567.89 << endl;
	a=007;
	b=1000;
	c=9;
	ostringstream out;
	out << "WORD_" << a << c << "_" << b;
	string t="1234";
	cout << out.str() << endl;
	out.str(t);
	cout << out.str() << endl;
	istringstream in(out.str());
	in >> c;
	cout << "c= " << c << endl;
*/

#include "code.h"

//------------------------------------------------------------------------------

string read_file(const string& filename)
{
	string line;
	char ch;
	ifstream ist(filename.c_str());
	if (!ist) error("Don`t read this filename:",filename);
	while (true) {
		ist.get(ch);
		if (ist.eof()) break;
		line += ch;
	}
	return line;
}

//------------------------------------------------------------------------------

void print(string& v)
{
	cout << "SOURCE:\n";
	for (int i=0; i<v.size(); i++)
		cout << v[i];
	cout << "\nAFTER PROCESSING:\n";
	for (int i=0; i<v.size(); i++)
		if (!ispunct(v[i]))
			cout << v[i];
		else if (v[i] == '\n')
			cout << endl;
	cout << endl;
}

//------------------------------------------------------------------------------


int main()
try {
	cout << "Input filename:\n";
	string filename;
	cin >> filename;
	string r = read_file(filename);
	print(r);
    return 0;
}
catch (exception& e) {
    cerr << e.what() << endl;
    return 1;
}
catch (...) {
    cerr << "Oops... exception...\n";
    return 2;
}

