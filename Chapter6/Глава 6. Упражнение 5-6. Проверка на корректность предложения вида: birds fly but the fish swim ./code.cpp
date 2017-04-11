/*
	Глава 6. Упражнение 5 - 6. Проверка на корректность предложения вида:
	birds fly but the fish swim . 
	c++ -o code code.cpp -std=c++98

	Предложение:
		существительное глагол
		артикуль существительное глагол
		предложение союз предложение

	Существительное:
		birds
		fish
		dogs
		cats

	Глагол:
		run
		fly
		swim
		sleep

	Артикль:
		the
	
	Союз:
		and
		but
*/
#include <iostream>
#include <vector>
#include <string>         // std::string
#include <locale>         // std::locale, std::toupper
#include <stdexcept>

using namespace std;

inline void error(const string& errormessage)
{
    cerr << errormessage << endl;
    throw runtime_error(errormessage);
}

//------------------------------------------------------------------------------
class grammatics {
public:
	vector<string> nouns;
	vector<string> verbs;
	vector<string> unions;
	vector<string> artikels;
};

//------------------------------------------------------------------------------
//	Определяем принадлежность данного слова(WORD) к словам из граматики.
char finding(string word, grammatics T)
{
	string str = word;									//
	locale loc;											// переводим слово
	for (string::size_type i=0; i<str.length(); ++i)	// в нижний регистр
    	str[i] = tolower(str[i],loc);					//

	for (int i = 0; i < T.nouns.size(); i++)
		if (T.nouns[i] == str) return 'n';
	for (int i = 0; i < T.verbs.size(); i++)
		if (T.verbs[i] == str) return 'v';
	for (int i = 0; i < T.unions.size(); i++)
		if (T.unions[i] == str) return 'u';
	for (int i = 0; i < T.artikels.size(); i++)
		if (T.artikels[i] == str) return 'a';
	if (word == ".")
		return '.';

	return 'f';
}

//------------------------------------------------------------------------------
bool theorem (vector<string>::iterator p, grammatics T)
{
	bool k = true;
	switch ( finding(*p,T) )
		{
		case 'n':
			if ( finding(*(p+1),T) == 'v' )
				k = theorem(p+=2,T);
			else
				return false;
			break;
		case 'a':
		case 'u':
			k = theorem(++p,T);
			break;
		case '.':
			return true;
			break;
		default:
			return false;
		}

	return k;
}
//------------------------------------------------------------------------------

int main ()
try
{
	grammatics T;
	// имена существительные
	T.nouns.push_back("birds");
	T.nouns.push_back("fish");
	T.nouns.push_back("dogs");
	T.nouns.push_back("cats");
	// глаголы
	T.verbs.push_back("run");
	T.verbs.push_back("fly");
	T.verbs.push_back("swim");
	T.verbs.push_back("sleep");
	//союзы
	T.unions.push_back("and");
	T.unions.push_back("but");
	//артикль
	T.artikels.push_back("the");

	//INPUT сперва читаем всё предложение в вектор слов
	vector<string> words;
	string word;
	cin >> word;
	while (word != ".")
		{
		if ( finding(word,T) != 'f')
			{
			words.push_back(word);
			cin >> word;
			}
		else
			error ("I don`t know a this word: "+word);
		}
	words.push_back(word);	// ложим точку как конец

	//COMPUTING
	vector<string>::iterator p;
	p = words.begin();

	if ( theorem(p,T) )
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}
catch (exception& e) {
    cerr << "Expecting error: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}

