//
// Глава 13. Упражнение 5. Определить функции из упр. №4 для окружности и элипса.
// Поместите точки соединения на границах и внутри этих фигур, но не за пределами окаймляющего их прмоугольника
// c++ -o code code.cpp GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp -lfltk -lfltk_images -std=c++11
//

#include "code.h"

using namespace Graph_lib;

const double PI = 3.14159265;	//Значение Пи

Point rotation(int x, int y, int width, int height, int angle)
{
	return Point(x - width*cos((angle*PI)/180), y - height*sin((angle*PI)/180));
}

//------------------------------------------------------------------------------
//	For CIRCLE
//North
Point n(const Ellipse& ellipse) {
	return Point(ellipse.point(0).x + ellipse.major(), ellipse.point(0).y);
}

//North-West
Point nw(const Ellipse& ellipse) {
//Представляем наш отрезок как вектор и поворачиваем его на заданный угол
	return rotation(ellipse.point(0).x + ellipse.major(),ellipse.point(0).y + ellipse.minor(),
	ellipse.major(), ellipse.minor(), 45);
}

//North-East
Point ne(const Ellipse& ellipse) {
	return rotation(ellipse.point(0).x + ellipse.major(),ellipse.point(0).y + ellipse.minor(),
	ellipse.major(), ellipse.minor(), 135);
}

//East
Point e(const Ellipse& ellipse) {
	return Point(ellipse.point(0).x + ellipse.major()*2, ellipse.point(0).y + ellipse.minor());
}

//South-East
Point se(const Ellipse& ellipse) {
	return rotation(ellipse.point(0).x + ellipse.major(),ellipse.point(0).y + ellipse.minor(),
	ellipse.major(), ellipse.minor(), 225);
}

//South
Point s(const Ellipse& ellipse) {
	return Point(ellipse.point(0).x + ellipse.major(), ellipse.point(0).y + ellipse.minor()*2);
}

//South-West
Point sw(const Ellipse& ellipse) {
	return rotation(ellipse.point(0).x + ellipse.major(),ellipse.point(0).y + ellipse.minor(),
	ellipse.major(), ellipse.minor(), 315);
}

//West
Point w(const Ellipse& ellipse) {
	return Point(ellipse.point(0).x, ellipse.point(0).y + ellipse.minor());
}

//Center Rectangle
Point center(const Ellipse& ellipse) {
	return ellipse.center();
}

//------------------------------------------------------------------------------
//	For CIRCLE
//North
Point n(const Circle& circle) {
	return Point(circle.point(0).x + circle.radius(), circle.point(0).y);
}

//North-West
Point nw(const Circle& circle) {
//Представляем наш отрезок как вектор и поворачиваем его на заданный угол
	return rotation(circle.point(0).x + circle.radius(),circle.point(0).y + circle.radius(),
	circle.radius(), circle.radius(), 45);
}

//North-East
Point ne(const Circle& circle) {
	return rotation(circle.point(0).x + circle.radius(),circle.point(0).y + circle.radius(),
	circle.radius(), circle.radius(), 135);
}

//East
Point e(const Circle& circle) {
	return Point(circle.point(0).x + circle.radius()*2, circle.point(0).y + circle.radius());
}

//South-East
Point se(const Circle& circle) {
	return rotation(circle.point(0).x + circle.radius(),circle.point(0).y + circle.radius(),
	circle.radius(), circle.radius(), 225);
}

//South
Point s(const Circle& circle) {
	return Point(circle.point(0).x + circle.radius(), circle.point(0).y + circle.radius()*2);
}

//South-West
Point sw(const Circle& circle) {
	return rotation(circle.point(0).x + circle.radius(),circle.point(0).y + circle.radius(),
	circle.radius(), circle.radius(), 315);
}

//West
Point w(const Circle& circle) {
	return Point(circle.point(0).x, circle.point(0).y + circle.radius());
}

//Center Rectangle
Point center(const Circle& circle) {
	return circle.center();
}

//------------------------------------------------------------------------------
//	For RECTANGLE
//North
Point n(const Rectangle& ABCD) {
	return Point(ABCD.point(0).x + ABCD.width()/2, ABCD.point(0).y);
}

//North-West
Point nw(const Rectangle& ABCD) {
	return ABCD.point(0);
}

//North-East
Point ne(const Rectangle& ABCD) {
	return Point(ABCD.point(0).x + ABCD.width(), ABCD.point(0).y);
}

//East
Point e(const Rectangle& ABCD) {
	return Point(ABCD.point(0).x + ABCD.width(), ABCD.point(0).y + ABCD.height()/2);
}

//South-East
Point se(const Rectangle& ABCD) {
	return Point(ABCD.point(0).x + ABCD.width(), ABCD.point(0).y + ABCD.height());
}

//South
Point s(const Rectangle& ABCD) {
	return Point(ABCD.point(0).x + ABCD.width()/2, ABCD.point(0).y + ABCD.height());
}

//South-West
Point sw(const Rectangle& ABCD) {
	return Point(ABCD.point(0).x, ABCD.point(0).y + ABCD.height());
}

//West
Point w(const Rectangle& ABCD) {
	return Point(ABCD.point(0).x, ABCD.point(0).y + ABCD.height()/2);
}

//Center Rectangle
Point center(const Rectangle& ABCD) {
	return Point(ABCD.point(0).x + ABCD.width()/2, ABCD.point(0).y + ABCD.height()/2);
}
//------------------------------------------------------------------------------

