/* 
 * Заглолвочный файл
 */

#include "std_lib_facilities.h"
#include <list>

struct God {
    string name, mythology, vehicle, weapon;
    God(string n, string m, string v, string w)
        :name(n), mythology(m), vehicle(v), weapon(w) { }
};



template<typename T>
class Link {
public:
    T value;
    Link(const T& v, Link* p = nullptr, Link* s = nullptr)
        : value{v}, prev{p}, succ{s} { }
    Link* insert(Link* n);          // insert n before this object
    Link* add(Link* n);             // insert n after this object
    Link* add_ordered(Link*);       // places new element in its correct lexicographical position.
    Link* erase();                  // remove this object from list
    Link* find(const string& s);    // find s in list
    const Link* find(const string& s) const;    // find s in const list (see §18.5.1)
//    Link* advance(int n) const;     // move n positions in list
    Link* next() const { return succ; }
    Link* previous() const { return prev; }
private:
    Link* prev;
    Link* succ;
};






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

