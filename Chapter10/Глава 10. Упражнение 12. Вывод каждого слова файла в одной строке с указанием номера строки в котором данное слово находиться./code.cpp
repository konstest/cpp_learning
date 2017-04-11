//
//	Глава 10. Упражнение 12. Вывод каждого слова файла в одной строке с указанием
//	номера строки в котором данное слово находиться.
//

#include "code.h"

//------------------------------------------------------------------------------

void print_words(int str_number, const string& str)
{
	string word;
	for (int i=0; i<str.size(); i++)
		if (!(str[i]==' ' || str[i]=='\n' || str[i]=='\t' || str[i]=='\r'))
			word += str[i];
		else {
			if (word!="")
				cout << str_number << ": " << word << endl;
			word = "";
		}
	if (word!="")
		cout << str_number << ": " << word << endl;
}

//------------------------------------------------------------------------------

void read_file(const string& filename)
{
	ifstream ist(filename.c_str());
	if (!ist) error ("Don`t read this file: "+filename);
	string str;
	int i = 1;
	while (true) {
		getline(ist,str);
		if (ist.eof()) break;
		print_words(i,str);
		i++;
	}
}

//------------------------------------------------------------------------------

int main()
try {
	cout << "Input filename: ";
	string filename;
	cin >> filename;
	read_file(filename);
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

