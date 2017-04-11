/* 
 * Headres file
 */

#include "std_lib_facilities.h"

template<typename A, typename B>
class Pair {
public:
    Pair(const A& a, const B& b): v1(a), v2(b) { }
    A v1;
    B v2;
};

template<typename A, typename B>
ostream& operator<<(ostream&, const Pair<A,B>&);


struct Type {
    int a;
    double b;
    Type(): a(0), b(0.0) { }
    Type(int aa, double bb): a(aa), b(bb) { }
};

ostream& operator<<(ostream& os, const Type& t);   //overload output for Type
