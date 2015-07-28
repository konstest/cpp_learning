//
// Глава 13. Упражнение 6. Написать программу рисующую диаграмму классов, похожую на
// ту, которая изображена в разделе 12.6. Используется доработанный класс Box
// из упражнения 13.2 с возможностью установки Метки.
// c++ -o code code.cpp GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp -lfltk -lfltk_images -std=c++11

#include "code.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------
void Box::draw_lines() const
{
    if (color().visibility()) {
    	//draw arcs
        fl_arc(point(0).x,point(0).y,a_w+a_w,a_h+a_h,90,180);
        fl_arc(point(0).x+w-(a_w+a_w),point(0).y,a_w+a_w,a_h+a_h,0,90);
        fl_arc(point(0).x,point(0).y+h-(a_h+a_h),a_w+a_w,a_h+a_h,180,270);
        fl_arc(point(0).x+w-(a_w+a_w),point(0).y+h-(a_h+a_h),a_w+a_w,a_h+a_h,270,360);
		//draw lines
        fl_line(point(0).x,point(0).y+a_h,point(0).x,point(0).y+h-a_h);
        fl_line(point(0).x+w,point(0).y+a_h,point(0).x+w,point(0).y+h-a_h);
        fl_line(point(0).x+a_w,point(0).y,point(0).x+w-a_w,point(0).y);
        fl_line(point(0).x+a_w,point(0).y+h,point(0).x+w-a_w,point(0).y+h);
        //Draw text lable
		int ofnt = fl_font();
		int osz = fl_size();
		fl_font(fnt.as_int(),fnz);
		fl_draw(lable.c_str(),point(0).x+w/6,point(0).y+h*3/5);
		fl_font(ofnt,osz);
    }
}

//------------------------------------------------------------------------------

Arrow::Arrow (Point p1, Point p2)
: r1(r1), r2(r2)
{
	//Узнаём длину отрезка (нашей стрелки)
	double width_arrow = sqrt( double(pow(p2.x-p1.x,2) + pow(p2.y-p1.y,2)) );
	r1 = width_arrow/10;
	r2 = r1/2;
	add(p1);
	add(p2);
}

//------------------------------------------------------------------------------

void Arrow::draw_lines()	const
{
	if (color().visibility()) {
		//Узнаём длину отрезка (нашей стрелки)
		double width_arrow = sqrt( double(pow(point(1).x-point(0).x,2) + pow(point(1).y-point(0).y,2)) );
		//через отношение ищем координаты нашей второй окружности лежащей на
		//расстоянии r1 от точки point(1), точки куда указывает стрелка
		double lambda = r1 / width_arrow;
		//Узнаём координаты второй окружности с радиусом r2
		int xM = (point(1).x + lambda*point(0).x)/(1+lambda);
		int yM = (point(1).y + lambda*point(0).y)/(1+lambda);
		//Вычислим координаты точек линий стрелки (>) для этого возмём единичный 
		//вектор от P1 до P2, повернём его на +90 градусов для P3 (-90 для P4) и умножим на r2.
		int P3x = xM + (point(1).y - yM)*r2/r1;
		int P3y = yM - (point(1).x - xM)*r2/r1;
		int P4x = xM - (point(1).y - yM)*r2/r1;
		int P4y = yM + (point(1).x - xM)*r2/r1;
		//рисуем указатель (>)
	    fl_line(point(1).x,point(1).y,P3x,P3y );
	    fl_line(point(1).x,point(1).y,P4x,P4y );
	}
	//Дорисовываем саму (длинную) линию стрелки
	Shape::draw_lines();
}

//------------------------------------------------------------------------------

Point n(const Box& box)
{
	return Point(box.point(0).x+box.width()/2, box.point(0).y);
}

Point s(const Box& box)
{
	return Point(box.point(0).x+box.width()/2, box.point(0).y + box.height());
}

//------------------------------------------------------------------------------

