
//
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

class Rational {
public:

    class Invalid { };					// to throw as exception

    Rational(int n, int d);				// constructor
    Rational():num(1), den(1) { };		// default constructor

    int	num;		//numerator
    int	den;		//denominator
};

//------------------------------------------------------------------------------
// conversion operators:
//Rational& operator=(Rational& a, const Rational& b);
Rational operator+(const Rational& a, const Rational& b);
Rational operator-(const Rational& a, const Rational& b);
Rational operator*(const Rational& a, const Rational& b);
Rational operator/(const Rational& a, const Rational& b);
bool operator==(const Rational& a, const Rational& b);
bool operator!=(const Rational& a, const Rational& b);
double to_double(const Rational a);
//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Rational& d);
istream& operator>>(istream& is, Rational& dd);

//------------------------------------------------------------------------------

