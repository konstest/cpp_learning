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
};

//------------------------------------------------------------------------------

class Type2 {
    Tracer _ob;
    string _s;
public:
    Type2(const string& k): _s(k), _ob("Type2: "+k) {}
};
