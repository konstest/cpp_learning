//
// Заглолвочный файл
//
// clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "std_lib_facilities.h"
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"
#include <list>
#include <FL/Fl_Output.H>
#include <sstream>

//------------------------------------------------------------------------------
struct Room {
    Room*   tunnels[3];
    Point   xy;
    bool    visible;
    int     number;
    Room(int k): xy(Point(0,0)), visible(false), number(k) { tunnels[0]=nullptr; tunnels[1]=nullptr; tunnels[2]=nullptr; }
};

class Cave : public Shape {
    Room* cave[20];
    public:
    Vector_ref<Text> numeration;
    Point c;
    int r;
    Cave(Point, int);   //indicate center & radius
    ~Cave();
    void draw_lines() const;
    void add(Point p1, Point p2);      // add a line defined by two points
    Room* room(int k) { return (0<k && k<21) ? cave[k-1] : nullptr; }
};

//------------------------------------------------------------------------------
struct Text2 : Text {
    Text2(Point x, const string& s): Text(x,s) {}
    void    set_point(Point P) { Text::set_point(0,P); }
};

//------------------------------------------------------------------------------
struct Circle2 : Circle {
    Circle2(Point x, int r): Circle(x,r) {}
    void    set_point(Point P) { Circle::set_point(0,P); }
};

//------------------------------------------------------------------------------
struct Triangle : Shape {
    Triangle(Point x, int r): radius(r) { add(x); }
    void    set_point(Point P) { Shape::set_point(0,P); }
    void    draw_lines() const;
private:
    Point   rotate(int)  const;
    int radius;
};

//------------------------------------------------------------------------------
//
struct Button2 : Button {
    Button2(Point xy, int w, int h, const string& label, Callback cb)
        : Button(xy,w,h,label,cb) {}
    void move(int dx,int dy) { hide(); pw->position(dx, dy); show(); }
};

//------------------------------------------------------------------------------
struct Game_window : Window {
    Game_window (Point xy, int w, int h, const string& title);
private:
    // Widgets:
    Button  quit_button;
    Button  shot_button;
    In_box  shot_field;
    Button2 tunnel_move_button_1;
    Button2 tunnel_move_button_2;
    Button2 tunnel_move_button_3;
    Cave    cave;
    Room*   hunter;
    Room*   initial_hunter_position;
    Triangle icon_hunter;
    Room*   wumpus;
    Room*   initial_wampus_position;
    Text2   icon_wumpus;
    Room*   pits[2];
    Text2   icon_pit1;
    Text2   icon_pit2;
    Room*   bats[2];
    Text2   icon_bat1;
    Text2   icon_bat2;
    Text    game_output;
    Text    shot_count_label;
    Text    question_output;
    Vector_ref<Circle> hazards;
    Circle  pits_info;
    Text    pits_info_text;
    Circle  bats_info;
    Text    bats_info_text;
    Circle  wumpus_info;
    Text    wumpus_info_text;
    Text    input_info;
    int     arrow_limit = 5;

    Button  q_yes;      //  buttons for question procedure
    Button  q_no;       //
    
    void    quit() { hide(); }	// curious FLTK idiom for delete window
    void    shot(); 
    void    select_tunnel_move_button_1() { game(0); redraw(); }
    void    select_tunnel_move_button_2() { game(1); redraw(); }
    void    select_tunnel_move_button_3() { game(2); redraw(); }
    void    q_press(bool);
    void    set_placement();    //setup inital coordinats for hnter, wumpus, pits & bats
    void    question();
    void    game(const int);
    void    hunter_move();

    const int length = 100;
};

