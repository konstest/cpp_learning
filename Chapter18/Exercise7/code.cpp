/* 
 * Chapter 18. Exercises 1,2,3.
 * 7.
 * Write versions of the cat_dot()s from the previous exercises to take C-style
 * strings as arguments and return a free-store-allocated C-style string as the
 * result. Do not use standard library functions or types in the
 * implementation. Test thesefunctions with several strings. Be sure to free
 * (using delete) all the memory you allocated from free store (using
 * new).Compare the effort involved in this exercise with the effort involved
 * for exercises 5 and 6.
 */

#include "code.h"

using namespace std;

string* cat_dot(const string& s1, const string& sep, const string& s2)
{
    return new string{s1+sep+s2};
}

int main()
{
    cout << "Chapter 18. Exercise 7.\n";
    string s1 = "Genri", s2 = "Ford";
    string* sss = cat_dot(s1," ",s2);
    cout << *sss << endl;
    delete sss;

    return 0;
}
