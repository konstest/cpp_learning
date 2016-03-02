/* 
 * Chapter 17 Exercises 1-5
 * c++ -o code code.cpp -std=c++11
 */
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void to_lower(char* s)
{
    int i=0;
    while (s[i] != '\0') {
        if (64 < int(s[i]) && int(s[i]) < 96)
            s[i] = s[i] + 32;    
        i++;
    }
}

void print_str(char* s)
{
    for (int i=0; s[i]!='\0'; i++)
        cout << s[i];
    cout << endl;
}

char* strdup(const char* s)
{
    int i = 0; 
    while ( s[i] != '\0' )
        i++;
    char* ss = new char[i+1];
    for (i=0; s[i] != '\0'; i++)
        ss[i] = s[i];
    ss[i] = '\0';
    return ss;
}

char* findx(const char* s, const char* x)
{
    int s_i=0,x_i=0;
    bool find = false;
    while (s[s_i]!='\0') {
        if (s[s_i] == x[x_i]) {
            x_i++;
            if (x[x_i]=='\0') {
                find = true;
                break;
            }
        }
        else
            x_i = 0;
        s_i++;
    }

    if (!find) return nullptr;      //return if nothing found 

    // back to top word
    while (s_i > 0 and s[s_i] != ' ')
        s_i--;
    if (s[s_i] == ' ') s_i++; 

    // and counting characters of the word
    int i=s_i, count=0;
    while (s[i]!='\0' and s[i]!=' ') {
        i++;
        count++;
    }

    // initializing space for the found word 
    char* f = new char[count];
    for (i=0; i<count; i++, s_i++)
        f[i] = s[s_i];
    f[i] = '\0';
    return f;
}

int main ()
{
    /*
     * Exercise 1.
     */
    cout << "Exercise 1:\n";
    double* p = new double(1.2);
    cout << "p= " << p << endl; 
    cout << "*p= " << *p << endl; 

    /*
     * Exercise 2.
     */
    cout << "\nExercise 2:\n";
    cout << "sizeof(int): " << sizeof(int) << endl;
    cout << "sizeof(double): " << sizeof(double) << endl;
    cout << "sizeof(bool): " << sizeof(bool) << endl;

    /*
     * Exercise 3.
     */
    cout << "\nExercise 3:\n";
    char S[] = "HeLlow wOrLd!";
    char* ss = S;
    print_str(ss);
    to_lower(ss);
    print_str(ss);

    /*
     * Exercise 4.
     */
    cout << "\nExercise 4:\n";
    char* new_ss = strdup(ss);
    print_str(new_ss);
    delete[] new_ss;

    /*
     * Exercise 5.
     */
    cout << "\nExercise 5:\n";
    char y[] = "low adfasd asd as d sasd asd sdsss!";
    char x[] = "asd";
    char* f = findx(y,x);
    print_str(f);
    delete[] f;

    return 0;
}
