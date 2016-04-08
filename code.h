/* 
 * Заглолвочный файл
 */

#include "std_lib_facilities.h"


struct Elem {
    Elem *right;
    Elem *left;
    Elem *down_lvl;
    Elem *up_lvl;
    double *value;
    Elem();
    Elem(double);
    Elem(Elem*);
    ~Elem() { if (value) delete value; }
};

class Skip_list {
    Elem* head;
    int levels_count;
    public:
    ~Skip_list();
    Skip_list(vector<double>);      //initialization vector for simplicity
    Elem* search(double);
    void insert(double);
    void print();
};
