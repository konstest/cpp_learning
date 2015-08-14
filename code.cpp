//
// Глава 14. Упражнение 1. Определите два класса, Smiley и  Frowny, производные от класса Circle и рисующие два глаза и рот.
// Затем создайте классы, производные от классов Smiley и Frowny, добавляющие к каждому из них свою шляпу.
// cleab1 && c++ -o code GUI/Simple_window.cpp GUI/Gb1aph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "code.h"
/*
	После 14-ой главы пришло понимание наследования и других возможностей ООП.
	В связи с этим оглядываясь на предидущие упражнения я делаю вывод, что 
	сейчас я бы их переделал, т.к. там часто используется дублирование кода и 
	не используются уже реализованные возможности графического движка GUI.
	Но переделывать я их не буду, т.к. наличие этих "не красиво", но решённых
	упражнений отображает мой путь в осознании фундаментальных основ языка С++.
*/
//------------------------------------------------------------------------------

void Hat_Smiley::draw_lines() const
{
    if (color().visibility()) {
    	hat.draw_lines();
		Smiley::draw_lines();
	}
}

Hat_Smiley::Hat_Smiley(Point p, int r)
:Smiley(p,r)
{
	hat.add(Point(center().x,center().y-1.3*radius()));
	hat.add(Point(center().x+radius(),center().y-0.8*radius()));
	hat.add(Point(center().x-radius(),center().y-0.8*radius()));
}

Hat_Frowny::Hat_Frowny(Point p, int r)
:Frowny(p,r)
{
	hat.add(Point(center().x-0.6*radius(),center().y-1.2*radius()));
	hat.add(Point(center().x+0.6*radius(),center().y-1.2*radius()));
	hat.add(Point(center().x+radius(),center().y-0.6*radius()));
	hat.add(Point(center().x-radius(),center().y-0.6*radius()));
}

void Hat_Frowny::draw_lines() const
{
    if (color().visibility()) {
    	hat.draw_lines();
		Frowny::draw_lines();
	}
}

//Конструктор Smiley
Smiley::Smiley(Point p, int r)
:Circle(p,r),
l_eye(Point(center().x-radius()/3-radius()/7,center().y-radius()/3),"x"),
r_eye(Point(center().x+radius()/3,center().y-radius()/3),"__"),
smile(Point(center().x,center().y-radius()/3),radius()/1.5,radius(),220,320)
{
	l_eye.set_font_size(radius()/5);
	r_eye.set_font_size(radius()/5);
}

void Smiley::draw_lines() const
{
    if (color().visibility()) {
    	l_eye.draw_lines();
    	r_eye.draw_lines();
    	smile.draw_lines();
		Circle::draw_lines();
    }
}

//Конструктор Frowny
Frowny::Frowny(Point p, int r)
:Circle(p,r),
l_eye(Point(center().x-radius()/3-radius()/7,center().y-radius()/3),"/"),
r_eye(Point(center().x+radius()/3,center().y-radius()/3),"\\"),
smile(Point(center().x,center().y+radius()),radius()/1.5,radius(),40,140)
{
	l_eye.set_font_size(radius()/5);
	r_eye.set_font_size(radius()/5);
}

void Frowny::draw_lines() const
{
    if (color().visibility()) {
    	l_eye.draw_lines();
    	r_eye.draw_lines();
    	smile.draw_lines();
		Circle::draw_lines();
    }
}


//------------------------------------------------------------------------------
// Добавил класс дугу из главы 13 упражнение 1 (SVN version - 82)
void Arc::draw_lines() const
{
    if (color().visibility())
        fl_arc(point(0).x,point(0).y,w+w,h+h,a_b,a_e);
}


Point Arc::center()	const
{
	return Point(point(0).x+w,point(0).y+h);
}

void rotation (Arc& A)
{
	int b = A.angle_begin(), e = A.angle_end();
	if (e<360) {
		b += 90;
		e += 90;
	}
	else {
		b = 0;
		e = 90;
	}
	A.set_angle(b,e);
}
//------------------------------------------------------------------------------

int main ()
try
{
	Simple_window win(Point(100,100),1600,1400,"Chapter 14.");
	Hat_Smiley S(Point(300,300),200);
	S.set_style(Line_style(Line_style::solid,6));
	S.set_color(Color::red);
	win.attach(S);

	Hat_Frowny F(Point(800,500),200);
	F.set_style(Line_style(Line_style::solid,5));
	F.set_color(Color::blue);
	win.attach(F);

	win.wait_for_button();       // Display!
}
catch(exception& e) {
    return 1;
}
catch(...) {
    return 2;
}

