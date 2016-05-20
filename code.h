/* 
 * Заглолвочный файл
 */

#include "std_lib_facilities.h"
#include <list>

template<typename T>
class Number {
    private:
        T i;
    public:
        Number(): i(0) {}
        Number(T k): i(k) {} //If declare this constructor with 'explicit' then will error, becouse don`t to be explicit conversion
        T  get() const { return i; }
        void    set(T k) { i = k; }
        T&    set() { return i; }
        Number&    operator+=(const Number& rhs) { i += rhs.get(); return *this; }
        Number&    operator-=(const Number& rhs) { i -= rhs.get(); return *this; }
        Number&    operator*=(const Number& rhs) { i *= rhs.get(); return *this; }
        Number&    operator/=(const Number& rhs) { i /= rhs.get(); return *this; }
        Number&    operator%=(const Number& r) { i = (int)i%(int)r.get(); return *this; }
};

template<typename T, typename A> Number<T> operator+(Number<T> lhs, const A& rhs) { return lhs += rhs; }
template<typename T, typename A> Number<T> operator+(A lhs, Number<T> rhs) { return lhs += rhs.get(); }
template<typename T, typename A> Number<T> operator+(Number<T> lhs, const Number<A>& rhs) { return lhs.set() += rhs.get(); } 
template<typename T, typename A> Number<T> operator-(Number<T> lhs, const A& rhs) { return lhs -= rhs; } 
template<typename T, typename A> Number<T> operator-(A lhs, Number<T> rhs) { return lhs -= rhs.get(); }
template<typename T, typename A> Number<T> operator-(Number<T> lhs, const Number<A>& rhs) { return lhs.set() -= rhs.get(); } 
template<typename T, typename A> Number<T> operator*(Number<T> lhs, const A& rhs) { return lhs *= rhs; }
template<typename T, typename A> Number<T> operator*(A lhs, Number<T> rhs) { return lhs *= rhs.get(); }
template<typename T, typename A> Number<T> operator*(Number<T> lhs, const Number<A>& rhs) { return lhs.set() *= rhs.get(); } 
template<typename T, typename A> Number<T> operator/(Number<T> lhs, const A& rhs) { return lhs /= rhs; }
template<typename T, typename A> Number<T> operator/(A lhs, Number<T> rhs) { return lhs /= rhs.get(); }
template<typename T, typename A> Number<T> operator/(Number<T> lhs, const Number<A>& rhs) { return lhs.set() /= rhs.get(); } 
template<typename T, typename A> Number<T> operator%(Number<T> lhs, const A& rhs) { return lhs %= rhs; }
template<typename T, typename A> Number<T> operator%(A lhs, Number<T> rhs) { return lhs += (int)rhs.get(); }
template<typename T, typename A> Number<T> operator%(Number<T> lhs, const Number<A>& rhs)
{
    return lhs.set() = (int)lhs.set() % (int)rhs.get();
} 

template<typename T> ostream& operator<<(ostream& os, const Number<T>& t) { return os << t.get(); }
template<typename T> istream& operator>>(istream& is, Number<T>& t);


struct Type1 {
    int a;
    double b;
    Type1(): a(0), b(0.0) { }
    Type1& operator+=(const Type1& t) {
        this->a += t.a;
        this->b += t.b;
        return *this;
    }
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

