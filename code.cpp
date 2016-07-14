//------------------------------------------------------------------------------
/* 
 * Chapter 19. Exercise 14.
 *  Provide a GUI interface and a bit of graphical output to the “Hunt the
 *  Wumpus” game from the exercises in Chapter 18.Take the input in an input
 *  box and display a map of the part of the cave currently known to the player
 *  in a window.
 * Chapter 18. Exercise 12.
 * The game “Hunt the Wumpus”
 * Implement a version of the game “Hunt the Wumpus.” “Hunt the Wumpus” (or
 * just “Wump”) is a simple (non-graphical)computer game originally invented by
 * Gregory Yob. The basic premise is that a rather smelly monster lives in
 * a darkcave consisting of connected rooms. Your job is to slay the wumpus
 * using bow and arrow. In addition to the wumpus, thecave has two hazards:
 * bottomless pits and giant bats. If you enter a room with a bottomless pit,
 * it’s the end of the gamefor you. If you enter a room with a bat, the bat
 * picks you up and drops you into another room. If you enter the room withthe
 * wumpus or he enters yours, he eats you. When you enter a room you will be
 * told if a hazard is nearby:
 *  “I smell the wumpus”: It’s in an adjoining room.
 *  “I feel a breeze”: One of the adjoining rooms is a bottomless pit.
 *  “I hear a bat”: A giant bat is in an adjoining room.
 *  For your convenience, rooms
 * are numbered. Every room is connected by tunnels to three other rooms. When
 * enteringa room, you are told something like “You are in room 12; there are
 * tunnels to rooms 1, 13, and 4; move or shoot?”Possible answers are m13
 * (“Move to room 13”) and s13-4-3 (“Shoot an arrow through rooms 13, 4, and
 * 3”). The rangeof an arrow is three rooms. At the start of the game, you have
 * five arrows. The snag about shooting is that it wakes up thewumpus and he
 * moves to a room adjoining the one he was in — that could be your
 * room.Probably the trickiest part of the exercise is to make the cave by
 * selecting which rooms are connected with which other rooms. You’ll probably
 * want to use a random number generator (e.g., randint() from
 * std_lib_facilities.h) tomake different runs of the program use different
 * caves and to move around the bats and the wumpus. Hint: Be sure to havea way
 * to produce a debug output of the state of the cave.
 *
 *  clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code
 */

