//
//	Глава 11. Упражнение 2. Удаляем из файла все гласные буквы.
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
//Читает файл в вектор
vector<string> read_file(const string& filename)
{
	ifstream ifile(filename.c_str());
	if (!ifile) error("Don`t read this file: ",filename);
	vector<string> v;
	string line;
	while (!ifile.eof())
		if (getline(ifile,line)) v.push_back(line);
	return v;
}

//------------------------------------------------------------------------------

void print(const vector<string>& v)
{
	for (int i=0; i<v.size(); i++)
		cout << v[i] << endl;
}

//------------------------------------------------------------------------------

void write_file(const vector<string>& v, const string& filename)
{
	ofstream ofile(filename.c_str());
	if (!ofile) error("Don`t write this file: ",filename);
	for (int i=0; i<v.size(); i++)
		ofile << v[i] << endl;
}

//------------------------------------------------------------------------------

bool is_vowel(char ch)
{
	char vowels[] = {'e','y','u','i','o','a'};
	for (int i=0; i<6; i++)
		if (ch == vowels[i] || ch == toupper(vowels[i]) ) return true;
	return false;
}
//------------------------------------------------------------------------------

void processing(vector<string>& v)
{
	string str;
	vector<string> k;
	for (int i=0; i<v.size(); i++) {
		str = "";
		for (int j=0; j<v[i].size(); j++)
			if (!is_vowel(v[i][j])) str += v[i][j];
		if (str!="") k.push_back(str);
	}
	v = k;
}
//------------------------------------------------------------------------------

int main()
try {
	string filename;
	cout << "Input filename please: ";
	cin >> filename;
	vector<string> r = read_file(filename);
	processing(r);
	print(r);
	write_file(r,filename);
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

