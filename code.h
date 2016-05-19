/* 
 * Заглолвочный файл
 */

#include "std_lib_facilities.h"
#include <list>

class Int {
    private:
        int i;
    public:
        Int(): i(0) {}
        Int(int k): i(k) {}
        int     get() const { return i; }
        void    set(int k) { i = k; }
        int&    set() { return i; }
        Int&    operator+=(const Int&);
        Int&    operator-=(const Int&);
        Int&    operator*=(const Int&);
        Int&    operator/=(const Int&);
};

Int operator+(Int lhs, const Int& rhs);
Int operator-(Int lhs, const Int& rhs);
Int operator*(Int lhs, const Int& rhs);
Int operator/(Int lhs, const Int& rhs);
ostream& operator<<(ostream& os, const Int& t) { return os << t.get(); }
istream& operator>>(istream& is, Int& t);



struct Type1 {
    int a;
    double b;
    Type1(): a(0), b(0.0) { }
    Type1& operator+=(const Type1& t) {
        this->a += t.a;
        this->b += t.b;
        return *this;
    }
    Type1 operator+(const Type1& rt);
};

template<typename T>
double operator+(T& l, const Type1& r);             //for excercise 2.

template<typename T>
double operator*(Type1& l, const T& r);             //for excercise 2.

ostream& operator<<(ostream& os, const Type1& t);   //overload output

template<typename T>
void f(vector<T>& v1, const vector<T>& v2);         //for excercise 1.

template<typename T, typename U>
double mul(vector<T> vt, vector<U> vu);             //for excercise 2.