#include "code.h"
#include "cmath"
#include <random>

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
//GUI constructor
Game_window::Game_window(Point xy, int w, int h, const string& title)
    :Window(w,h,title),
    quit_button(Point(x_max()-70,0), 70, 20, "Quit",
            [](Address, Address pw) { reference_to<Game_window>(pw).quit(); }),
    shot_button(Point(270,0), 50, 29, "SHOT",
            [](Address, Address pw) { reference_to<Game_window>(pw).shot(); }),
    shot_field(Point(120,0), 150, 30, ""),
    shot_count_label(Point(5,19),"Left arrows (5): "),
    tunnel_move_button_1(Point(75,30), 40,40,"", [](Address, Address pw) { reference_to<Game_window>(pw).select_tunnel_move_button_1(); } ),
    tunnel_move_button_2(Point(95,30), 40,40,"", [](Address, Address pw) { reference_to<Game_window>(pw).select_tunnel_move_button_2(); } ),
    tunnel_move_button_3(Point(115,30), 40,40,"", [](Address, Address pw) { reference_to<Game_window>(pw).select_tunnel_move_button_3();} ),
    cave(Point(w/2,h/2+h/15),h/9),
    game_output(Point(30,60),""),
    question_output(Point(w/3,h-30),""),
    icon_hunter(Point(w/2,h/2),25),
    icon_wumpus(Point(0,0),"WAMPUS"),
    icon_pit1(Point(0,0),"Pit"),
    icon_pit2(Point(0,0),"Pit"),
    icon_bat1(Point(0,0),"Bats"),
    icon_bat2(Point(0,0),"Bats"),
    q_yes(Point(w-w/3+30,h-50), 50,30, "YES", 
            [](Address, Address pw) { reference_to<Game_window>(pw).q_press(true); }),
    q_no(Point(w-w/3+100,h-50), 50,30, "NO", 
            [](Address, Address pw) { reference_to<Game_window>(pw).q_press(false); }),
    pits_info(Point(35,100),30),
    pits_info_text(Point(20,110),"informs about the pit"),
    bats_info(Point(35,150),30),
    bats_info_text(Point(20,160),"informs about the bats"),
    wumpus_info(Point(35,200),30),
    wumpus_info_text(Point(20,210),"informs about the wumpus"),
    input_info(Point(330,20),"write here the numbers of rooms: 2 7 17 8")
{
    /*
     *  Inital setup
     */
    srand(time(NULL));

    hunter = nullptr;
    wumpus = nullptr;
    pits[0] = nullptr;
    pits[1] = nullptr;
    bats[0] = nullptr;
    bats[1] = nullptr;

    set_placement();    //set up hunter, wumpus, bats & pits in random room
   
    int arrow_limit = 5;


    attach(quit_button);
    attach(shot_button);
    attach(shot_field);

    cave.set_color(Color::dark_red);
    cave.set_style(Line_style(Line_style::solid,3));
    attach(cave);

    game_output.set_font_size(25);
    game_output.set_color(Color::dark_red);
    attach(game_output);
    question_output.set_font_size(20);
    shot_count_label.set_font_size(14);
    attach(shot_count_label);

    ostringstream game_cout;
    game_cout << "HUNT THE WUMPUS";
    game_output.set_label(game_cout.str());
    game_cout.str("");

    /*
     * Debug
    attach(icon_hunter);
    attach(icon_wumpus);
    attach(icon_pit1);
    attach(icon_pit2);
    attach(icon_bat1);
    attach(icon_bat2);
    */

    attach(icon_hunter);

    attach(tunnel_move_button_1);
    attach(tunnel_move_button_2);
    attach(tunnel_move_button_3);

    pits_info.set_style(Line_style(Line_style::dash,7));
    attach(pits_info);
    pits_info_text.set_font_size(20);
    attach(pits_info_text);

    bats_info.set_style(Line_style(Line_style::dashdot,7));
    bats_info.set_color(Color::dark_green);
    attach(bats_info);
    bats_info_text.set_font_size(20);
    bats_info_text.set_color(Color::dark_green);
    attach(bats_info_text);

    wumpus_info.set_style(Line_style(Line_style::solid,7));
    wumpus_info.set_color(Color::red);
    attach(wumpus_info);
    wumpus_info_text.set_font_size(20);
    wumpus_info_text.set_color(Color::red);
    attach(wumpus_info_text);

    input_info.set_font_size(20);
    attach(input_info);
    game(-1);
}

//------------------------------------------------------------------------------
// Draw triangle for hunter icon
void Triangle::draw_lines() const
{
    Point p0 = rotate(270);
    Point p1 = rotate(30);
    Point p2 = rotate(150);
    fl_line(p0.x,p0.y,p1.x,p1.y);
    fl_line(p1.x,p1.y,p2.x,p2.y);
    fl_line(p2.x,p2.y,p0.x,p0.y);
}

Point Triangle::rotate(int angle) const
{
    double PI = 3.14159;
    double x = point(0).x - radius*cos(angle*PI/180);
    double y = point(0).y - radius*sin(angle*PI/180);
    if ( (x - (int)x) > 0.5 ) x++;  // precision
    if ( (y - (int)y) > 0.5 ) y++;  // precision
    return Point(x,y);
}

//------------------------------------------------------------------------------
// recalculate hunter posicion
void Game_window::hunter_move()
{
    icon_hunter.set_point(hunter->xy);
    tunnel_move_button_1.move(hunter->tunnels[0]->xy.x-20,hunter->tunnels[0]->xy.y-20);
    tunnel_move_button_2.move(hunter->tunnels[1]->xy.x-20,hunter->tunnels[1]->xy.y-20);
    tunnel_move_button_3.move(hunter->tunnels[2]->xy.x-20,hunter->tunnels[2]->xy.y-20);
    //show visible tunnels
    if (!hunter->visible) {
        hunter->visible = true;
        attach(cave.numeration[hunter->number-1]);
    }
    if(!hunter->tunnels[0]->visible)
        attach(cave.numeration[hunter->tunnels[0]->number-1]);
    if(!hunter->tunnels[1]->visible)
        attach(cave.numeration[hunter->tunnels[1]->number-1]);
    if(!hunter->tunnels[2]->visible)
        attach(cave.numeration[hunter->tunnels[2]->number-1]);
}

//------------------------------------------------------------------------------
/*          Game engine
 *  The logic for hunter & wumpus move and shooting
 */
