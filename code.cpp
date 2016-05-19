/* 
 * Chapter 19. Exercise 5.
 * Define a class Int having a single member of class int. Define constructors,
 * assignment, and operators +, -, *, / for it.Test it, and improve its design
 * as needed (e.g., define operators << and >> for convenient I/O).
 * clear; g++ -o code code.cpp -std=c++0x && ./code
 */

#include <iostream> 
#include "code.h"

using namespace std;

//-----------------------------------------------------------------------------
//  Overload math operators
Int& Int::operator-=(const Int& rhs)
{
    i -= rhs.get();
    return *this;
}

Int& Int::operator+=(const Int& rhs)
{
    i += rhs.get();
    return *this;
}

Int& Int::operator*=(const Int& rhs)
{
    i *= rhs.get();
    return *this;
}

Int& Int::operator/=(const Int& rhs)
{
    i /= rhs.get();
    return *this;
}

Int operator-(Int lhs, const Int& rhs)
{
    return lhs -= rhs;
}

Int operator+(Int lhs, const Int& rhs)
{
    return lhs += rhs;
}

Int operator*(Int lhs, const Int& rhs)
{
    return lhs *= rhs;
}

Int operator/(Int lhs, const Int& rhs)
{
    return lhs /= rhs;
}

// overload output
istream& operator>>(istream& is, Int& t)
{
    is >> t.set();
    return is;
}

//-----------------------------------------------------------------------------
int main() 
{ 
    try {
        Int h;
        cout << "Input Int h: ";
        cin >> h;
        cout << "h = h / 3.2;\n";
        h = h / 3.2;
        cout << h << endl;
        return 0;
    }
    catch (...) {
        cerr << "Error occurred :(\n";
        return 1;
    }
}
//-----------------------------------------------------------------------------
