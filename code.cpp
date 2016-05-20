/* 
 * Chapter 19. Exercise 7.
 * Try your solution to exercise 2 with some Numbers.
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

//------------------------------------------------------------------------------
template<typename T>
void f(vector<T>& v1, const vector<T>& v2)
{
    if (v1.size() <= v2.size())
        for (int i=0; i<v1.size(); i++)
            v1[i] = v1[i] + v2[i];
    else
        for (int i=0; i<v2.size(); i++)
            v1[i] += v2[i];
}

//------------------------------------------------------------------------------
template<typename T, typename U>
double mul(vector<T> vt, vector<U> vu)
{
    int i = 0;
    double sum_mul = 0;
    if (vt.size() <= vu.size()) {
        for (i=0; i<vt.size(); i++) {
//            cout << sum_mul << " + " << vt[i] << " * " << vu[i] << endl;
            sum_mul = sum_mul + (vt[i] * vu[i]);
        }
        for (;i < vu.size(); i++)
            sum_mul = sum_mul + vu[i];
    }
    else {
        for (i=0; i<vu.size(); i++)
            sum_mul = sum_mul + (vt[i] * vu[i]);
        for (;i < vt.size(); i++)
            sum_mul = sum_mul + vt[i];
    }
    return sum_mul;
}

//------------------------------------------------------------------------------
int main()
{
    try {
        cout << "Chapter 19. Exercise 7.\n";
        vector<Number<double>> vd(3);
        for (int i=0; i<vd.size(); i++)
            vd[i] = 1;
        vector<Number<int>> vi(5);
        for (int i=0; i<vi.size(); i++)
            vi[i] = 2;

        cout << "mul(vd,vi): " << mul(vd,vi) << endl;       // OK

        return 0;
    }
    catch (...) {
        cerr << "Error occurred :(\n";
        return 1;
    }
}