void Game_window::game(const int tunnel)
{
    if (tunnel>-1)
        hunter = hunter->tunnels[tunnel];

    while (true) {
        hunter_move();

        ostringstream game_cout;

        /*              Processing hazards          */
        if (hunter == pits[0] || hunter == pits[1]) {
            game_output.set_label("");
            game_cout << "YYYIIIIEEEE . . . FELL IN PIT";
            game_cout << "  HA HA HA ~ YOU LOSE!";
            game_output.set_label(game_cout.str());
            game_cout.str("");
            if (hunter == pits[0])
                attach(icon_pit1);
            else
                attach(icon_pit2);
            question();
            return;
        }
        if (hunter == bats[0] || hunter == bats[1]) {
            game_output.set_label("");
            game_cout << "ZAP -- SUPER BAT SNATCH! ELSEWHEREVILLE FOR YOU!";
            game_output.set_label(game_cout.str());
            game_cout.str("");
            if (hunter == bats[0])
                attach(icon_bat1);
            else
                attach(icon_bat2);
            hunter = cave.room(rand()%20 + 1);
            hunter_move();
            continue;
        }
        if (hunter == wumpus) {
            game_cout << "TSK TSK TSK - WUMPUS GOT YOU! HA HA HA !!! YOU DEAD !!!";
            game_output.set_label(game_cout.str());
            attach(icon_wumpus);
            question();
            return;
        }

        /*          Prcoessing notice about a hazards          */
        bool added = false;
        for (int i=0;i<3;i++) {
            if (hunter->tunnels[i] == wumpus) {
                game_cout << " I SMELL A WUMPUS!!!";
                game_output.set_label(game_cout.str());
                for (int i=0; i<hazards.size(); i++) {
                    if ( hazards[i].point(0) == hunter->xy ) {
                        added = true;
                        break;
                    }
                }
                if (!added) {
                    hazards.push_back(new Circle(hunter->xy,50));
                    hazards[hazards.size()-1].set_color(Color::red);
                    hazards[hazards.size()-1].set_style(Line_style(Line_style::solid,5));
                    attach(hazards[hazards.size()-1]);
                    added = false;
                }
            }
            if (hunter->tunnels[i] == pits[0] || hunter->tunnels[i] == pits[1]) {
                game_cout << " I FEEL A BREEZE!";
                game_output.set_label(game_cout.str());
                for (int i=0; i<hazards.size(); i++) {
                    if ( hazards[i].point(0) == hunter->xy ) {
                        added = true;
                        break;
                    }
                }
                if (!added) {
                    hazards.push_back(new Circle(hunter->xy,40));
                    hazards[hazards.size()-1].set_style(Line_style(Line_style::dash,7));
                    attach(hazards[hazards.size()-1]);
                    added = false;
                }
            }
            if (hunter->tunnels[i] == bats[0] || hunter->tunnels[i] == bats[1]) {
                game_cout << " I HEAR A BAT!!";
                game_output.set_label(game_cout.str());
                for (int i=0; i<hazards.size(); i++) {
                    if ( hazards[i].point(0) == hunter->xy ) {
                        added = true;
                        break;
                    }
                }
                if (!added) {
                    hazards.push_back(new Circle(hunter->xy,30));
                    hazards[hazards.size()-1].set_style(Line_style(Line_style::dashdot,5));
                    hazards[hazards.size()-1].set_color(Color::dark_green);
                    attach(hazards[hazards.size()-1]);
                    added = false;
                }
            }
        }   //endfor (int i=0;i<3;i++)
        break;
    }   //endwhile(true)
}

/*
 *  Processing click on the shot_button
 */
