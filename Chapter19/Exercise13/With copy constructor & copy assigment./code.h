/* 
 * Заглолвочный файл
 */
#include "std_lib_facilities.h"
#include <fstream>

//------------------------------------------------------------------------------
class Tracer {
    string _str;
public:
    Tracer(const string& str): _str(str) { cout << "'"+_str+"'()" << endl; }
    ~Tracer() { cout << "~'"+_str+"'()" << endl; }
    Tracer(const Tracer& tr) {
        _str = tr._str; 
        cout << "copy constructor('"+_str+"')" << endl; 
        _str = tr._str+" <- from copy constr";
    }
    Tracer& operator=(const Tracer& r_val) {
        cout << "copy assigment('"+r_val._str+"')" << endl;
        _str = r_val._str+" <- from copy assigm"; 
        return *this;
    }
};

//------------------------------------------------------------------------------

class Type2 {
    Tracer _ob;
    string _s;
public:
    Type2(const string& k): _s(k), _ob("Type2: "+k) {}
};
