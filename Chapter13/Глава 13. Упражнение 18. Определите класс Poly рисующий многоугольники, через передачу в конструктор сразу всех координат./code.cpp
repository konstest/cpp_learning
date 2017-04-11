//
// Глава 13. Упражнение 18. Определите класс Poly рисующий многоугольники, 
//	через передачу в конструктор сразу всех координат.
// Измененая команда компиляции, а именно code.cpp добавлена в конец.
// clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "code.h"

using namespace Graph_lib;

const double PI = 3.141592653589;

//------------------------------------------------------------------------------
bool Intersection( const int ax1, const int ay1, const int ax2, const int ay2,
	const int bx1, const int by1, const int bx2, const int by2 )
{
	unsigned int v1 = (bx2-bx1)*(ay1-by1)-(by2-by1)*(ax1-bx1);
	unsigned int v2 = (bx2-bx1)*(ay2-by1)-(by2-by1)*(ax2-bx1);
	unsigned int v3 = (ax2-ax1)*(by1-ay1)-(ay2-ay1)*(bx1-ax1);
	unsigned int v4 = (ax2-ax1)*(by2-ay1)-(ay2-ay1)*(bx2-ax1);
	return ( (v1*v2<0) && (v3*v4<0) ) ? true : false;
}

Poly::Poly (vector<Point> P)
{
	int np = P.size();
	if (np < 3) error("less than 3 points in a Polygon");

	P.push_back(P[0]);
    Point ignore(0,0);
	for (int i = np-1; i > 1; i--)
		for (int j = 0; j < i - 2; j++)
			if ( line_segment_intersect(P[i],P[i-1],P[j],P[j+1],ignore) )
				error("intersect in polygon");

	for (int j = np-2; j > 1; j--)
		if ( line_segment_intersect(P[0],P[np-1],P[j],P[j-1],ignore) )
			error("intersect in polygon");

	P.pop_back();

	for (int i = 0; i < np; i++)
	    Closed_polyline::add(P[i]);
}
//------------------------------------------------------------------------------

int main ()
try
{
    Simple_window win(Point(50,50),800,600,"Chapter 13.");

	vector<Point> P;
	P.push_back(Point(100,100));
	P.push_back(Point(500,50));
	P.push_back(Point(200,550));
//	P.push_back(Point(0,200));		//У Строуструпа так полигон рисовался, хотя не должен :)
	P.push_back(Point(10,300));
	
	Poly L(P);
/*	Polygon L;
	for (int i = 0; i < P.size(); i++)
		L.add(P[i]);
*/
	win.attach(L);
	
	win.wait_for_button();
}
catch(exception& e) {
    // some error reporting
    return 1;
}
catch(...) {
    // some more error reporting
    return 2;
}