void Game_window::shot()
{
    string rooms_numbers = shot_field.get_string();
    if (rooms_numbers != "") {

        ostringstream game_cout;

        /*      Reading rooms numbers       */
        stringstream game_cin{rooms_numbers};
        Room* path[5];     // the arrow path across rooms
        int i=0, c_room = 0;
        int old_r_number = -777;// protection from duble input room number
        int r_number = -1;
        while (i<5) {
            game_cin >> r_number;
            if ( (0 < r_number && r_number <= 20) && (old_r_number != r_number) ) {
                path[i] = cave.room(r_number);
                old_r_number = r_number;
                c_room++;
            }
            r_number = -1;
            i++;
        }/*     end reading rooms numbers   */

        /*      STARING SHOT:       */
        arrow_limit--;
        bool profit = false;
        for (int i=0; i<c_room; i++) {
            if ( i == 0 ) {  // if first room is not equal rooms in tunnels;
                if ( hunter->tunnels[0] != path[i] &&
                     hunter->tunnels[1] != path[i] &&
                     hunter->tunnels[2] != path[i] )  
                    path[i] = hunter->tunnels[rand() % 2];
            }
            else { // if pervious room not point to it room, then use a random direction
                if ( (path[i] != path[i-1]->tunnels[0]) &&
                    (path[i] != path[i-1]->tunnels[1]) &&
                    (path[i] != path[i-1]->tunnels[2]) )
                    path[i] = path[i-1]->tunnels[rand() % 2];
            }

            game_cout << " -> " << path[i]->number;

            //The gamer hit the wampus?
            if ( path[i] == wumpus ) {
                game_cout << "(HIT!)";
                game_cout << " AHA! YOU GOT THE WUMPUS!";
                attach(icon_wumpus);
                question();
                profit = true;
                break;
            }
            else
                game_cout << "(MISSED)";
            //The arrow hit to gamer?
            if ( path[i] == hunter ) {
                game_cout << endl << " OUCH! ARROW GOT YOU!";
                question();
                profit = true;
                break;
            }
        }/*     end shorting arrow      */

        /*      Testing count arrow     */
        if (arrow_limit == 0) {
            game_cout << "ARROW ENDED! TSK TSK TSK - WUMPUS GOT YOU!";
            question();
        }
        game_output.set_label(game_cout.str());
    
        /*      Wumpus wake up & move?    */
        if (!profit) {
            int wake = rand() % 100 + 1;
            if ( 1<= wake && wake <= 75 ) {  // 75% wake up & move wumpus
                wumpus = wumpus->tunnels[rand() % 2];
                icon_wumpus.set_point(Point(wumpus->xy.x-70,wumpus->xy.y-10));
                game(-1);
            }
        }
    }
    ostringstream oss;
    oss << "Left arrows (" << arrow_limit << "):";
    shot_count_label.set_label(oss.str());
    redraw();
}

//------------------------------------------------------------------------------
// add two point for tunnel drawing
void Cave::add(Point p1, Point p2)
{
    Shape::add(p1);
    Shape::add(p2);
}

// Calculate drawing all tunnels cave
void Cave::draw_lines() const
{
    for (int i=1, cave_count = 0; i<number_of_points(); i+=6, cave_count++) {
        if (cave[cave_count]->visible) {
            fl_line(point(i-1).x,point(i-1).y,point(i).x,point(i).y);
            fl_line(point(i+1).x,point(i+1).y,point(i+2).x,point(i+2).y);
            fl_line(point(i+3).x,point(i+3).y,point(i+4).x,point(i+4).y);
        }
    }
}

