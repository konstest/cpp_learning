//
//	Глава 10. Упражнение 11. Вычисление суммы целлых чисел записанных в файле и
//	разделённых пробелами. Вида:
//	2 sdfsdf sdf  2 34

#include "code.h"

//------------------------------------------------------------------------------

bool is_int(const string& str)
{
	for (int i=0; i<str.size(); i++) {
		if (!isdigit(str[i])) return false;
	}
	return true;
}

//------------------------------------------------------------------------------

int read_file(const string& filename)
{
	int sum=0;
	ifstream ist(filename.c_str());
	if (!ist) error ("Don`t read this file: "+filename);
	string str;
	while (true) {
		ist >> str;
		if (ist.eof()) break;
		if (is_int(str)) {
			sum += atoi(str.c_str());
			cout << str << endl;
		}
	}
	return sum;
}

//------------------------------------------------------------------------------

int main()
try {
	cout << "Input filename: ";
	string filename;
	cin >> filename;
	cout << "Numbers summ is = " << read_file(filename) << endl;
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

