/* 
 * Chapter 18. Exercises 8.
 * Rewrite all the functions in §18.7 to use the approach of making a backward
 * copy of the string and then comparing; for example, take "home", generate
 * "emoh", and compare those two strings to see that they are different, so
 * home isn’t a palindrome.
 */

#include "code.h"

using namespace std;

bool is_palindrome(const string& s)
{
    string b_s(s);  //pseudo backward copy
    for (int i=0; i<s.size(); i++)
        if ( b_s[b_s.size()-1-i] != s[i] )
            return false;
    return true;
}

bool is_palindrome(const char s[], int n)
{
    char b[n];
    for (int i=0; i<n; i++)
        b[n-1-i] = s[i];
    for (int i=0; i<n; i++)
        if (b[i] != s[i])
            return false;
    return true;
}

bool is_palindrome(const char* first, const char* last)
{
    if (first != last) {
        if (*first!=*last)
            return false;
        return is_palindrome(first+1,last-1);
    }
    return true;
}

int main()
{
    cout << "Chapter 18. Exercise 8.\n";
    string sss = "homoh";
    cout << "is_palindrome(sss)" << endl;
    if (is_palindrome(sss))
        cout << "Yes, " << sss << " is a palindrome!\n";
    else
        cout << "No, " << sss << " is`t a palindrome :(\n";
    sss = "one eno";
    cout << "is_palindrome(sss.c_str(),sss.size()))" << endl;
    if (is_palindrome(sss.c_str(),sss.size()))
        cout << "Yes, " << sss << " is a palindrome!\n";
    else
        cout << "No, " << sss << " is`t a palindrome :(\n";
    sss = "oneino";
    cout << "is_palindrome(sss.c_str(),&sss.c_str()[sss.size()-1])" << endl;
    if (is_palindrome(sss.c_str(),&sss.c_str()[sss.size()-1]))
        cout << "Yes, " << sss << " is a palindrome!\n";
    else
        cout << "No, " << sss << " is`t a palindrome :(\n";

    return 0;
}
