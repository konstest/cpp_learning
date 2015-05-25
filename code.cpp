//
//	Глава 10. Упражнение 2 - 4
//

#include "code.h"

//------------------------------------------------------------------------------
Reading::Reading	(int h, char c, double t)
:hour(h), suffix(c), temperature(t)
{
	if ( !(0<=h && h<=23) ) throw Invalid();
	if ( !(c=='c' || c=='f') ) throw Invalid();
	//temp is normal forever :)
}

void write_file(string& filename, const vector<Reading>& temps)
{
	ofstream file(filename.c_str());
	if (!file) error("No such file: "+filename);
	for (int i=0; i<temps.size(); i++)
		file << temps[i].hour << " " << temps[i].suffix << " " 
			<< temps[i].temperature << endl;
}

vector<Reading> read_file(string& filename)
{
	vector<Reading> temps;
	int hour;
	char suffix;
	double temperature;
	ifstream file(filename.c_str());
	if (!file) error("No such file: "+filename);
	while (true) {
		file >> hour >> suffix >> temperature;
		if (file.eof()) break;
		if (file.fail()) error("Error file format!");
		temps.push_back(Reading(hour,suffix,temperature));
	}
	return temps;
}

//Create vector of temperatures.
vector<Reading> input_temps()
{
	vector<Reading> temps;
	int hour;
	char suffix;
	double temp;
	cout << "Input values (exam: 0 c 27) or (exam: 7 f 60):\n";
	cout << "(for exit enter CTRL+D)\n";
	cin >> hour >> suffix >> temp;
	while (!cin.eof()) {
		if (cin.fail()) error ("Error input format!");
		temps.push_back(Reading(hour,suffix,temp));
		cin >> hour >> suffix >> temp;
	}
	cin.unget();
	cin.clear();
	return temps;
}

double avarage_temp(const vector<Reading> temps)
{
	double summ=0;
	for (int i=0; i<temps.size(); i++)
		if (temps[i].suffix == 'f')
			summ += temps[i].temperature;
		else
			summ += c_to_f(temps[i].temperature);
	return summ/temps.size();
}

//Converting Celsius to Fahrenheit
double c_to_f(double c)
{
	return (c*(9/double(5)) + 32);
}

//Converting Fahrenheit to Celsius
double f_to_c(double f)
{
	return (5/double(9))*(f - 32);
}

double median_temp(const vector<Reading> temps)
{
	vector<double> values;
	int count = temps.size();
	for (int i=0; i<count; i++)
		if (temps[i].suffix == 'f')
			values.push_back(temps[i].temperature);
		else
			values.push_back(c_to_f(temps[i].temperature));
	sort(values.begin(),values.end());
	if (count%2!=0)
		return values[count/2];
	return (values[(count/2)-1] + values[count/2])/double(2);
}
//------------------------------------------------------------------------------

int main()
try
{
	//INPUT:
	vector<Reading> temps = input_temps();
	string filename;
	cout << "Input file name please: ";
	cin >> filename;
	write_file(filename,temps);

	//COMPUTING:
	vector<Reading> ctemps = read_file(filename);
	double avarage = avarage_temp(ctemps);
	double median = median_temp(ctemps);

	//OUTPUT:
	cout << "Avarage temperature: " << avarage << "(Fahrenheit) "
		<< f_to_c(avarage) << "(Celsius)" << endl;
	cout << "Median temperatures: " << median << "(Fahrenheit) "
		<< f_to_c(median) << "(Celsius)" << endl;

	return 0;
}
catch (Invalid&) {
    cerr << "error: Invalid!!!\n"; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
