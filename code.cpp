/* 
 * Chapter 18. Exercises 1,2,3.
 * 5.
 */

#include "code.h"

using namespace std;

string cat_dot(const string& s1, const string& s2)
{
    return s1+"."+s2;
}

int main()
{
    cout << "Chapter 18. Exercise 5.\n" << endl;
    string s1 = "Genri", s2 = "Ford";
    cout << cat_dot(s1,s2) << endl;

    return 0;
}
