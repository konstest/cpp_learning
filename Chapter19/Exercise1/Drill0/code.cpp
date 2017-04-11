/* 
 * Chapter 19. Drill.
 */

#include "std_lib_facilities.h"
#include "code.h"

//------------------------------------------------------------------------------
template<typename T>
S<T>::S(T v)
{
   val = v; 
}

//------------------------------------------------------------------------------
template<typename T> 
T& S<T>::get()
{
   return val; 
}

//------------------------------------------------------------------------------
template<typename T> 
const T& S<T>::get() const
{
   return val; 
}

//------------------------------------------------------------------------------
template<typename T> 
S<T>& S<T>::operator=(const T& t)
{
    val = t;
}

//------------------------------------------------------------------------------
template<typename T>
void read_val(T& v)
{
    cin >> v;
}

//------------------------------------------------------------------------------
template<typename T>
istream& operator>>(istream& is, vector<T>& v)
{
    for (int i=0; i<v.size(); i++)
        is >> v[i];
    return is;
}

//------------------------------------------------------------------------------
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    for (int i=0; i<v.size(); i++)
        os << v[i] << " ";
    return os;
}

//------------------------------------------------------------------------------
int main()
{
    S<int> ii(int(2));
    S<char> cc(char('K'));
    S<double> dd(double(1.2));
    S<string> ss(string("STROKA"));
    S<vector<int>> vv(vector<int> (10));

    cout << "Type int: ";
    read_val(ii.get());
    cout << ii.get() << endl;

    cout << "Type char: ";
    read_val(cc.get());
    cout << cc.get() << endl;

    cout << "Type double: ";
    read_val(dd.get());
    cout << dd.get() << endl;

    cout << "Type string: ";
    read_val(ss.get());
    cout << ss.get() << endl;

    cout << "Type vector of " << vv.get().size() << " int:\n";
    read_val(vv.get());
    cout << vv.get() << endl;

    ss = "other string";
    cout << ss.get() << endl;

    vector<int> kk(5);
    vv = kk;
    cout << vv.get() << endl;
}

//------------------------------------------------------------------------------
