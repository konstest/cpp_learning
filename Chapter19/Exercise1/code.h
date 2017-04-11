/* 
 * Headres file
 */

#include "std_lib_facilities.h"

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
