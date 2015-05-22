
//
// This is example code from Chapter 9.8 "The Date class" of 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "code.h"

namespace Chrono {

// member function definitions:

//------------------------------------------------------------------------------

Date::Date(int yy, Month mm, int dd)
    : y(yy), m(mm), d(dd)
{
    if (!is_date(yy,mm,dd)) throw Invalid();
}

//------------------------------------------------------------------------------

const Date& default_date()
{
    static const Date dd(2001,Date::jan,1); // start of 21st century
    return dd;
}

//------------------------------------------------------------------------------

Date::Date()
    :y(default_date().year()),
     m(default_date().month()),
     d(default_date().day())
{
}

//------------------------------------------------------------------------------

void Date::add_day(int n)
{
    // ...
}

//------------------------------------------------------------------------------

void Date::add_month(int n)
{
    // ...
}

//------------------------------------------------------------------------------

void Date::add_year(int n)
{
    if (m==feb && d==29 && !leapyear(y+n)) { // beware of leap years!
        m = mar;        // use March 1 instead of February 29
        d = 1;
    }
    y+=n;
}

//------------------------------------------------------------------------------

// helper functions:

bool is_date(int y, Date::Month  m, int d)
{
    // assume that y is valid

    if (d<=0) return false;            // d must be positive

    int days_in_month = 31;            // most months have 31 days

    switch (m) {
case Date::feb:                        // the length of February varies
    days_in_month = (leapyear(y))?29:28;
    break;
case Date::apr: case Date::jun: case Date::sep: case Date::nov:
    days_in_month = 30;                // the rest have 30 days
    break;
    }

    if (days_in_month<d) return false;

    return true;
} 

//------------------------------------------------------------------------------

bool leapyear(int y)
{
    return y%4 ? true : false;
}

//------------------------------------------------------------------------------

bool operator==(const Date& a, const Date& b)
{
    return a.year()==b.year()
        && a.month()==b.month()
        && a.day()==b.day();
}

//------------------------------------------------------------------------------

bool operator!=(const Date& a, const Date& b)
{
    return !(a==b);
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.year()
              << ',' << d.month()
              << ',' << d.day() 
              << ')';
}

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Date& dd)
{
    int y, m, d;
    char ch1, ch2, ch3, ch4;
    is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
    if (!is) return is;
    if (ch1!='(' || ch2!=',' || ch3!=',' || ch4!=')') { // oops: format error
        is.clear(ios_base::failbit);                    // set the fail bit
        return is;
    }
    dd = Date(y,Date::Month(m),d);     // update dd
    return is;
}

//------------------------------------------------------------------------------

enum Day {
    sunday, monday, tuesday, wednesday, thursday, friday, saturday
};

//------------------------------------------------------------------------------

Day day_of_week(const Date& d)
{
    // ...
    return sunday;
}

//------------------------------------------------------------------------------

Date next_Sunday(const Date& d)
{
    // ...
    return d;
}

//------------------------------------------------------------------------------

Date next_weekday(const Date& d)
{
    // ...
    return d;
}

//------------------------------------------------------------------------------

int month_to_int(const Date::Month m)
{
	switch(m) {
	case Date::jan:
		return 1;
	case Date::feb:
		return 2;
	case Date::mar:
		return 3;
	case Date::apr:
		return 4;
	case Date::may:
		return 5;
	case Date::jun:
		return 6;
	case Date::jul:
		return 7;
	case Date::aug:
		return 8;
	case Date::sep:
		return 9;
	case Date::oct:
		return 10;
	case Date::nov:
		return 11;
	case Date::dec:
		return 12;
	}
}

//------------------------------------------------------------------------------

long Date::number_from_1970() const
{
    int days_count = 0;
    if (y>1972)
		days_count = 365*(y-1970) + (y-1972)/4 + 1;	//1972 is leap year
    else if (y>=1970)
    	days_count = 365*(y-1970);
    else throw Invalid();  //This year, less than in 1970;

	for (int i=1; i<month_to_int(m); i++) {
		int days_in_month = 31;
		switch (i) {	// Look what month?
		case 2:				// the length of February varies
			days_in_month = (leapyear(y)) ? 29:28;
			break;
		case 4: case 6: case 9: case 11:
			days_in_month = 30;
			break;
		}
		days_count += days_in_month;
	}
	return days_count + d;
}

//------------------------------------------------------------------------------

} // Chrono

//------------------------------------------------------------------------------

int main()
try
{
    Chrono::Date holiday(1970, Chrono::Date::jul, 1); // initialization
    Chrono::Date d2 = Chrono::next_Sunday(holiday);
    Chrono::Day  d  = day_of_week(d2);
    cout << "holiday is " << holiday << "number:" << holiday.number_from_1970()
    << " d2 is " << d2 << "number:" << d2.number_from_1970() << endl;
    return holiday != d2;
}
catch (Chrono::Date::Invalid&) {
    cerr << "error: Invalid date\n"; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
