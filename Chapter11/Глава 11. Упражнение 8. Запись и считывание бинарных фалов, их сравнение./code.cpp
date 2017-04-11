//
//	Глава 11. Упражнение 8. Запись и считывание бинарных фалов, их сравнение.
//

#include "code.h"

using namespace std;

//------------------------------------------------------------------------------

template<class T>
char* as_bytes(T&i) {
	void* addr = &i;
	return static_cast<char*>(addr);
}

//------------------------------------------------------------------------------
/*
//Cpecial for CHARs
void text_to_binary()
{
	string filename;
	cout << "enter the name of a text file: ";
	cin >> filename;
	ifstream t(filename.c_str());
	if (!t) error ("Don`t read this file: "+filename);
	string binfilename = filename+".bin";
	ofstream b(binfilename.c_str(),ios::binary);
	if (!b) error ("Don`t read this file: "+binfilename);
	char ch;
	string line;
	vector<string> v;
	while (true) {
		t.get(ch);
		if (t.eof()) break;
		if (t.fail()) error ("Error reading file: "+filename);
		line += ch;
	}

	for (int j=0; j<line.size(); j++)
		b.write(as_bytes(line[j]),sizeof(char));
}

//------------------------------------------------------------------------------

void binary_to_text()
{
	string filename;
	cout << "enter the name of a binary file: ";
	cin >> filename;
	ifstream b(filename.c_str(), ios::binary);
	if (!b) error ("Don`t read this file: "+filename);
	string txtfilename = filename+".txt";
	ofstream t(txtfilename.c_str());
	if (!t) error ("Don`t read this file: "+txtfilename);
	char ch;
	string line;
	
	while (b.read(as_bytes(ch),sizeof(char)))
		line += ch;

	for (int i=0; i<line.size(); i++)
		t << line[i];
}	
*/

//------------------------------------------------------------------------------
void text_to_binary()
{
	string filename;
	cout << "enter the name of a text file: ";
	cin >> filename;
	ifstream t(filename.c_str());
	if (!t) error ("Don`t read this file: "+filename);
	string binfilename = filename+".bin";
	ofstream b(binfilename.c_str(),ios::binary);
	if (!b) error ("Don`t read this file: "+binfilename);
	int k;
	vector<int> v;
	while (true) {
		t >> k;
		v.push_back(k);
		if (t.eof()) break;
		if (t.fail()) error ("Error reading file: "+filename);
	}

	for (int i=0; i<v.size(); i++)
		b.write(as_bytes(v[i]),sizeof(int));
}

//------------------------------------------------------------------------------

void binary_to_text()
{
	string filename;
	cout << "enter the name of a binary file: ";
	cin >> filename;
	ifstream b(filename.c_str(), ios::binary);
	if (!b) error ("Don`t read this file: "+filename);
	string txtfilename = filename+".txt";
	ofstream t(txtfilename.c_str());
	if (!t) error ("Don`t read this file: "+txtfilename);
	int k;
	vector<int> v;
	
	while (b.read(as_bytes(k),sizeof(int)))
		v.push_back(k);

	for (int i=0; i<v.size(); i++)
		t << v[i] << " ";
}

//------------------------------------------------------------------------------

int main()
try
{
	string str;
	cout << "What a you want?\n \
Converting text[t] file in to binary. Or binary[b] to text: ";
	cin >> str;
	while ( !(str=="t" || str=="b") ) {
		cout << "ERROR! enter [t|b]: ";
		cin >> str;
	}
	if (str == "t")
		text_to_binary();
	else
		binary_to_text();

    return 0;
}
catch (...) {
    cerr << "Oops... exception...\n";
    return 1;
}

