/* 
 * Chapter 17 Exercises 10 
 * Look at your solution of exercise 7. Is there any way that input could get
 * the array to overflow; that is, is there any way you could enter more
 * characters than you allocated space for (a serious error)? Does anything
 * reasonable happen if you try to enter more characters than you allocated?
 * Answers:
 *      Array overflow: input a characters of escape
 *          sequence(ctrl+1/2/3/4/etc, arrow down/up/left/right).
 *      When is we enter more characters than is allocated is nothing happen.
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
