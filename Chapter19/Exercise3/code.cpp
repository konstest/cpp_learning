/* 
 * Chapter 19. Exercise 3.
 * Write a template class Pair that can hold a pair of values of any type. Use
 * this to implement a simple symbol table likethe one we used in the
 * calculator (§7.8).
 */

#include "std_lib_facilities.h"
#include "code.h"

//------------------------------------------------------------------------------
//  Overloading output for Pair
template<typename A, typename B>
ostream& operator<<(ostream& os, const Pair<A,B>& p) 
{
    os << p.v1 << ":\t" << p.v2;
    return os;
}

//------------------------------------------------------------------------------
// Overload output for Type
ostream& operator<<(ostream& os, const Type& t)
{
    os << "a(" << t.a << "), b(" << t.b << ")";
    return os;
}
 
//------------------------------------------------------------------------------
int main()
{
    vector<Pair<string,double>> table;

    Pair<string,double> pi("pi",3.1415926535);
    table.push_back(pi);
    Pair<string,double> e("e",2.7182818284);
    table.push_back(e);
    
    for (int i=0; i<table.size(); i++)
        cout << table[i] << endl;

    Pair<string,Type> test0("Type0",Type());
    test0.v2.a = 5;
    test0.v2.b = 7.3;
    vector<Pair<string,Type>> table2;
    table2.push_back(test0);
    Pair<string,Type> test1("Type1",Type(123,9.0001));
    table2.push_back(test1);

    for (int i=0; i<table2.size(); i++)
        cout << table2[i] << endl;

    return 0;
}

//------------------------------------------------------------------------------
