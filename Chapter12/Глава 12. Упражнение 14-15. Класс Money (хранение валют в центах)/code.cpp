//
//	Глава 12. Задание 14 - 15
//

#include "code.h"

//------------------------------------------------------------------------------
double course(string cy)
{
	if (cy == "USD") return 1;			//default
	if (cy == "DKK") return 0.7;
	if (cy == "EUR") return 1.3;
	throw Money::Invalid();
}

//------------------------------------------------------------------------------
//translate value to cents
long Money::to_cents(string cy, double d)
{	//123.456
	double dd = d*course(cy);
	long val = dd;		//$123
	double c = dd - val;	//0.456 - cents
	c *= 100;				//45.6	- 45 cents 
	if ( (c - int(c)) != 0 && (c - int(c)) >= 0.5 )
		c += 1;				//rounding 0.6 -> 1 cents
	return (c + val*100);
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Money& d)
{
	return os << "USD" << d.c()/double(100) << " = " << d.c() << "`cents";
}

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Money& dd)
{
	string cy;
	double val;
	is >> cy >> val;
	if (!is) return is;
	dd = Money(cy,val);
	return is;
}

//------------------------------------------------------------------------------

int main()
try
{
	Money baks;
	cout << baks << endl;
	cout << "Input money (exam: USD 12.573)\n";
	while (true) {
		cin >> baks;
		cout << baks << endl;
	}
return 0;
}
catch (Money::Invalid&) {
    cerr << "error: Invalid!!!\n"; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
