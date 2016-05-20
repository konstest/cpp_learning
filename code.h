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
        double  return_to_double() { return i; };
        Number&    operator+=(const Number& rhs) { i += rhs.get(); return *this; }
        Number&    operator-=(const Number& rhs) { i -= rhs.get(); return *this; }
        Number&    operator*=(const Number& rhs) { i *= rhs.get(); return *this; }
        Number&    operator/=(const Number& rhs) { i /= rhs.get(); return *this; }
        Number&    operator%=(const Number& r) { i = (int)i%(int)r.get(); return *this; }
};

template<typename T, typename A> Number<T> operator+(Number<T> lhs, const A& rhs) { return lhs += rhs; }
template<typename T, typename A> A operator+(A lhs, Number<T> rhs) { return lhs += rhs.get(); }
template<typename T, typename A> Number<T> operator+(Number<T> lhs, const Number<A>& rhs) { return lhs.set() += rhs.get(); } 
template<typename T, typename A> Number<T> operator-(Number<T> lhs, const A& rhs) { return lhs -= rhs; } 
template<typename T, typename A> A operator-(A lhs, Number<T> rhs) { return lhs -= rhs.get(); }
template<typename T, typename A> Number<T> operator-(Number<T> lhs, const Number<A>& rhs) { return lhs.set() -= rhs.get(); } 
template<typename T, typename A> Number<T> operator*(Number<T> lhs, const A& rhs) { return lhs *= rhs; }
template<typename T, typename A> A operator*(A lhs, Number<T> rhs) { return lhs *= rhs.get(); }
template<typename T, typename A> Number<T> operator*(Number<T> lhs, const Number<A>& rhs) { return lhs.set() *= rhs.get(); } 
template<typename T, typename A> Number<T> operator/(Number<T> lhs, const A& rhs) { return lhs /= rhs; }
template<typename T, typename A> A operator/(A lhs, Number<T> rhs) { return lhs /= rhs.get(); }
template<typename T, typename A> Number<T> operator/(Number<T> lhs, const Number<A>& rhs) { return lhs.set() /= rhs.get(); } 
template<typename T, typename A> Number<T> operator%(Number<T> lhs, const A& rhs) { return lhs %= rhs; }
template<typename T, typename A> A operator%(A lhs, Number<T> rhs) { return lhs += (int)rhs.get(); }
template<typename T, typename A> Number<T> operator%(Number<T> lhs, const Number<A>& rhs)
{
    return lhs.set() = (int)lhs.set() % (int)rhs.get();
} 

template<typename T> ostream& operator<<(ostream& os, const Number<T>& t) { return os << t.get(); }
template<typename T> istream& operator>>(istream& is, Number<T>& t);

