//
// Глава 13. Упражнение 4. Определить функции n(), s(), e(), w(), center(), ne(), se() и т.д.
// Каждая из них должна получать аргумент типа Rectangle и возвращать объект типа Point.
// Иными словами функции вычисляющие координаты точек углов, центра и середины сторон прямоугольника.
// c++ -o code code.cpp GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp -lfltk -lfltk_images -std=c++11

#include "code.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------
//North
Point n(const Rectangle& ABCD) {
	return Point(ABCD.point(0).x + ABCD.width()/2, ABCD.point(0).y);
}

//------------------------------------------------------------------------------
//North-West
Point nw(const Rectangle& ABCD) {
	return ABCD.point(0);
}

//------------------------------------------------------------------------------
//North-East
Point ne(const Rectangle& ABCD) {
	return Point(ABCD.point(0).x + ABCD.width(), ABCD.point(0).y);
}

//------------------------------------------------------------------------------
//East
Point e(const Rectangle& ABCD) {
	return Point(ABCD.point(0).x + ABCD.width(), ABCD.point(0).y + ABCD.height()/2);
}

//------------------------------------------------------------------------------
//South-East
Point se(const Rectangle& ABCD) {
	return Point(ABCD.point(0).x + ABCD.width(), ABCD.point(0).y + ABCD.height());
}

//------------------------------------------------------------------------------
//South
Point s(const Rectangle& ABCD) {
	return Point(ABCD.point(0).x + ABCD.width()/2, ABCD.point(0).y + ABCD.height());
}

//------------------------------------------------------------------------------
//South-West
Point sw(const Rectangle& ABCD) {
	return Point(ABCD.point(0).x, ABCD.point(0).y + ABCD.height());
}

//------------------------------------------------------------------------------
//West
Point w(const Rectangle& ABCD) {
	return Point(ABCD.point(0).x, ABCD.point(0).y + ABCD.height()/2);
}

//------------------------------------------------------------------------------
//Center Rectangle
Point center(const Rectangle& ABCD) {
	return Point(ABCD.point(0).x + ABCD.width()/2, ABCD.point(0).y + ABCD.height()/2);
}

//------------------------------------------------------------------------------

int main ()
try
{
    Simple_window win(Point(10,10),1200,800,"Chapter 13. Exercise 3:");

    Rectangle ABCD(Point(100,150),Point(400,300));
    ABCD.set_style(Line_style(Line_style::solid,7));
    win.attach(ABCD);

	ostringstream oss;
	Point P = nw(ABCD);
	oss << "(" << P.x << "," << P.y << ")";
	Text TXT(Point(P.x-35,P.y-5), oss.str());
	TXT.set_font_size(15);
	win.attach(TXT);
	oss.str("");

	P = n(ABCD);
	oss << "(" << P.x << "," << P.y << ")";
	Text TXT1(Point(P.x-35,P.y-5), oss.str());
	TXT1.set_font_size(15);
	win.attach(TXT1);
	oss.str("");

	P = ne(ABCD);
	oss << "(" << P.x << "," << P.y << ")";
	Text TXT2(Point(P.x-35,P.y-5), oss.str());
	TXT2.set_font_size(15);
	win.attach(TXT2);
	oss.str("");
	
	P = ne(ABCD);
	oss << "(" << P.x << "," << P.y << ")";
	Text TXT3(Point(P.x-35,P.y-5), oss.str());
	TXT3.set_font_size(15);
	win.attach(TXT3);
	oss.str("");

	P = se(ABCD);
	oss << "(" << P.x << "," << P.y << ")";
	Text TXT4(Point(P.x-35,P.y-5), oss.str());
	TXT4.set_font_size(15);
	win.attach(TXT4);
	oss.str("");

	P = s(ABCD);
	oss << "(" << P.x << "," << P.y << ")";
	Text TXT5(Point(P.x-35,P.y-5), oss.str());
	TXT5.set_font_size(15);
	win.attach(TXT5);
	oss.str("");

	P = sw(ABCD);
	oss << "(" << P.x << "," << P.y << ")";
	Text TXT6(Point(P.x-35,P.y-5), oss.str());
	TXT6.set_font_size(15);
	win.attach(TXT6);
	oss.str("");

	P = w(ABCD);
	oss << "(" << P.x << "," << P.y << ")";
	Text TXT7(Point(P.x-35,P.y-5), oss.str());
	TXT7.set_font_size(15);
	win.attach(TXT7);
	oss.str("");

	P = center(ABCD);
	oss << "(" << P.x << "," << P.y << ")";
	Text TXT8(Point(P.x-35,P.y-5), oss.str());
	TXT8.set_font_size(15);
	win.attach(TXT8);
	oss.str("");

	P = e(ABCD);
	oss << "(" << P.x << "," << P.y << ")";
	Text TXT9(Point(P.x-35,P.y-5), oss.str());
	TXT9.set_font_size(15);
	win.attach(TXT9);
	oss.str("");

    Rectangle abcd(Point(150,250),Point(500,600));
    abcd.set_color(Color::blue);
    abcd.set_style(Line_style(Line_style::solid,2));
    win.attach(abcd);
	win.attach(TXT);

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

//------------------------------------------------------------------------------
