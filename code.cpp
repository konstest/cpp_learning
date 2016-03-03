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

char* read_cin()
{
    char ch;
    int k = 0, i = 0;
    char* ptr = new char;
    cout << "\tInput characters:\n";
    while(cin.get(ch)) {
        if (ch == '!') {
            ptr[k] = '\0';
            break;
        }
        k++;
        char* tmp_ptr = new char[k];
        for (i=0; i<k-1; i++)
            tmp_ptr[i] = ptr[i];
        tmp_ptr[i] = ch;
        delete[] ptr;
        ptr = tmp_ptr;
    }
    return ptr;
}

void print_all(const char* s)
{
    cout << "\tPRINT ALL characters:\n";
    for(int i=0; s[i] != '\0'; i++)
        cout << s[i];
    cout << endl;
}

int main() 
{ 
    char* p = read_cin();
    print_all(p);
    return 0;
}
