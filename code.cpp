/* 
 * Chapter 19. Exercise 2.
 * Write a template function that takes a vector<T> vt and a vector<U> vu as
 * arguments and returns the sum of allvt[i]*vu[i]s.
 */

#include "std_lib_facilities.h"
#include "code.h"

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
// Overload output
ostream& operator<<(ostream& os, const Type1& t)
{
    os << "a(" << t.a << "), b(" << t.b << ")";
    return os;
}

//------------------------------------------------------------------------------
// Overload a + b
Type1 Type1::operator+(const Type1& rt)
{
    *this += rt;
    return *this;
}

//------------------------------------------------------------------------------
// Overload Type1 * T, NOTE: special no T * Type1
template<typename T>
double operator*(Type1& l, const T& r)
{
    return l.a*r;
}

//------------------------------------------------------------------------------
// Overload T + Type1
template<typename T>
double operator+(T& l, const Type1& r)
{
    return l + r.a;
}

//------------------------------------------------------------------------------
int main()
{
    //Exercise 1.
    cout << "Exercise 1:\n";
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

    f(v1,v2);

    cout << "f(v1,v2);\n";
    for (int i=0; i<v1.size(); i++)
        cout << v1[i] << "\t";
    cout << endl;

    //Exercise 2.
    cout << endl << "Exercise 2:\n";
    vector<double> vd(7);
    for (int i=0; i<vd.size(); i++)
        vd[i] = i;
    vector<int> vi(4);
    for (int i=0; i<vi.size(); i++)
        vi[i] = 2;

    cout << "mul(vd,vi): " << mul(vd,vi) << endl;       // OK
    cout << "mul(v1,vd): " << mul(v1,vd) << endl;       // OK
    //cout << "sum: " << mul(vd,v1) << endl;    //<-- error because no 'operator* (T&, const Type1&)'

    return 0;
}


//------------------------------------------------------------------------------
