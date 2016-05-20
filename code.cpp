/* 
 * Chapter 19. Exercise 6.
 * Repeat the previous exercise, but with a class Number<T> where T can be any
 * numeric type. Try adding % toNumber and see what happens when you try to use
 * % for Number<double> and Number<int>.
 * clear; g++ -o code code.cpp -std=c++0x && ./code
 */

#include <iostream> 
#include "code.h"

using namespace std;

//-----------------------------------------------------------------------------
// overload output
template<typename T> istream& operator>>(istream& is, Number<T>& t)
{
    is >> t.set();
    return is;
}

//-----------------------------------------------------------------------------
int main() 
{ 
    try {
        cout << "Chapter 19. Exercise 6.\n";
        Number<double> ob = 4.7;
        ob = 5.3 + ob;
        ob = (ob/2)*3;
        ob = ob % 2;
        Number<double> eb = 2;
        ob = ob % eb;
        eb %= ob;
        ob = (ob*7)/2+eb;
        cout << "ob= " << ob << endl;
        cout << "eb= " << eb << endl;
        return 0;
    }
    catch (...) {
        cerr << "Error occurred :(\n";
        return 1;
    }
}
//-----------------------------------------------------------------------------
