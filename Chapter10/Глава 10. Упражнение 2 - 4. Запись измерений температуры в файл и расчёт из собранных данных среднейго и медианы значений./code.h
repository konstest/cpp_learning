//
//	Глава 10. Упражнение 2 - 4
//

#include <iostream>
#include "std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------
class Invalid{

};

struct Reading {
	int		hour;
	char	suffix;
	double	temperature;
	Reading	(int h, char c, double t);
};

//------------------------------------------------------------------------------
double median_temp(const vector<Reading> temps);
double f_to_c(double f);
double c_to_f(double c);
double avarage_temp(const vector<Reading> temps);
vector<Reading> input_temps();
vector<Reading> read_file(string& filename);
void write_file(string& filename, const vector<Reading>& temps);
//------------------------------------------------------------------------------

