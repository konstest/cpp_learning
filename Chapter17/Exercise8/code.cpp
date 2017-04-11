/* 
 * Chapter 17 Exercises 8 
 * Do exercise 7 again, but this time read into a std::string rather than to
 * memory you put on the free store (string know show to use the free store for
 * you).
 * c++ -o code code.cpp -std=c++11 && ./code
 */
#include <iostream> 

using namespace std;

string* read_cin(string* str)
{
    char ch;
    cout << "\tInput characters:\n";
    while(cin.get(ch)) {
        if (ch == '!') break;
        str->push_back(ch);
    }
    return str;
}

void print_all(string* s)
{
    cout << "PRINT ALL characters:\n" << *s << endl;
}

int main() 
{ 
    string str;
    print_all(read_cin(&str));
    return 0;
}
