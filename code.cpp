//
//	Глава 10. Задание 1 - 7
//

#include "code.h"

//------------------------------------------------------------------------------

istream& operator>>(istream& ist, Point& P)
{
	int x=0,y=0;
	ist >> x >> y;
	if (!ist) error ("Не корректные данные!");
	P = Point(x,y);
	return ist;
}

ostream& operator<<(ostream& os, const Point& P)
{
	return os << "x:" << P.x << " y:" << P.y;
}

//------------------------------------------------------------------------------

int main()
try
{
	vector<Point> original_points;
	Point P;
	cout << "Enter the coordinates of seven(through the gap):" << endl;
	for (int i=0; i<7; i++) {
		cin >> P;
		original_points.push_back(P);
	}
	
	cout << "Please insert you file name: ";
	string filename;
	cin >> filename;
	ofstream out(filename.c_str());
	if ( !out ) error("Don`t open this file for writing!");
	for (int i=0; i<original_points.size(); i++) 
		out << original_points[i].x << " " << original_points[i].y << endl;

	vector<Point> processed_points;
	ifstream input(filename.c_str());
	if ( !input ) error ("No such file "+filename);
	P = Point();	//initialisation
	while ( input >> P.x >> P.y ) {
		if ( input.eof() ) break;
		if ( !input ) error("Don`t read file: "+filename);
		processed_points.push_back(P);
		P = Point();	//initialisation
	}

	cout << "Reading from file: "+filename << endl;
	for (int i=0; i<processed_points.size(); i++) 
		cout << processed_points[i].x << " " << processed_points[i].y << endl;
	cout << "Readed lines: " << processed_points.size() << endl;

	//Next comes a trivial comparison vectors..
	return 0;
}
/*catch (asdasd::Invalid&) {
    cerr << "error: Invalid!!!\n"; 
    return 1;
}*/
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
