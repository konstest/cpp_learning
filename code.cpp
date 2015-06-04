//
//	Глава 11. Упражнение 15. Форматированный вывод считанных чисел и их количества
//

#include "code.h"

const int N = 12;
//------------------------------------------------------------------------------

vector<int> read_file(const string& filename)
{
	int num;
	vector<int> k;
	ifstream ist(filename.c_str());
	if (!ist) error("Don`t read this filename:",filename);
	while (ist >> num) {
		k.push_back(num);
		if (ist.eof()) break;
	}
	return k;
}

//------------------------------------------------------------------------------

void output(const vector<int> v)
{
	ostringstream out;
	int k = 0;
	out << setw(N) << "Numbers:" << setw(N) << "counts:";
	out << endl << setw(N) << v[0];
	for (int i=1; i<v.size(); i++)
		if (v[i]!=v[i-1]) {
			if (k>0) out << setw(N) << k+1;
			k = 0;
			out << endl << setw(N) << v[i];
		} else
			k++;	//дубликат
	cout << out.str() << endl;
}

//------------------------------------------------------------------------------

int main()
try {
	cout << "Input filename:\n";
	string filename;
	cin >> filename;
	vector<int> l = read_file(filename);
	sort(l.begin(),l.end());
	output(l);
    return 0;
}
catch (...) {
    cerr << "Oops... exception...\n";
    return 1;
}

