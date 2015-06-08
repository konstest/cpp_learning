//
// Глава 12. Упражнения с 1 по 8.
//
// c++ -o code code.cpp GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp -lfltk -lfltk_images -std=c++11

#include "GUI/Simple_window.h"    // if we want that "Next" button
#include "GUI/Graph.h"
#include "std_lib_facilities.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

int main ()
try
{ 
    Point tl(100,100);    // top-left corner of our window

    Simple_window win(tl,x_max()+100,y_max()+100,"My window");

    Rectangle r(Point(50,200), 100, 300);// top-left corner, width, height
    r.set_color(Color::blue);     // color the inside of the rectangle
    win.attach(r);
	
	ostringstream txt;
	txt << x_max();
	string x_w = txt.str();
	txt.str("");
	txt << y_max();
	string y_w = txt.str();

    Text t(Point(60,450), "Screen X:"+x_w+" Screen Y:"+y_w);
    win.attach(t);
    t.set_font_size(20);

    Text F(Point(100,120), "N");
    Text I(Point(200,120), "K");
    Text O(Point(300,120), "A");
	F.set_color(Color::yellow);
	I.set_color(Color::red);
	O.set_color(Color::dark_magenta);
    F.set_font_size(150);
    I.set_font_size(150);
    O.set_font_size(150);
    win.attach(F);
    win.attach(I);
    win.attach(O);

	Polygon p;
	p.add(Point(50,50));
	p.add(Point(50,150));
	p.add(Point(150,150));
	p.add(Point(150,50));
	p.set_color(Color::red);
    win.attach(p);

	
    Rectangle s11(Point(200,150), 50, 50);
    s11.set_fill_color(Color::black);
    win.attach(s11);
    Rectangle s21(Point(250,150), 50, 50);
    s21.set_color(Color::white);
    s21.set_fill_color(Color::white);
    win.attach(s21);
    Rectangle s31(Point(300,150), 50, 50);
    s31.set_fill_color(Color::black);
    win.attach(s31);
    Rectangle s41(Point(350,150), 50, 50);
    s41.set_color(Color::white);
    s41.set_fill_color(Color::white);
    win.attach(s41);

    Rectangle s12(Point(200,200), 50, 50);
    s12.set_color(Color::white);
    s12.set_fill_color(Color::white);
    win.attach(s12);
    Rectangle s22(Point(250,200), 50, 50);
    s22.set_fill_color(Color::black);
    win.attach(s22);
    Rectangle s32(Point(300,200), 50, 50);
    s32.set_color(Color::white);
    s32.set_fill_color(Color::white);
    win.attach(s32);
    Rectangle s42(Point(350,200), 50, 50);
    s42.set_fill_color(Color::black);
    win.attach(s42);

    Rectangle s13(Point(200,250), 50, 50);
    s13.set_fill_color(Color::black);
    win.attach(s13);
    Rectangle s23(Point(250,250), 50, 50);
    s23.set_color(Color::white);
    s23.set_fill_color(Color::white);
    win.attach(s23);
    Rectangle s33(Point(300,250), 50, 50);
    s33.set_fill_color(Color::black);
    win.attach(s33);
    Rectangle s43(Point(350,250), 50, 50);
    s43.set_color(Color::white);
    s43.set_fill_color(Color::white);
    win.attach(s43);

    Rectangle s14(Point(200,300), 50, 50);
    s14.set_color(Color::white);
    s14.set_fill_color(Color::white);
    win.attach(s14);
    Rectangle s24(Point(250,300), 50, 50);
    s24.set_fill_color(Color::black);
    win.attach(s24);
    Rectangle s34(Point(300,300), 50, 50);
    s34.set_color(Color::white);
    s34.set_fill_color(Color::white);
    win.attach(s34);
    Rectangle s44(Point(350,300), 50, 50);
    s44.set_fill_color(Color::black);
    win.attach(s44);

    Rectangle big_r(Point(10,15), (x_max()/3)*2, (y_max()/4)*3);
    win.attach(big_r);
    Rectangle big_r_canvas(Point(9,14), (x_max()/3)*2+1, (y_max()/4)*3+1);
    big_r_canvas.set_color(Color::red);
    win.attach(big_r_canvas);

	//drawing at home:
    Rectangle karkas(Point(500,550), 500, 400);
    karkas.set_fill_color(Color::green);
    win.attach(karkas);
	
    Rectangle window1(Point(525,650), 125, 125);
    window1.set_fill_color(Color::blue);
    win.attach(window1);
    Rectangle window2(Point(850,650), 125, 125);
    window2.set_fill_color(Color::blue);
    win.attach(window2);

    Rectangle door(Point(675,700), 150, 250);
    door.set_fill_color(Color::black);
    win.attach(door);

    Closed_polyline roof;
    roof.add(Point(450,550)); 
    roof.add(Point(750,250));
    roof.add(Point(1050,550));
    roof.set_fill_color(Color::yellow);
    win.attach(roof);
	
    Closed_polyline pipe;
    pipe.add(Point(850,350));
    pipe.add(Point(900,400));
    pipe.add(Point(900,300));
    pipe.add(Point(850,300));
    pipe.set_fill_color(Color::dark_cyan);
    win.attach(pipe);

	Circle olimp1(Point(600,100),50);
	olimp1.set_color(Color::blue);
	olimp1.set_style(Line_style(Line_style::Line_style_type::solid,4));
	win.attach(olimp1);
	Circle olimp2(Point(660,150),50);
	olimp2.set_color(Color::yellow);
	olimp2.set_style(Line_style(Line_style::Line_style_type::solid,4));
	win.attach(olimp2);
	Circle olimp3(Point(720,100),50);
	olimp3.set_color(Color::black);
	olimp3.set_style(Line_style(Line_style::Line_style_type::solid,4));
	win.attach(olimp3);
	Circle olimp4(Point(780,150),50);
	olimp4.set_color(Color::green);
	olimp4.set_style(Line_style(Line_style::Line_style_type::solid,4));
	win.attach(olimp4);
	Circle olimp5(Point(840,100),50);
	olimp5.set_color(Color::red);
	olimp5.set_style(Line_style(Line_style::Line_style_type::solid,4));
	win.attach(olimp5);

	Image photo(Point(1050,-150),"Dima.jpg");
	photo.set_mask(Point(0,0),1000,1500);
	win.attach(photo);
	win.set_label("Photo: Belenchenko Dmitrii.");

    win.wait_for_button();               // Display!
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
