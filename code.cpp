// c++ -o code code.cpp -std=c++11
//
// Глава 8. Упражение 2.
//
#include "iostream"
#include "vector"
#include "string"

using namespace std;

void print(const string& comment, const vector<int>& v)
{
	for (int i=0; i<v.size(); i++) {
		cout << comment << v[i] << endl;
	}
}

int main ()
{
	vector<int> d(10,10);
	string comment = "> ";
	print(comment,d);
}

