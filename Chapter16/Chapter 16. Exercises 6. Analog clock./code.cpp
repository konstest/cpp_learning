/*
 Chapter 16. Exercises 6.
	6. Make an “analog clock,” that is, a clock with hands that move. You get the time of day from the operating system through
a library call. A major part of this exercise is to find the functions that give you the time of day and a way of waiting for a
short period of time (e.g., a second for a clock tick) and to learn to use them based on the documentation you found. Hint:
clock(), sleep().

 clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code
*/

#include "code.h"
#include "cmath"
#include <ctime>	/* time_t, struct tm, difftime, time, mktime */

using namespace Graph_lib;
using namespace std;

//------------------------------------------------------------------------------

Point rotation (Point P, int r, int angle)
{
	static const double PI = 3.141592653;
	double x = P.x - r*cos(angle*PI/180);
	double y = P.y - r*sin(angle*PI/180);
	if ( (x-(int)x) >= 0.5) x++;
	if ( (y-(int)y) >= 0.5) y++;
	return Point(x,y);
}

//------------------------------------------------------------------------------

Arrow::Arrow (Point P, int l, int w, int a)    
: center(P), length(l), width(w), angle(a)
{
	//Добавляем точки стрелки
	add(rotation(P,w,a-90));
	add(rotation(P,l,a));
	add(rotation(P,w,a+90));
}

//------------------------------------------------------------------------------

void Arrow::turn (int a)
{
	//Добавляем точки стрелки на "a" грудусов относительно текущего положения
	set_point(0,rotation(center,width,a-90));
	set_point(1,rotation(center,length,a));
	set_point(2,rotation(center,width,a+90));
}

//------------------------------------------------------------------------------

My_window::My_window(Point xy, int w, int h, const string& title)
    :Window(xy,w,h,title),
    quit_button(Point(x_max()-50,0), 50, 25, "Quit", 
[](Address, Address pw) { reference_to<My_window>(pw).quit(); }),
    current_date(Point(0,20), ""),
    big(Point(w/2,h/2),h/2-h/10),
	hour(Point(w/2,h/2),(h/2-h/10)*0.5,(h/2-h/10)/15,90),
	minute(Point(w/2,h/2),(h/2-h/10)*0.75,(h/2-h/10)/15,90),
	second(Point(w/2,h/2),h/2-h/10,(h/2-h/10)/30,90),
	small(Point(w/2,h/2),(h/2-h/10)/15)
{
	big.set_color(Color::blue);
	small.set_fill_color(Color::yellow);
	second.set_fill_color(81);
	hour.set_fill_color(Color::yellow);
	minute.set_fill_color(Color::yellow);
    attach(quit_button);
    attach(current_date);
	attach(big);
	attach(second);
	attach(minute);
	attach(hour);
	attach(small);
/*http://www.cplusplus.com/reference/ctime/tm/
struct tm is contains:
Member		Type	Meaning					Range
tm_sec		int	seconds after the minute	0-61*
tm_min		int	minutes after the hour		0-59
tm_hour		int	hours since midnight		0-23
tm_mday		int	day of the month			1-31
tm_mon		int	months since January		0-11
tm_year		int	years since 1900	
tm_wday		int	days since Sunday			0-6
tm_yday		int	days since January 1		0-365
tm_isdst	int	Daylight Saving Time flag	
*/

	//drawing циферблат
	Point P;
	for (int i=0; i<12; i++) {
		stringstream ss;
		ss << i+1;
		P = rotation(Point(w/2,h/2),h/2-h/10,90+(i+1)*30);
		digits.push_back(new Text(Point(P.x-15,P.y+10), ss.str()) );
		digits[digits.size()-1].set_font_size(30);
		digits[digits.size()-1].set_color(Color::dark_red);
		attach(digits[digits.size()-1]);
		ss.str("");
	}

	turn();
    Fl::add_timeout(0.1, timer_callback, (void*)this);
}

//------------------------------------------------------------------------------
// installation of our arrows to the position of current localtime
void My_window::turn()
{
	//Calculate date & time for turn our arrows
    time_t rawtime;
	rawtime = time(NULL);	//eq: time(&rawtime);
	struct tm * timeinfo;
	timeinfo = localtime (&rawtime);
    stringstream ss;
	ss << " DATE:" << timeinfo->tm_mday << "." << timeinfo->tm_mon+1 << "." << timeinfo->tm_year+1900
	<< " TIME:" << timeinfo->tm_hour << ":" << timeinfo->tm_min << ":" << timeinfo->tm_sec;
    current_date.set_label(ss.str());
	current_date.set_font_size(20);

	static int pre_hour;
	static int pre_minute;
	static int pre_second;
	if (pre_hour != timeinfo->tm_hour) {
		hour.turn(90+timeinfo->tm_hour*30+timeinfo->tm_min*0.5);
		pre_hour = timeinfo->tm_hour;
	}
	if (pre_minute != timeinfo->tm_min) {
		minute.turn(90+timeinfo->tm_min*6);
		pre_minute = timeinfo->tm_min;
	}
	if (pre_second != timeinfo->tm_sec) {
		second.turn(90+timeinfo->tm_sec*6);
		pre_second = timeinfo->tm_sec;
	}
}

//------------------------------------------------------------------------------

int main()
try {
    My_window win(Point(100,100),400,400,"Chapter 16.");
	return gui_main();
}
catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Some exception\n";
    return 2;
}

//------------------------------------------------------------------------------
