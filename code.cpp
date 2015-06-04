//
//	Глава 11. Упражнение 14. Форматированный вывод setw(n), scientific,
//	etprecision(n) и т.д.
//

#include "code.h"

//------------------------------------------------------------------------------

vector<double> read_file(const string& filename)
{
	double num;
	vector<double> k;
	ifstream ist(filename.c_str());
	if (!ist) error("Don`t read this filename:",filename);
	while (ist >> num) {
		k.push_back(num);
		if (ist.eof()) break;
	}
	return k;
}

//------------------------------------------------------------------------------

void output(const vector<double> v)
{
	ostringstream out;
	out << scientific << setprecision(1);
	for (int i=0; i<v.size(); i++) {
		out << setw(8) << v[i];
		if ((i+1)%4==0) out << endl;
	}
	cout << out.str().c_str();
}

//------------------------------------------------------------------------------

int main()
try {
	cout << "Input filename:\n";
	string filename;
	cin >> filename;
	vector<double> l = read_file(filename);
	output(l);
    return 0;
}
catch (...) {
    cerr << "Oops... exception...\n";
    return 1;
}

