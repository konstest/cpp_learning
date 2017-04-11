/* 
 * Chapter 18. Exercise 12.
 * The game “Hunt the Wumpus”
 */

#include "std_lib_facilities.h"
#include <algorithm>
#include "code.h"

//------------------------------------------------------------------------------
// Destrucror
Cave::~Cave()
{
    for (int i=0; i<20; i++)
        delete cave[i];
}

//------------------------------------------------------------------------------
//Cave dodecahedron constructor
Cave::Cave()
{
    for (int i=0; i<20; i++)
        cave[i] = new Room(i+1);

    //insert links on hands
    //tunnels 1
    cave[0]->tunnels[0] = room(2);
    cave[0]->tunnels[1] = room(5);
    cave[0]->tunnels[2] = room(6);
    //tunnels 2
    cave[1]->tunnels[0] = room(8);
    cave[1]->tunnels[1] = room(3);
    cave[1]->tunnels[2] = room(1);
    //tunnels 3
    cave[2]->tunnels[0] = room(2);
    cave[2]->tunnels[1] = room(10);
    cave[2]->tunnels[2] = room(4);
    //tunnels 4
    cave[3]->tunnels[0] = room(3);
    cave[3]->tunnels[1] = room(12);
    cave[3]->tunnels[2] = room(5);
    //tunnels 5
    cave[4]->tunnels[0] = room(1);
    cave[4]->tunnels[1] = room(4);
    cave[4]->tunnels[2] = room(14);
    //tunnels 6
    cave[5]->tunnels[0] = room(7);
    cave[5]->tunnels[1] = room(1);
    cave[5]->tunnels[2] = room(15);
    //tunnels 7
    cave[6]->tunnels[0] = room(17);
    cave[6]->tunnels[1] = room(8);
    cave[6]->tunnels[2] = room(6);
    //tunnels 8
    cave[7]->tunnels[0] = room(9);
    cave[7]->tunnels[1] = room(2);
    cave[7]->tunnels[2] = room(7);
    //tunnels 9
    cave[8]->tunnels[0] = room(18);
    cave[8]->tunnels[1] = room(10);
    cave[8]->tunnels[2] = room(8);
    //tunnels 10
    cave[9]->tunnels[0] = room(9);
    cave[9]->tunnels[1] = room(11);
    cave[9]->tunnels[2] = room(3);
    //tunnels 11
    cave[10]->tunnels[0] = room(10);
    cave[10]->tunnels[1] = room(19);
    cave[10]->tunnels[2] = room(12);
    //tunnels 12
    cave[11]->tunnels[0] = room(11);
    cave[11]->tunnels[1] = room(13);
    cave[11]->tunnels[2] = room(4);
    //tunnels 13
    cave[12]->tunnels[0] = room(12);
    cave[12]->tunnels[1] = room(20);
    cave[12]->tunnels[2] = room(14);
    //tunnels 14
    cave[13]->tunnels[0] = room(5);
    cave[13]->tunnels[1] = room(13);
    cave[13]->tunnels[2] = room(15);
    //tunnels 15
    cave[14]->tunnels[0] = room(6);
    cave[14]->tunnels[1] = room(14);
    cave[14]->tunnels[2] = room(16);
    //tunnels 16
    cave[15]->tunnels[0] = room(17);
    cave[15]->tunnels[1] = room(15);
    cave[15]->tunnels[2] = room(20);
    //tunnels 17
    cave[16]->tunnels[0] = room(18);
    cave[16]->tunnels[1] = room(7);
    cave[16]->tunnels[2] = room(16);
    //tunnels 18
    cave[17]->tunnels[0] = room(19);
    cave[17]->tunnels[1] = room(9);
    cave[17]->tunnels[2] = room(17);
    //tunnels 19
    cave[18]->tunnels[0] = room(18);
    cave[18]->tunnels[1] = room(11);
    cave[18]->tunnels[2] = room(20);
    //tunnels 20
    cave[19]->tunnels[0] = room(13);
    cave[19]->tunnels[1] = room(19);
    cave[19]->tunnels[2] = room(16);
}

//------------------------------------------------------------------------------
// Question about repeat the game with new setting.
void Game::question()
{
    string answer;
    while (answer != "Y" && answer != "N") {
        cout << "SAME SET-UP (Y/N)? ";
        cin >> answer;
    }
    if (answer == "Y") {
        hunter = initial_hunter_position;
        wumpus = initial_wampus_position;
    }
    else {
        set_placement();
    }
}

