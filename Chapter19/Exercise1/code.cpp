/* 
 * Chapter 19. Exercise 1.
 * Write a template function f() that adds the elements of one vector<T> to the
 * elements of another; for example, f(v1,v2)should do v1[i]+=v2[i] for each
 * element of v1.
 */

#include "std_lib_facilities.h"
#include "code.h"

//------------------------------------------------------------------------------
template<typename T>
void f(vector<T>& v1, const vector<T>& v2)
{
    if (v1.size() <= v2.size())
        for (int i=0; i<v1.size(); i++)
            v1[i] += v2[i];
    else
        for (int i=0; i<v2.size(); i++)
            v1[i] += v2[i];
}

//------------------------------------------------------------------------------
// Overload output
ostream& operator<<(ostream& os, const Type1& t)
{
    os << "a(" << t.a << "), b(" << t.b << ")";
    return os;
}

//------------------------------------------------------------------------------
int main()
{
    //initialisation
    vector<Type1> v1(3);
    vector<Type1> v2(5);
    for (int i=0; i<v1.size(); i++) {
        v1[i].a = i;
        v1[i].b = i - 0.1;
    }
    for (int i=0; i<v2.size(); i++) {
        v2[i].a = i;
        v2[i].b = i - 0.1;
    }

    //calculate
    f(v1,v2);

    //output
    for (int i=0; i<v1.size(); i++)
        cout << v1[i] << "\t";
    cout << endl;
    for (int i=0; i<v2.size(); i++)
        cout << v2[i] << "\t";
    cout << endl;

    return 0;
}

//------------------------------------------------------------------------------
