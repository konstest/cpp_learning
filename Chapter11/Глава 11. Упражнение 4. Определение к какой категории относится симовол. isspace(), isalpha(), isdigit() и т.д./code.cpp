//
//	Глава 11. Упражнение 4. Определение к какой категории относится симовол.
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

vector<string> read_file(const string& filename)
{
	string line;
	vector<string> k;
	ifstream ist(filename.c_str());
	if (!ist) error("Don`t read this filename:",filename);
	while (true) {
		getline(ist,line);
		if (ist.eof()) break;
		k.push_back(line);
	}
	return k;
}

//------------------------------------------------------------------------------

void print(const vector<string>& v)
{
	ostringstream out;
	for (int i=0; i<v.size(); i++) {
		cout << v[i] << ":\n" ;
		for (int j=0; j<v[i].size(); j++) {
			out << v[i][j];
			if (!ispunct(v[i][j])) {
				out << " является ";
				if (isspace(v[i][j])) out << "/разделителем";
				if (isalpha(v[i][j])) {
					out << "/буквой";
					if (isupper(v[i][j])) out << " в верхнем регистре";
					else out << " в нижнем регистре";
				}
				if (isdigit(v[i][j])) out << "/десятичной цифрой";
				if (iscntrl(v[i][j])) out << "/управляющим символом (ASCII 0..31 и 127)";
			} else out << " просто какой то символ.";
			cout << out.str() << endl;
			out.str("");
		}
	}
}

//------------------------------------------------------------------------------


int main()
try {
	cout << "Input filename:\n";
	string filename;
	cin >> filename;
	vector<string> r = read_file(filename);
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

