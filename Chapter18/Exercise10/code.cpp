/* 
 * Chapter 18. Exercise 10 (both options).
 * Look at the “array solution” to the palindrome problem in §18.7.2. Fix it
 * to deal with long strings by (a) reporting if an input string was too long
 * and (b) allowing an arbitrarily long string. Comment on the complexity of 
 * the two versions.
 */

//
// This is example code from Chapter 18.6.2 "Palindromes using arrays" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int strlen(const char* s)
{
    int i=0;
    while(*s) {
        s++;
        i++;
    }
    return i;
}

//------------------------------------------------------------------------------

bool is_palindrome(const char s[], int n)
// s points to the first character of an array of n characters
{
    int first = 0;         // index of first letter
    int last = n-1;        // index of last letter
    while (first < last) { // we haven't reached the middle
        if (s[first]!=s[last]) return false;
        ++first;           // move forward
        --last;            // move backwards
    }
    return true;
}

//------------------------------------------------------------------------------

istream& read_word(istream& is, char* buffer, int max)
// read all characters from std input and warn if the nummber of characters count 
// is more that value 'max'
{
    int count=0;
    char ch = 0;
    while (is.get(ch)) {
        if (ch == '\n') {
            *buffer = '\0';
            break;
        }
        *buffer = ch;
        buffer++;
        count++;
    }
    if ( count > max )
        cout << "input string was too long :(\n";
    return is;
}

//------------------------------------------------------------------------------

int main()
{
    const int max = 128;
    char s[max];
    while (read_word(cin,s,max) ) { 
        if (*s) {
            cout << "<- it is";
            if (!is_palindrome(s,strlen(s))) cout << " not";
            cout << " a palindrome\n";
        }
    }
}

//------------------------------------------------------------------------------