//------------------------------------------------------------------------------
// Constructor where init & run the game
Game::Game()
{
    srand(time(NULL));

    hunter = nullptr;
    wumpus = nullptr;
    pits[0] = nullptr;
    pits[1] = nullptr;
    bats[0] = nullptr;
    bats[1] = nullptr;

    set_placement();    //set up hunter, wumpus, bats & pits in random room
    initial_hunter_position = hunter;
    initial_wampus_position = wumpus;
    
    int arrow_limit = 5;

    /*
     *  Start the game!
     */
    cout << endl;
    cout << "\t###############\n";
    cout << "\tHUNT THE WUMPUS\n";
    cout << "\t###############\n";
    cout << endl;
    
    while (true) {
        /*
        // FOR DEBUG
        cout << "WUMPUS: " << wumpus->number << endl;
        cout << "BATS[0]: " << bats[0]->number << endl;
        cout << "BATS[1]: " << bats[1]->number << endl;
        cout << "PITS[0]: " << pits[0]->number << endl;
        cout << "PITS[1]: " << pits[1]->number << endl;
        */
        //processing hazards
        if (hunter == pits[0] || hunter == pits[1]) {
            cout << "YYYIIIIEEEE . . . FELL IN PIT\n";
            cout << "HA HA HA ~ YOU LOSE!\n";
            question();
            cout << endl;
        }
        if (hunter == bats[0] || hunter == bats[1]) {
            cout << "ZAP -- SUPER BAT SNATCH! ELSEWHEREVILLE FOR YOU!\n";
            hunter = cave.room(rand()%20 + 1);
            cout << endl;
            continue;   //do not go to next
        }
        if (hunter == wumpus) {
            cout << "TSK TSK TSK - WUMPUS GOT YOU!\n";
            cout << "HA HA HA !!! YOU DEAD !!!\n";
            question();
            cout << endl;
        }
        //Notice about a hazards
        for (int i=0;i<3;i++) {
            if (hunter->tunnels[i] == wumpus)
                cout << "I SMELL A WUMPUS\n";
            if (hunter->tunnels[i] == pits[0] || hunter->tunnels[i] == pits[1])
                cout << "I FEEL A BREEZE\n";
            if (hunter->tunnels[i] == bats[0] || hunter->tunnels[i] == bats[1])
                cout << "I HEAR A BAT\n";
        }
        
        cout << "YOU ARE IN ROOM " << hunter->number << endl;
        cout << "TUNNELS LEAD TO " << hunter->tunnels[0]->number << "\t" 
             << hunter->tunnels[1]->number << "\t" << hunter->tunnels[2]->number << endl;
        //Select action
        string action;
        while ( action != "S" && action != "M" ) {
            cout << endl << "SHOT(S) OR MOVE(M)? ";
            cin >> action;
        }
        if (action == "M") {
            int room = -1;
            while ( room != hunter->tunnels[0]->number && room != hunter->tunnels[1]->number &&
                    room != hunter->tunnels[2]->number ) {
                cout << "WHERE TO? ";
                cin >> room;
            }
            //Move to this tunnel
            hunter = cave.room(room);
        }
        else {  // SHOT
            //Set shooting parameters:
            int c_room = -1;
            while ( c_room<1 || 5<c_room ) {
                cout << "NUMBER OF ROOMS - THE WAY AN ARROW(1-5): ";
                cin >> c_room;
            }
            Room* path[c_room];     // the arrow path across rooms
            int old_r_number = -777;// protection from duble input room number
            for(int i=0; i<c_room; i++) {
                int r_number = -1;
                while ( r_number < 1 || 20 < r_number || old_r_number == r_number ) {
                    cout << "ROOM #: ";
                    cin >> r_number;
                }
                old_r_number = r_number;
                path[i] = cave.room(r_number);
            }
            //STARING SHOT:
            arrow_limit--;
            cout << "ARROW FLY TO";
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

                cout << " -> " << path[i]->number;

                //The gamer hit the wampus?
                if ( path[i] == wumpus ) {
                    cout << "(HIT!)";
                    cout << endl << "AHA! YOU GOT THE WUMPUS!\n";
                    cout << "HEE HEE HEE - THE WUMPUS'LL GETCHA NEXT TIME!!\n";
                    return;
                }
                else
                    cout << "(MISSED)";
                //The arrow hit to gamer?
                if ( path[i] == hunter ) {
                    cout << endl << "OUCH! ARROW GOT YOU!\n";
                    question();
                    break;
                }
            }   //shorting arrow
            //Wampus wake up & move?
            int wake = rand() % 100 + 1;
            if ( 1<= wake && wake <= 75 )   // 75% wake up & move wumpus
                wumpus = wumpus->tunnels[rand() % 2];
        }
        cout << endl;
        if (arrow_limit == 0) {
            cout << "ARROW ENDED! TSK TSK TSK - WUMPUS GOT YOU!\n";
            question();
            cout << endl;
        }
    }
}

//------------------------------------------------------------------------------
//set not cross random
void Game::set_placement()
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
}

int main()
{
    try {
        Game Hunt_of_Wumpus;
        return 0;
    }
    catch(...) {
        return 1;
    }
}

//------------------------------------------------------------------------------