//------------------------------------------------------------------------------
//  Cave dodecahedron constructor
//  Setup rooms binding
Cave::Cave(Point center, int radius): c(center), r(radius)
{
    for (int i=0; i<20; i++)
        cave[i] = new Room(i+1);

    //insert links on hands
    //tunnels 1
    cave[0]->tunnels[0] = room(2);
    cave[0]->tunnels[1] = room(5);
    cave[0]->tunnels[2] = room(6);
    cave[0]->xy = rotation(center,radius,270);
    //tunnels 2
    cave[1]->tunnels[0] = room(1);
    cave[1]->tunnels[1] = room(7);
    cave[1]->tunnels[2] = room(3);
    cave[1]->xy = rotation(center,radius,342);
    //tunnels 3
    cave[2]->tunnels[0] = room(2);
    cave[2]->tunnels[1] = room(8);
    cave[2]->tunnels[2] = room(4);
    cave[2]->xy = rotation(center,radius,54);
    //tunnels 4
    cave[3]->tunnels[0] = room(3);
    cave[3]->tunnels[1] = room(9);
    cave[3]->tunnels[2] = room(5);
    cave[3]->xy = rotation(center,radius,126);
    //tunnels 5
    cave[4]->tunnels[0] = room(4);
    cave[4]->tunnels[1] = room(10);
    cave[4]->tunnels[2] = room(1);
    cave[4]->xy = rotation(center,radius,198);
    //tunnels 6
    cave[5]->tunnels[0] = room(1);
    cave[5]->tunnels[1] = room(11);
    cave[5]->tunnels[2] = room(15);
    cave[5]->xy = rotation(center,radius*2,270);
    //tunnels 7
    cave[6]->tunnels[0] = room(2);
    cave[6]->tunnels[1] = room(11);
    cave[6]->tunnels[2] = room(12);
    cave[6]->xy = rotation(center,radius*2,342);
    //tunnels 8
    cave[7]->tunnels[0] = room(3);
    cave[7]->tunnels[1] = room(12);
    cave[7]->tunnels[2] = room(13);
    cave[7]->xy = rotation(center,radius*2,54);
    //tunnels 9
    cave[8]->tunnels[0] = room(4);
    cave[8]->tunnels[1] = room(13);
    cave[8]->tunnels[2] = room(14);
    cave[8]->xy = rotation(center,radius*2,126);
    //tunnels 10
    cave[9]->tunnels[0] = room(5);
    cave[9]->tunnels[1] = room(14);
    cave[9]->tunnels[2] = room(15);
    cave[9]->xy = rotation(center,radius*2,198);
    //tunnels 11
    cave[10]->tunnels[0] = room(6);
    cave[10]->tunnels[1] = room(16);
    cave[10]->tunnels[2] = room(7);
    cave[10]->xy = rotation(center,radius*3,306);
    //tunnels 12
    cave[11]->tunnels[0] = room(7);
    cave[11]->tunnels[1] = room(17);
    cave[11]->tunnels[2] = room(8);
    cave[11]->xy = rotation(center,radius*3,18);
    //tunnels 13
    cave[12]->tunnels[0] = room(8);
    cave[12]->tunnels[1] = room(18);
    cave[12]->tunnels[2] = room(9);
    cave[12]->xy = rotation(center,radius*3,90);
    //tunnels 14
    cave[13]->tunnels[0] = room(9);
    cave[13]->tunnels[1] = room(19);
    cave[13]->tunnels[2] = room(10);
    cave[13]->xy = rotation(center,radius*3,162);
    //tunnels 15
    cave[14]->tunnels[0] = room(10);
    cave[14]->tunnels[1] = room(20);
    cave[14]->tunnels[2] = room(6);
    cave[14]->xy = rotation(center,radius*3,234);
    //tunnels 16
    cave[15]->tunnels[0] = room(11);
    cave[15]->tunnels[1] = room(20);
    cave[15]->tunnels[2] = room(17);
    cave[15]->xy = rotation(center,radius*4,306);
    //tunnels 17
    cave[16]->tunnels[0] = room(16);
    cave[16]->tunnels[1] = room(12);
    cave[16]->tunnels[2] = room(18);
    cave[16]->xy = rotation(center,radius*4,18);
    //tunnels 18
    cave[17]->tunnels[0] = room(17);
    cave[17]->tunnels[1] = room(13);
    cave[17]->tunnels[2] = room(19);
    cave[17]->xy = rotation(center,radius*4,90);
    //tunnels 19
    cave[18]->tunnels[0] = room(18);
    cave[18]->tunnels[1] = room(14);
    cave[18]->tunnels[2] = room(20);
    cave[18]->xy = rotation(center,radius*4,162);
    //tunnels 20
    cave[19]->tunnels[0] = room(19);
    cave[19]->tunnels[1] = room(15);
    cave[19]->tunnels[2] = room(16);
    cave[19]->xy = rotation(center,radius*4,234);

    /*          Calculate numbers position        */
    ostringstream number;
    for (int i=0; i<20; i++) {
        add(cave[i]->xy,cave[i]->tunnels[0]->xy);
        add(cave[i]->xy,cave[i]->tunnels[1]->xy);
        add(cave[i]->xy,cave[i]->tunnels[2]->xy);
        number << i+1;
        numeration.push_back(new Text(Point(cave[i]->xy.x-13,cave[i]->xy.y+7),number.str()));
        numeration[numeration.size()-1].set_font_size(20);
        numeration[numeration.size()-1].set_font(Font::helvetica_bold);
        numeration[numeration.size()-1].set_color(Color::blue);
        number.str("");
    }
}

//  Destructor, deleting pointers 
Cave::~Cave()
{
    for (int i=0; i<20; i++)
        delete cave[i];
}

//------------------------------------------------------------------------------
// Question about repeat the game with new setting.
void Game_window::question()
{
    tunnel_move_button_1.hide();
    tunnel_move_button_2.hide();
    tunnel_move_button_3.hide();
    shot_button.hide();
    ostringstream game_cout;
    game_cout << "START AGAIN WITH THE SAME SET-UP (Y/N)? ";
    question_output.set_label(game_cout.str());
    attach(question_output);
    attach(q_yes);
    attach(q_no);
}

