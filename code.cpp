//
//	Глава 10. Упражнение 8-9. Конкатенация двух файлов в один и последующее
//	упорядочивание его содержимого.
//

#include "code.h"

//------------------------------------------------------------------------------

vector<string> read_file(string filename, vector<string>& lines)
{
	string line;
	ifstream ist(filename.c_str());
	if (!ist) error ("Don`t read this file: "+filename);
	while (!ist.eof()) {
		ist >> line;
		lines.push_back(line);
	}
	return lines;
}

//------------------------------------------------------------------------------

void write_file (string filename, const vector<string>& lines)
{
	ofstream ost(filename.c_str());
	if (!ost) error ("Don`t open for write this file: "+filename);
	for (int i=0; i<lines.size(); i++)
		ost << lines[i] << endl;
}

//------------------------------------------------------------------------------

void print_file(string filename)
{
	string line;
	ifstream ist(filename.c_str());
	if (!ist) error ("Don`t read this file: "+filename);
	while (!ist.eof()) {
		getline(ist,line);
		cout << line << endl;
	}
}

//------------------------------------------------------------------------------

int main()
try {
	cout << "Input two file names: ";
	string f1, f2;
	cin >> f1 >> f2;
	vector<string> v;
	read_file(f1,v);
	read_file(f2,v);
	sort (v.begin(),v.end());
	cout << "Insert output file name: ";
	string output_file;
	cin >> output_file;
	write_file(output_file,v);
	print_file(output_file);
    return 0;
}
/*catch (exception& e) {
//    cerr << e.what() << endl;
    return 1;
}*/
catch (...) {
    cerr << "Oops... exception...\n";
    return 2;
}

//------------------------------------------------------------------------------
