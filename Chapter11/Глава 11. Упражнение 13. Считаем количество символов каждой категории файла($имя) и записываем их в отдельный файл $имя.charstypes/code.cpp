//
//	Глава 11. Упражнение 13. Считаем количество символов каждой категории и
//	записываем их в отдельный файл $имя.charstypes.
//

#include "code.h"

//------------------------------------------------------------------------------
struct charstypes {
	charstypes(): whitespace(0), alpha_upper(0), alpha_lower(0), digit(0),
	cntrl(0), other(0), chars_count(0) {}
	int	whitespace;	//разделитель
	int	alpha_upper;//буква в верхнем рекистре
	int	alpha_lower;//буква в нижнем рекистре
	int digit;		//цифра
	int cntrl;		//Управляющий символ (ASCII 0..31 и 127)
	int other;		//Просто какой то символ, не попавший в выше перечисл-е
	int chars_count;//All chars count.
};

//------------------------------------------------------------------------------

string read_file(const string& filename)
{
	string line;
	ifstream ist(filename.c_str());
	if (!ist) error("Don`t read this filename:",filename);
	char ch;
	while (ist.get(ch)) {
		line += ch;
		if (ist.eof()) break;
	}
	return line;
}

//------------------------------------------------------------------------------

charstypes computing(const string& v)
{
	int i;
	charstypes chars;
	chars.chars_count = v.size();
	for (i=0; i<v.size(); i++) {
		if (isspace(v[i])) chars.whitespace++;
		if (isalpha(v[i])) {
			if (isupper(v[i])) chars.alpha_upper++;
			else chars.alpha_lower++;
		}
		if (isdigit(v[i])) chars.digit++;
		if (iscntrl(v[i])) chars.cntrl++;
		if (ispunct(v[i])) chars.other++;
	}
	chars.chars_count = i;
	return chars;
}

//------------------------------------------------------------------------------

void write_file(const string& filename, const charstypes& chars)
{
	ostringstream out;
	out << "Файл "+filename+" содержит " << chars.chars_count << " сиволов, из которых:\n";
	out << chars.whitespace << " - разделителей,\n";
	out << chars.alpha_upper  << " - букв в верхнем регистре,\n";
	out << chars.alpha_lower  << " - букв в нижнем регистре,\n";
	out << chars.digit << " - цифр,\n";
	out << chars.cntrl << " - управляющих символов (ASCII 0..31 и 127),\n";
	out << chars.other << " - символов не попавший в выше перечисленные.\n";
	cout << out.str();
	ofstream f(filename+".chatstypes");
	if (!f) error("Don`t read this file: "+filename+".chatstypes");
	f << out.str();
}
//------------------------------------------------------------------------------

int main()
try {
	cout << "Input filename:\n";
	string filename;
	cin >> filename;
	string l = read_file(filename);
	charstypes chars = computing(l);
	write_file(filename,chars);
    return 0;
}
catch (...) {
    cerr << "Oops... exception...\n";
    return 1;
}

