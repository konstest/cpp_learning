/* 
 * Headres file
 */

#include "std_lib_facilities.h"

template<typename T> struct S {
public:
    S(T v);
    T& get();
    const T& get() const;
    S& operator=(const T&);
private:
    T val;
};

template<typename T> ostream& operator<<(ostream& os, const vector<T>&);
template<typename T> istream& operator>>(istream& is, vector<T>&);

