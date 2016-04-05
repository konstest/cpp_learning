/* 
 * Chapter 18. Exercise 11.
 * Look up (e.g., on the web) skip list and implement that kind of list. This
 * is not an easy exercise.
 */

#include "std_lib_facilities.h"
#include <algorithm>
#include "code.h"

//------------------------------------------------------------------------------
//  Constructors
Elem::Elem()
{
    right = nullptr; 
    left = nullptr; 
    up_lvl = nullptr; 
    down_lvl = nullptr; 
    value = nullptr; 
}

Elem::Elem(double val)
{
    right = nullptr; 
    left = nullptr; 
    up_lvl = nullptr; 
    down_lvl = nullptr; 
    value = new double(val); 
}

Elem::Elem(Elem* el)
{
    right = nullptr;
    if (el->left && el->left->left)
        left = el->left->left->up_lvl;
    else
        left = nullptr;
    up_lvl = nullptr; 
    down_lvl = el;
    el->up_lvl = this;
    value = el->value;
}

//------------------------------------------------------------------------------
// Create ordered list from vector of double
Skip_list::Skip_list(vector<double> V)
{
    sort(V.begin(),V.end());
    Elem *ptr;
    head = new Elem();
    for (int i=0; i<V.size(); i++) {
        if ( i == 0 ) {                         // first element
            head->right = new Elem(V[i]);
            head->right->left = head;
            ptr = head->right;
        }
        else if ( i > 0 && V[i] != V[i-1] ) {   //eliminate duplicates
            ptr->right = new Elem(V[i]);
            ptr->right->left = ptr;
            ptr = ptr->right;
        }
    }

    levels_count = 1;

    //Adding new levels
    Elem *rptr = nullptr;
    while (head->right->right) {
        rptr = head;
        head = new Elem(head);
        ptr = head;
        while (rptr) {
            if (rptr->right && rptr->right->right) {
                rptr = rptr->right->right;
            }
            else
                break;
            ptr->right = new Elem(rptr);
            ptr = ptr->right;
        }
        levels_count++;
    }
}

//------------------------------------------------------------------------------
// Out put Skip_list
void Skip_list::print()
{
    Elem *ptr = head, *rptr = nullptr;
    while (ptr) {
        if (ptr->right) {
            rptr = ptr->right;
            while (rptr) {
                cout << *rptr->value << " ";
                rptr = rptr->right;
            }
        }
        cout << endl;
        ptr = ptr->down_lvl;
    }
}

//------------------------------------------------------------------------------
// Search element in the skip_list
Elem* Skip_list::search(double s_val)
{
    Elem *ptr = head;
    while (ptr) {
        if (ptr->right) {
            if (s_val == *ptr->right->value)
                return ptr->right;
            if (s_val < *ptr->right->value)
                ptr = ptr->down_lvl;
            else
                ptr = ptr->right;
        }
        else
            ptr = ptr->down_lvl;
    }
    return nullptr; //not found
}

//------------------------------------------------------------------------------
//Insert new value at the list.
void Skip_list::insert(double i_val)
{
    Elem *ptr = head;
    while (ptr) {
        if (ptr->right) {
            if (i_val == *ptr->right->value)
                return;         // adding element is already in the list
            if (i_val < *ptr->right->value) {
                if (ptr->down_lvl)
                    ptr = ptr->down_lvl;
                else
                    break;
            }
            else {
                ptr = ptr->right;
            }
        }
        else {
            if (ptr->down_lvl)
                ptr = ptr->down_lvl;
            else
                break;
        }
    }

    //Add on low level the new element:
    Elem *tmp = new Elem(i_val);
    if (ptr->right) {
        tmp->right = ptr->right;
        tmp->right->left = tmp;
    }
    ptr->right = tmp;
    tmp->left = ptr;

    //randomize insert in the upper levels:
    srand (time(NULL));
    int lvl_c = 0;
    while (rand() % 2) {
        lvl_c++;
        if (lvl_c == levels_count) break;   //we are on the upper level
//        cout << "UP ON NEW LVL!\n";
        tmp->up_lvl = new Elem();
        tmp->up_lvl->value = tmp->value;
        tmp->up_lvl->down_lvl = tmp;
        //insert to left link
        Elem *tf = tmp;
        while (tf) {
            if (tf->left->up_lvl) {
                tmp->up_lvl->left = tf->left->up_lvl;
                tmp->up_lvl->right = tf->left->up_lvl->right;
                if (tf->left->up_lvl->right && tf->left->up_lvl->right->left)
                    tf->left->up_lvl->right->left = tmp->up_lvl;
                tf->left->up_lvl->right = tmp->up_lvl;
                break;
            }
            else
                tf = tf->left;
        }
        tmp = tmp->up_lvl;
    }
}

//------------------------------------------------------------------------------
int main()
{
    Skip_list slist({34,45,5,234,6,32,8,1023,89,0,6,5,243,345,56,21});
//    Skip_list slist({34,45,5,6,32,8,0,6,5,56,21,22,23,24});
//    Skip_list slist({0,1,2,3,4,5});

    cout << "Output list:\n";
    slist.print();
    cout << "Search in list:\n";
    cout << "Value 243 ";
    Elem* e = slist.search(243);
    if (e)
        cout << "found!" << endl;
    else
        cout << "not found :(" << endl;
    cout << "Insert new value: 25\n";
    slist.insert(25);
    slist.print();

    return 0;
}

//------------------------------------------------------------------------------
