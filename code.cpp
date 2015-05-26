//
//	Глава 10. Упражнение 6. Перевод в/из Римских цифр.
//

#include "code.h"

//------------------------------------------------------------------------------
//input number
istream& operator>>(istream& is, Roman_int& r)
{
	string num;
	is >> num;
	r = Roman_int( roman_to_int(num) );
	return is;
}

//------------------------------------------------------------------------------
//output number
ostream& operator<<(ostream& os, const Roman_int& r)
{
	return os << int_to_roman(r.as_int());
}

//------------------------------------------------------------------------------
//Converting from Roman to Arabic
int roman_to_int(string num)
{	//MMMDCCLII = 3752
	int number=r_int(num[num.size()-1]), r=0;

	for (int i=num.size()-1; i>0; i--)
		if ( r_int(num[i-1]) > r_int(num[i]) ){
			r = 0;
			number += r_int(num[i-1]);
		}
		else  if ( r_int(num[i-1]) < r_int(num[i]) ) {
			r = 0;
			if ( i>1 && r_int(num[i-1])==r_int(num[i-2]) )
				error ("Error: two in a row to the left of a smaller number of larger.");
			number -= r_int(num[i-1]);
		}
		else { // ==
			r++;
			if (r>2)
				error ("Error: more than three repetitions of the same number.");
			number += r_int(num[i-1]);
		}
	return number;
}

//------------------------------------------------------------------------------
//convert
int r_int(char letter)
{
	switch (letter) {
	case 'I':
		return 1;
	case 'V':
		return 5;
	case 'X':
		return 10;
	case 'L':
		return 50;
	case 'C':
		return 100;
	case 'D':
		return 500;
	case 'M':
		return 1000;
	default:
		error("No such letter: "+letter);
	}
}

//------------------------------------------------------------------------------

string int_to_roman(int num)
{	//3752 = MMMDCCLII
	int a=0,b=0,c=0,d=0;
	string roman;
	if (num <= 3999) {
		a = num/1000;				//	3752/1000 = 3 - thousands
		b = (num-a*1000)/100;		//	(3752-3000)/100 = 7	- handreds
		c = (num-a*1000-b*100)/10;	//	(3752-3000-700)/10 = 5 - tens of
		d = (num-a*1000-b*100-c*10);//	2
		if (a>0)
			for (int i=0; i<a; i++)
				roman += "M";
		if (b>0)
			roman += roman_rules(b,100);
		if (c>0)
			roman += roman_rules(c,10);
		if (d>0)
			roman += roman_rules(d,1);
	}
	else error ("The number more than 3999");
	return roman;
}

//------------------------------------------------------------------------------

string roman_rules(int digit, const int coefficient)
{
	string roman;
	string bigges;
	string half;
	string tithe;
	switch (coefficient) {
	case 100:
		bigges = "M";
		half = "D";
		tithe = "C";
		break;
	case 10:
		bigges = "C";
		half = "L";
		tithe = "X";
		break;
	case 1:
		bigges = "X";
		half = "V";
		tithe = "I";
		break;
	}
	int ko = digit*coefficient;
	if ( ko==coefficient*1 || ko==coefficient*2 || ko==coefficient*3 )
		for (int i=0; i<digit; i++)
			roman += tithe;
	if ( ko==coefficient*4 )
		roman += tithe+half;
	if ( ko==coefficient*5 )
		roman += half;
	if ( ko==coefficient*6 || ko==coefficient*7 || ko==coefficient*8 ) {
		roman += half;
		for (int i=0; i<digit-5; i++)
			roman += tithe;
	}
	if ( ko==coefficient*9 )
		roman += tithe+bigges;

	return roman;
}

//------------------------------------------------------------------------------

int main()
try
{
	int number;
	Roman_int r;
	//INPUT:
	cout << "Input integer number(MAX:3999): ";
	cin >> number;
	r = Roman_int(number);
	cout << "Roman " << r << " = " << r.as_int() << endl;
	cout << "Input Roman number(MAX:MMMCMXCIX = 3999): ";
	cin >> r;
	//COMPUTING:

	//OUTPUT:
	cout << "Roman " << r << " = " << r.as_int() << endl;
	return 0;
}
catch (Invalid&) {
    cerr << "error: Invalid!!!\n"; 
    return 1;
}
catch (...) {
    return 2;
}

//------------------------------------------------------------------------------
