//
//	Глава 10. Упражнение 7. Калькулятор Римских цифр.
//

#include <iostream>
#include "std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------
class Invalid{

};

class Roman_int {
public:
	int	as_int() const	{ return number; }
	Roman_int(): number(0) {}			//default constr
	Roman_int(int n): number(n) {}		//constructor
private:
	int	number;
};

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Roman_int& r);			//input number
ostream& operator<<(ostream& os, const Roman_int& r);	//output number
int roman_to_int(string num);
int r_int(char letter);
string int_to_roman(int num);
string roman_rules(int digit, int coefficient);

//------------------------------------------------------------------------------

