/* 
 * Chapter 17 Exercises 7 
 * Write a program that reads characters from cin into an array that you
 * allocate on the free store. Read individual characters until an exclamation
 * mark (!) is entered. Do not use a std::string. Do not worry about memory
 * exhaustion.
 * c++ -o code code.cpp -std=c++11 && ./code
 */
#include <iostream> 

using namespace std;

string* read_cin()
{
    char ch;
    string* str;
    cout << "\tInput characters:\n";
    while(cin.get(ch)) {
        if (ch == '!') break;
        *str->push_back(ch);
    }
    return str;
}

void print_all(string* s)
{
    cout << s << endl;
}

int main() 
{ 
    string* p = read_cin();
    print_all(p);
    return 0;
}
