/* 
 * Заглолвочный файл
 */

#include "std_lib_facilities.h"

struct X {  // simple test class
    int val;
    void out(const string& s, int nv)
        { cerr << this << "–>" << s << ": " << val << " (" << nv << ")\n"; }
    X(){ out("X()",0); val=0; }    // default constructor
    X(int v) { val=v; out( "X(int)",v); }
    X(const X& x){ val=x.val; out("X(X&) ",x.val); }
    // copy constructor
    X& operator=(const X& a)    // copy assignment
        { out("X::operator=()",a.val); val=a.val; return *this; }
    ~X() { out("~X()",0); }    // destructor
};

