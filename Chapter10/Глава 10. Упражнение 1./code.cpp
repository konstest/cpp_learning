//
//	Глава 10. Упражнение 1.
//

#include "code.h"

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

int main()
try
{
	int num=0,sum=0;
	string filename;
	cout << "Input file name please: ";
	cin >> filename;
	ifstream file(filename.c_str());
	if (!file) error ("Don`t read this file: "+filename);
	while (!file.eof()) {
		file >> num;
		sum += num;
	}
	cout << "The amount of numbers read from the file is: " << sum << endl;
	return 0;
}
/*catch (asdasd::Invalid&) {
    cerr << "error: Invalid!!!\n"; 
    return 1;
}*/
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