int main ()
try
{
    Simple_window win(Point(10,10),1200,900,"Chapter 13. Exercise 6:");

    Arrow A(Point(400,700),Point(1000,150));
    A.set_color(Color::yellow);
    A.set_style(Line_style(Line_style::solid,9));
    win.attach(A);

    Arrow B(Point(400,700),Point(1000,150));
    B.set_color(Color::blue);
    B.set_style(Line_style(Line_style::solid,2));
    win.attach(B);

	int arrow_w = 13, arrow_h = 5;
	int height = 30;
	Box Lable_Window( Point(95,30), 100, height, 10, 10, "Window", Font(Font::screen_bold), 15 );
	Lable_Window.set_style(Line_style(Line_style::solid,2));
	win.attach(Lable_Window);

	Box Lable_Line_style( Point(230,30), 130, height, 10, 10, "Line_style", Font(Font::screen_bold), 15 );
	Lable_Line_style.set_style(Line_style(Line_style::solid,2));
	win.attach(Lable_Line_style);

	Box Lable_Color( Point(400,30), 70, height, 10, 10, "Color", Font(Font::screen_bold), 15 );
	Lable_Color.set_style(Line_style(Line_style::solid,2));
	win.attach(Lable_Color);

	Box Lable_Simple_Window( Point(60,height*3), 170, height, 10, 10, "Simple_Window", Font(Font::screen_bold), 15 );
	Lable_Simple_Window.set_style(Line_style(Line_style::solid,2));
	win.attach(Lable_Simple_Window);
	
	Arrow SimpleWindow_to_Windows(n(Lable_Simple_Window), s(Lable_Window),arrow_w,arrow_h);
	SimpleWindow_to_Windows.set_style(Line_style(Line_style::solid,2));
	win.attach(SimpleWindow_to_Windows);

	Box Lable_Shape( Point(270,height*3-15), 80, height, 10, 10, "Shape", Font(Font::screen_bold), 15 );
	Lable_Shape.set_style(Line_style(Line_style::solid,2));
	win.attach(Lable_Shape);

	Box Lable_Point( Point(400,height*3), 70, height, 10, 10, "Point", Font(Font::screen_bold), 15 );
	Lable_Point.set_style(Line_style(Line_style::solid,2));
	win.attach(Lable_Point);


	Box Lable_Line( Point(30,height*7), 50, height, 10, 10, "Line", Font(Font::screen_bold), 15 );
	Lable_Line.set_style(Line_style(Line_style::solid,2));
	win.attach(Lable_Line);

	Box Lable_Lines( Point(100,height*7), 60, height, 10, 10, "Lines", Font(Font::screen_bold), 15 );
	Lable_Lines.set_style(Line_style(Line_style::solid,2));
	win.attach(Lable_Lines);

	Box Lable_Polygon( Point(170,height*7), 100, height, 10, 10, "Polygon", Font(Font::screen_bold), 15 );
	Lable_Polygon.set_style(Line_style(Line_style::solid,2));
	win.attach(Lable_Polygon);

	Box Lable_Axis( Point(285,height*7), 50, height, 10, 10, "Axis", Font(Font::screen_bold), 15 );
	Lable_Axis.set_style(Line_style(Line_style::solid,2));
	win.attach(Lable_Axis);

	Box Lable_Rectangle( Point(345,height*7), 120, height, 10, 10, "Rectangle", Font(Font::screen_bold), 15 );
	Lable_Rectangle.set_style(Line_style(Line_style::solid,2));
	win.attach(Lable_Rectangle);

	Box Lable_Text( Point(475,height*7), 60, height, 10, 10, "Text", Font(Font::screen_bold), 15 );
	Lable_Text.set_style(Line_style(Line_style::solid,2));
	win.attach(Lable_Text);

	Box Lable_Image( Point(550,height*7), 70, height, 10, 10, "Image", Font(Font::screen_bold), 15 );
	Lable_Image.set_style(Line_style(Line_style::solid,2));
	win.attach(Lable_Image);

	Point P = s(Lable_Shape);
	Arrow Line_to_Shape(n(Lable_Line), Point(P.x-35,P.y),arrow_w,arrow_h);
	Line_to_Shape.set_style(Line_style(Line_style::solid,2));
	win.attach(Line_to_Shape);

	Arrow Lines_to_Shape(n(Lable_Lines), Point(P.x-22,P.y),arrow_w,arrow_h);
	Lines_to_Shape.set_style(Line_style(Line_style::solid,2));
	win.attach(Lines_to_Shape);

	Arrow Lines_to_Polygon(n(Lable_Polygon), Point(P.x-11,P.y),arrow_w,arrow_h);
	Lines_to_Polygon.set_style(Line_style(Line_style::solid,2));
	win.attach(Lines_to_Polygon);

	Arrow Lines_to_Axis(n(Lable_Axis), Point(P.x,P.y),arrow_w,arrow_h);
	Lines_to_Axis.set_style(Line_style(Line_style::solid,2));
	win.attach(Lines_to_Axis);

	Arrow Lines_to_Rectangle(n(Lable_Rectangle), Point(P.x+11,P.y),arrow_w,arrow_h);
	Lines_to_Rectangle.set_style(Line_style(Line_style::solid,2));
	win.attach(Lines_to_Rectangle);

	Arrow Lines_to_Text(n(Lable_Text), Point(P.x+22,P.y),arrow_w,arrow_h);
	Lines_to_Text.set_style(Line_style(Line_style::solid,2));
	win.attach(Lines_to_Text);

	Arrow Lines_to_Image(n(Lable_Image), Point(P.x+35,P.y),arrow_w,arrow_h);
	Lines_to_Image.set_style(Line_style(Line_style::solid,2));
	win.attach(Lines_to_Image);

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

