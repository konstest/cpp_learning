//
//	Глава 11. Упражнение 3. Использование showbase и 
//	cin.unsetf(ios::dec|ios::oct|ios::hex).
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

vector<string> read()
{
	string word;
	vector<string> k;
	cin >> word;
	while (!cin.eof()) {
		k.push_back(word);
		cin >> word;
	}
	return k;
}

//------------------------------------------------------------------------------

void print(const vector<string>& v)
{
	for (int i=0; i<v.size(); i++)
		cout << v[i] << endl;
}

//------------------------------------------------------------------------------

void translate(const vector<string>& v)
{
	for (int i=0; i<v.size(); i++)
		if (v[i][0] == '0' ) {
			if (v[i][1] == 'x')
				output(" шестнадцатиричное ", v[i]);
			else
				output(" восьмиричное ", v[i]);
		} else
			output(" десятиричное ", v[i]);
}
//------------------------------------------------------------------------------

void output(const string& str, const string& elem)
{
	istringstream istr(elem);
	int num;
	istr.unsetf(ios::dec|ios::oct|ios::hex);
	istr >> num;
	if (!istr.fail())
		cout << dec << num << str << dec << elem << endl;
	else
		cout << elem << " не являяется числом!\n";
}
//------------------------------------------------------------------------------

int main()
try {
	cout << "Input number (ex: 123 0123 0x1f) [ENTER & CTRL+D]:\n";
	vector<string> r = read();
	translate(r);
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

