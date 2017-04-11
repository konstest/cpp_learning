//
//	Глава 12. Задание 14 - 15
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------
/*
	Вводится: $123.45
	123	- доллара
	45	- центов, если будет .4523, то округляется до 45 центов
*/
class Money {
public:
    class Invalid { };		// to throw as exception
	Money(): cents(1) { }	// default constructor
	Money(string cy, double d): cents(to_cents(cy,d)) { } //constructor
	long c() const { return cents; }
private:
	long to_cents(string cy, double d);		//translate to cents
	long cents;
};

//------------------------------------------------------------------------------
double course(string cy);

ostream& operator<<(ostream& os, const Money& a);
istream& operator>>(istream& is, Money& a);

//------------------------------------------------------------------------------

