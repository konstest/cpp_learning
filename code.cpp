//
// 
//

#include "code.h"

//------------------------------------------------------------------------------
//constructor
Rational::Rational(int n, int d)
:num(n), den(d)
{
	if (d==0) throw Invalid();
}

//------------------------------------------------------------------------------
/*
Rational& operator=(Rational& a, const Rational& b)
{
	a.num = b.num;
	a.den = b.den;
	return a;
}
*/
//------------------------------------------------------------------------------

Rational operator+(const Rational& a, const Rational& b)
{
	Rational tmp;
	if (a.den == b.den){
		tmp.num = a.num + b.num;
		tmp.den = a.den;
	}
	else {
		tmp.num = (a.num*b.den) + (b.num*a.den);	//reduce to a common denominator
		tmp.den = a.den * b.den;
	}
	return tmp;
}

//------------------------------------------------------------------------------

Rational operator-(const Rational& a, const Rational& b)
{
	Rational tmp;
	if (a.den == b.den) {
		tmp.num = a.num - b.num;
		tmp.den = a.den;
	}
	else {
		tmp.num = (a.num*b.den) - (b.num*a.den);	//reduce to a common denominator
		tmp.den = a.den * b.den;
	}
	return tmp;
}

//------------------------------------------------------------------------------

Rational operator*(const Rational& a, const Rational& b)
{
	Rational tmp;
	tmp.num = a.num * b.num;
	tmp.den = a.den * b.den;
	return tmp;
}
//------------------------------------------------------------------------------

Rational operator/(const Rational& a, const Rational& b)
{
	Rational tmp;
	tmp.num = b.den;	// revers values
	tmp.den = b.num;	//
	return a*tmp;
}

//------------------------------------------------------------------------------

bool operator==(const Rational& a, const Rational& b)
{
	return a.num == b.num && a.den == b.den;
}

//------------------------------------------------------------------------------

bool operator!=(const Rational& a, const Rational& b)
{
	return !(a==b);
}

//------------------------------------------------------------------------------

double to_double(const Rational a)
{
	return double(a.num)/double(a.den);
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Rational& d)
{
	return os << d.num << '/' << d.den;
}

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Rational& dd)
{
	char delim;
	is >> dd.num >> delim >> dd.den;
	if (!is) return is;
	if (delim != '/') {
		is.clear(ios_base::failbit);
		return is;
	}
	return is;
}

//------------------------------------------------------------------------------

int main()
try
{
	Rational a, b(1,2);
	a = Rational(5,2);
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	cout << "a*b= " << a*b << "(" << to_double(a*b) << ")" << endl;
	
return 0;
}
catch (Rational::Invalid&) {
    cerr << "error: Invalid!!!\n"; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