int main ()
try
{
    Simple_window win(Point(10,10),1200,800,"Chapter 13. Exercise 3:");

//RECTAGLE
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

//CIRCLE
    Circle circ(Point(500,425),100);
    circ.set_color(Color::blue);
    circ.set_style(Line_style(Line_style::solid,2));
    win.attach(circ);

	P = nw(circ);
	oss << "(" << P.x << "," << P.y << ")";
	Text circ_nw(Point(P.x-35,P.y-5), oss.str());
	circ_nw.set_color(Color::blue);
	circ_nw.set_font_size(15);
	win.attach(circ_nw);
	oss.str("");

	P = n(circ);
	oss << "(" << P.x << "," << P.y << ")";
	Text circ_n(Point(P.x-35,P.y-5), oss.str());
	circ_n.set_color(Color::blue);
	circ_n.set_font_size(15);
	win.attach(circ_n);
	oss.str("");

	P = ne(circ);
	oss << "(" << P.x << "," << P.y << ")";
	Text circ_ne(Point(P.x-35,P.y-5), oss.str());
	circ_ne.set_color(Color::blue);
	circ_ne.set_font_size(15);
	win.attach(circ_ne);
	oss.str("");

	P = e(circ);
	oss << "(" << P.x << "," << P.y << ")";
	Text circ_e(Point(P.x-35,P.y-5), oss.str());
	circ_e.set_color(Color::blue);
	circ_e.set_font_size(15);
	win.attach(circ_e);
	oss.str("");

	P = se(circ);
	oss << "(" << P.x << "," << P.y << ")";
	Text circ_se(Point(P.x-35,P.y-5), oss.str());
	circ_se.set_color(Color::blue);
	circ_se.set_font_size(15);
	win.attach(circ_se);
	oss.str("");

	P = s(circ);
	oss << "(" << P.x << "," << P.y << ")";
	Text circ_s(Point(P.x-35,P.y-5), oss.str());
	circ_s.set_color(Color::blue);
	circ_s.set_font_size(15);
	win.attach(circ_s);
	oss.str("");

	P = sw(circ);
	oss << "(" << P.x << "," << P.y << ")";
	Text circ_sw(Point(P.x-35,P.y-5), oss.str());
	circ_sw.set_color(Color::blue);
	circ_sw.set_font_size(15);
	win.attach(circ_sw);
	oss.str("");

	P = w(circ);
	oss << "(" << P.x << "," << P.y << ")";
	Text circ_w(Point(P.x-35,P.y-5), oss.str());
	circ_w.set_color(Color::blue);
	circ_w.set_font_size(15);
	win.attach(circ_w);
	oss.str("");

	P = center(circ);
	oss << "(" << P.x << "," << P.y << ")";
	Text circ_center(Point(P.x-35,P.y-5), oss.str());
	circ_center.set_color(Color::blue);
	circ_center.set_font_size(15);
	win.attach(circ_center);
	oss.str("");

//ELLIPSE
    Ellipse elips(Point(700,600),150,50);
    elips.set_color(Color::red);
    elips.set_style(Line_style(Line_style::solid,2));
    win.attach(elips);

	P = nw(elips);
	oss << "(" << P.x << "," << P.y << ")";
	Text elips_nw(Point(P.x-35,P.y-5), oss.str());
	elips_nw.set_color(Color::red);
	elips_nw.set_font_size(15);
	win.attach(elips_nw);
	oss.str("");

	P = n(elips);
	oss << "(" << P.x << "," << P.y << ")";
	Text elips_n(Point(P.x-35,P.y-5), oss.str());
	elips_n.set_color(Color::red);
	elips_n.set_font_size(15);
	win.attach(elips_n);
	oss.str("");

	P = ne(elips);
	oss << "(" << P.x << "," << P.y << ")";
	Text elips_ne(Point(P.x-35,P.y-5), oss.str());
	elips_ne.set_color(Color::red);
	elips_ne.set_font_size(15);
	win.attach(elips_ne);
	oss.str("");

	P = e(elips);
	oss << "(" << P.x << "," << P.y << ")";
	Text elips_e(Point(P.x-35,P.y-5), oss.str());
	elips_e.set_color(Color::red);
	elips_e.set_font_size(15);
	win.attach(elips_e);
	oss.str("");

	P = se(elips);
	oss << "(" << P.x << "," << P.y << ")";
	Text elips_se(Point(P.x-35,P.y-5), oss.str());
	elips_se.set_color(Color::red);
	elips_se.set_font_size(15);
	win.attach(elips_se);
	oss.str("");

	P = s(elips);
	oss << "(" << P.x << "," << P.y << ")";
	Text elips_s(Point(P.x-35,P.y-5), oss.str());
	elips_s.set_color(Color::red);
	elips_s.set_font_size(15);
	win.attach(elips_s);
	oss.str("");

	P = sw(elips);
	oss << "(" << P.x << "," << P.y << ")";
	Text elips_sw(Point(P.x-35,P.y-5), oss.str());
	elips_sw.set_color(Color::red);
	elips_sw.set_font_size(15);
	win.attach(elips_sw);
	oss.str("");

	P = w(elips);
	oss << "(" << P.x << "," << P.y << ")";
	Text elips_w(Point(P.x-35,P.y-5), oss.str());
	elips_w.set_color(Color::red);
	elips_w.set_font_size(15);
	win.attach(elips_w);
	oss.str("");

	P = center(elips);
	oss << "(" << P.x << "," << P.y << ")";
	Text elips_center(Point(P.x-35,P.y-5), oss.str());
	elips_center.set_color(Color::red);
	elips_center.set_font_size(15);
	win.attach(elips_center);
	oss.str("");

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
