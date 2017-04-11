//c++ -o code code.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
bool disliked_test(string word, vector<string> disliked);

int main () {
	vector<string> words;
	vector<string> disliked;
	string word;
	
	disliked.push_back("Broccoli");
	disliked.push_back("Петух");
	disliked.push_back("Bla");
	
	//VVOD
	cout << "Вводите слова, по окончании нажмите ctrl+D:\n";
	while (cin>>word)
		words.push_back(word);
	cout << "Количество слов: " << words.size() <<endl;
	
	sort(words.begin(),words.end());

	//VIVOD
	for (int i=0; i<words.size(); ++i)
		if ( (i==0 || words[i-1]!=words[i]) && disliked_test(words[i],disliked) )
			cout << words[i] << endl;
	return 0;
}

//Проверяем попало ли данное слово в перечень не желательных
bool disliked_test(string word, vector<string> disliked)
{
	for (int i=0; i<disliked.size(); ++i)
		if (word == disliked[i]) return false;
	return true;
}