/*
 *  Processing click on a q_yes & q_no buttons
 */
void Game_window::q_press(bool yes)
{
    if (yes) {
        // Set same configuration
        hunter = initial_hunter_position;
        wumpus = initial_wampus_position;
    }
    else
        set_placement();    // calculate new game configuration

    arrow_limit = 5;
    shot_count_label.set_label("Left arrows (5):");

    for (int i=0; i<hazards.size(); i++)
        detach(hazards[i]);

    for (int i=0; i<20; i++) {
        cave.room(i+1)->visible = false;
        detach(cave.numeration[i]);
    }
    detach(icon_wumpus);
    icon_wumpus.set_point(Point(wumpus->xy.x-70,wumpus->xy.y-10));
    detach(icon_bat1);
    detach(icon_bat2);
    detach(icon_pit1);
    detach(icon_pit2);
    detach(q_yes);
    detach(q_no);
    detach(question_output);

    tunnel_move_button_1.show();
    tunnel_move_button_2.show();
    tunnel_move_button_3.show();
    shot_button.show();
    game(-1);
    redraw();
}

//------------------------------------------------------------------------------
//set not cross random
void Game_window::set_placement()
{
    /*
    hunter = cave.room(7); 
    wumpus = cave.room(13);
    pits[0] = cave.room(15);        // for DEBUG
    pits[1] = cave.room(10);
    bats[0] = cave.room(8);
    bats[1] = cave.room(19);
    */
    hunter = cave.room(rand() % 20 + 1);
    while (true) {
        wumpus = cave.room(rand() % 20 + 1);
        if (wumpus != hunter) break;
    }
    while (true) {
        pits[0] = cave.room(rand() % 20 + 1);
        pits[1] = cave.room(rand() % 20 + 1);
        if (pits[0] != pits[1])
            if (pits[0] != wumpus && pits[0] != hunter &&
                pits[1] != wumpus && pits[1] != hunter ) break;
    }
    while (true) {
        bats[0] = cave.room(rand() % 20 + 1);
        bats[1] = cave.room(rand() % 20 + 1);
        if (bats[0] != bats[1])
            if (bats[0] != wumpus && bats[0] != hunter &&
                bats[1] != wumpus && bats[1] != hunter &&
                bats[0] != pits[0] && bats[1] != pits[0] &&
                bats[0] != pits[1] && bats[1] != pits[1] ) break;
    }

    /*      setup game icon on the game field       */
    initial_hunter_position = hunter;
    initial_wampus_position = wumpus;

    icon_hunter.set_style(Line_style(Line_style::solid,10));
    icon_hunter.set_color(Color::yellow);

    icon_wumpus.set_point(Point(wumpus->xy.x-70,wumpus->xy.y-10));
    icon_wumpus.set_font_size(30);
    icon_wumpus.set_font(Font::times_bold);
    icon_wumpus.set_color(Color::red);

    icon_pit1.set_point(Point(pits[0]->xy.x-30,pits[0]->xy.y-10));
    icon_pit1.set_font_size(30);
    icon_pit1.set_font(Font::times_bold);
    icon_pit2.set_point(Point(pits[1]->xy.x-30,pits[1]->xy.y-10));
    icon_pit2.set_font_size(30);
    icon_pit2.set_font(Font::times_bold);

    icon_bat1.set_point(Point(bats[0]->xy.x-40,bats[0]->xy.y-10));
    icon_bat1.set_font_size(30);
    icon_bat1.set_font(Font::times_bold);
    icon_bat1.set_color(Color::dark_green);
    icon_bat2.set_point(Point(bats[1]->xy.x-40,bats[1]->xy.y-10));
    icon_bat2.set_font_size(30);
    icon_bat2.set_font(Font::times_bold);
    icon_bat2.set_color(Color::dark_green);
}

//------------------------------------------------------------------------------
//  Spec for reading from the shot_field
string In_box::get_string()
{
    Fl_Input& pi = reference_to<Fl_Input>(pw);
    const char* p = pi.value();
    return string(p);
}

//------------------------------------------------------------------------------

int main()
try {
    Game_window win(Point(100,100),1300,768,"Hunt the wumpus.");
    return gui_main();
}
catch(exception& e) {
    cerr << "exception: " << e.what();
    return 1;
}
catch (...) {
    cerr << "Some exception";
    return 2;
}

//------------------------------------------------------------------------------
