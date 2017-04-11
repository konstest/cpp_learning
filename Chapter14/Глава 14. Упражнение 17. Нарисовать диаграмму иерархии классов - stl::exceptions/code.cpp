/*
 Глава 14. Упражнение 17.
	The exceptions defined in the C++ standard library, such as exception, runtime_error, and out_of_range (§5.6.3),
are organized into a class hierarchy (with a useful virtual function what() returning a string supposedly explaining what
went wrong). Search your information sources for the C++ standard exception class hierarchy and draw a class hierarchy
diagram of it.

 clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code
*/

#include "code.h"
#include "cmath"

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
int main ()
try
{		//x_win = x_max()*0.7
	int x_win = 1920, y_win = y_max()*0.7;
	Simple_window win(Point((x_max()-x_win)/2,(y_max()-y_win)/2),x_win,y_win,"Chapter 14. Exercise 17.");

	Vector_ref<Rectangle> rects;
	Vector_ref<Text> labels;
	Vector_ref<Line> links;
	int links_height = 50;
	Point P,P1,P2,P3;
	
	rects.push_back(new Rectangle(Point(win.x_max()/2-75,150),150,50));
	win.attach(rects[rects.size()-1]);
	P = Point(rects[rects.size()-1].point(0).x+20,rects[rects.size()-1].point(0).y+30);
	labels.push_back(new Text(P,"exceptions"));
	labels[labels.size()-1].set_font_size(20);
	win.attach(labels[labels.size()-1]);
	P = Point(rects[rects.size()-1].point(0).x + rects[rects.size()-1].width()/2,
				rects[rects.size()-1].point(0).y + rects[rects.size()-1].height());
	links.push_back(new Line(P,Point(P.x,P.y+links_height)));
	win.attach(links[links.size()-1]);

	links.push_back(new Line(Point(P.x-170*3,P.y+links_height),Point(P.x-170*3+170*4.1,P.y+links_height)));
	P1 = links[links.size()-1].point(0);
	win.attach(links[links.size()-1]);

	links.push_back(new Line(links[links.size()-1].point(0),Point(links[links.size()-1].point(0).x,
			links[links.size()-1].point(0).y+links_height)));
	win.attach(links[links.size()-1]);
	rects.push_back(new Rectangle(Point(links[links.size()-1].point(1).x-85,links[links.size()-1].point(1).y),170,50));
	win.attach(rects[rects.size()-1]);
	P = Point(rects[rects.size()-1].point(0).x+10,rects[rects.size()-1].point(0).y+30);
	labels.push_back(new Text(P,"bad_exception"));
	labels[labels.size()-1].set_font_size(20);
	win.attach(labels[labels.size()-1]);

	links.push_back(new Line(Point(P1.x+170*1.1,P1.y),Point(P1.x+170*1.1,P1.y+links_height)));
	win.attach(links[links.size()-1]);
	rects.push_back(new Rectangle(Point(links[links.size()-1].point(1).x-85,links[links.size()-1].point(1).y),170,50));
	win.attach(rects[rects.size()-1]);
	P = Point(rects[rects.size()-1].point(0).x+30,rects[rects.size()-1].point(0).y+30);
	labels.push_back(new Text(P,"logic_error"));
	labels[labels.size()-1].set_font_size(20);
	win.attach(labels[labels.size()-1]);
	P = Point(rects[rects.size()-1].point(0).x + rects[rects.size()-1].width()/2,
				rects[rects.size()-1].point(0).y + rects[rects.size()-1].height());
	links.push_back(new Line(P,Point(P.x,P.y+links_height)));
	win.attach(links[links.size()-1]);

	links.push_back(new Line(Point(100,P.y+links_height),Point(P.x+24,P.y+links_height)));
	P2 = links[links.size()-1].point(0);
	win.attach(links[links.size()-1]);

	links.push_back(new Line(links[links.size()-1].point(0),Point(links[links.size()-1].point(0).x,
			links[links.size()-1].point(0).y+links_height)));
	win.attach(links[links.size()-1]);
	rects.push_back(new Rectangle(Point(links[links.size()-1].point(1).x-85,links[links.size()-1].point(1).y),170,50));
	win.attach(rects[rects.size()-1]);
	P = Point(rects[rects.size()-1].point(0).x+30,rects[rects.size()-1].point(0).y+30);
	labels.push_back(new Text(P,"length_error"));
	labels[labels.size()-1].set_font_size(20);
	win.attach(labels[labels.size()-1]);

	links.push_back(new Line(Point(P2.x+170*1.1,P2.y),Point(P2.x+170*1.1,P2.y+links_height)));
	win.attach(links[links.size()-1]);
	rects.push_back(new Rectangle(Point(links[links.size()-1].point(1).x-85,links[links.size()-1].point(1).y),170,50));
	win.attach(rects[rects.size()-1]);
	P = Point(rects[rects.size()-1].point(0).x+20,rects[rects.size()-1].point(0).y+30);
	labels.push_back(new Text(P,"domian_error"));
	labels[labels.size()-1].set_font_size(20);
	win.attach(labels[labels.size()-1]);

	links.push_back(new Line(Point(P2.x+170*2.2,P2.y),Point(P2.x+170*2.2,P2.y+links_height)));
	win.attach(links[links.size()-1]);
	rects.push_back(new Rectangle(Point(links[links.size()-1].point(1).x-90,links[links.size()-1].point(1).y),180,50));
	win.attach(rects[rects.size()-1]);
	P = Point(rects[rects.size()-1].point(0).x+2,rects[rects.size()-1].point(0).y+30);
	labels.push_back(new Text(P,"invalid_argument"));
	labels[labels.size()-1].set_font_size(20);
	win.attach(labels[labels.size()-1]);

	links.push_back(new Line(Point(P2.x+170*3.3,P2.y),Point(P2.x+170*3.3,P2.y+links_height)));
	win.attach(links[links.size()-1]);
	rects.push_back(new Rectangle(Point(links[links.size()-1].point(1).x-85,links[links.size()-1].point(1).y),170,50));
	win.attach(rects[rects.size()-1]);
	P = Point(rects[rects.size()-1].point(0).x+20,rects[rects.size()-1].point(0).y+30);
	labels.push_back(new Text(P,"out_of_range"));
	labels[labels.size()-1].set_font_size(20);
	win.attach(labels[labels.size()-1]);

	links.push_back(new Line(Point(P1.x+170*4.1,P1.y),Point(P1.x+170*4.1,P1.y+links_height)));
	win.attach(links[links.size()-1]);
	rects.push_back(new Rectangle(Point(links[links.size()-1].point(1).x-85,links[links.size()-1].point(1).y),170,50));
	win.attach(rects[rects.size()-1]);
	P = Point(rects[rects.size()-1].point(0).x+20,rects[rects.size()-1].point(0).y+30);
	labels.push_back(new Text(P,"runtime_error"));
	labels[labels.size()-1].set_font_size(20);
	win.attach(labels[labels.size()-1]);
	P = Point(rects[rects.size()-1].point(0).x + rects[rects.size()-1].width()/2,
				rects[rects.size()-1].point(0).y + rects[rects.size()-1].height());
	links.push_back(new Line(P,Point(P.x,P.y+links_height)));
	win.attach(links[links.size()-1]);

	links.push_back(new Line(Point(P.x-170*1.5,P.y+links_height),Point(P.x+170*1.5,P.y+links_height)));
	P3 = links[links.size()-1].point(0);
	int length = links[links.size()-1].point(1).x - links[links.size()-1].point(0).x;
	win.attach(links[links.size()-1]);

	links.push_back(new Line(links[links.size()-1].point(0),Point(links[links.size()-1].point(0).x,
			links[links.size()-1].point(0).y+links_height)));
	win.attach(links[links.size()-1]);
	rects.push_back(new Rectangle(Point(links[links.size()-1].point(1).x-85,links[links.size()-1].point(1).y),170,50));
	win.attach(rects[rects.size()-1]);
	P = Point(rects[rects.size()-1].point(0).x+30,rects[rects.size()-1].point(0).y+30);
	labels.push_back(new Text(P,"range_error"));
	labels[labels.size()-1].set_font_size(20);
	win.attach(labels[labels.size()-1]);

	links.push_back(new Line(Point(P3.x+length/2,P3.y),Point(P3.x+length/2,P3.y+links_height)));
	win.attach(links[links.size()-1]);
	rects.push_back(new Rectangle(Point(links[links.size()-1].point(1).x-85,links[links.size()-1].point(1).y),170,50));
	win.attach(rects[rects.size()-1]);
	P = Point(rects[rects.size()-1].point(0).x+10,rects[rects.size()-1].point(0).y+30);
	labels.push_back(new Text(P,"overflow_error"));
	labels[labels.size()-1].set_font_size(20);
	win.attach(labels[labels.size()-1]);

	links.push_back(new Line(Point(P3.x+length,P3.y),Point(P3.x+length,P3.y+links_height)));
	win.attach(links[links.size()-1]);
	rects.push_back(new Rectangle(Point(links[links.size()-1].point(1).x-85,links[links.size()-1].point(1).y),170,50));
	win.attach(rects[rects.size()-1]);
	P = Point(rects[rects.size()-1].point(0).x+5,rects[rects.size()-1].point(0).y+30);
	labels.push_back(new Text(P,"underflow_error"));
	labels[labels.size()-1].set_font_size(20);
	win.attach(labels[labels.size()-1]);

	win.wait_for_button();
}
catch(exception& e) {
    return 1;
}
catch(...) {
    return 2;
}

