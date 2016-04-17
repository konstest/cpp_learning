/* 
 * Headres file
 */

#include "std_lib_facilities.h"

struct Room {
    Room* tunnels[3];
    int number;
    Room(int k): number(k) { tunnels[0]=nullptr; tunnels[1]=nullptr; tunnels[2]=nullptr; }
};

class Cave {
    Room* cave[20];
    public:
    Cave();
    ~Cave();
    Room* room(int k) { return (0<k && k<21) ? cave[k-1] : nullptr; }
};

class Game {
    Cave cave;
    Room* initial_hunter_position;
    Room* initial_wampus_position;
    Room* hunter;
    Room* wumpus;
    Room* pits[2];
    Room* bats[2];
    void set_placement();
    void question();
    public:
    Game();
};
