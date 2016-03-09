/* 
 * Chapter 17. Exercise 14.
 * Could the “list of gods” example from §17.10.1 have been written using
 * a singly-linked list; that is, could we have left the prev member out of
 * Link? Why might we want to do that? For what kind of examples would it make
 * sense to use a singly-linked list? Re-implement that example using only
 * a singly-linked list.
 * clear; c++ -o code code.cpp -std=c++11 && ./code
 */

#include <iostream> 
#include "code.h"

using namespace std;

Link* Link::insert(Link* n) // insert n before this object;
{
    if (n==nullptr) return this;
    if (this==nullptr) return n;
    n->succ = this;
    return n;
}

Link* Link::add(Link* n) // add n after this object;
{
    if (n==nullptr) return this;
    if (this==nullptr) return n;
    n->succ = succ;
    succ = n;
    return n;
}

// places new element in its correct lexicographical position.
// Don`t working with singly-linked lists because not correct deleting
// the element from the old list
/*
Link* Link::add_ordered(Link* n) 
{
    if (n==nullptr) return this;
    // if *n already to other list, then:
    if (n->succ)
        n->succ->prev = n->prev;
    if (n->prev)
        n->prev->succ = n->succ;
    n->succ = nullptr;
    n->prev = nullptr;
    
    if (this==nullptr) return n;

    Link* p = this;
    while (p->prev)
        p = p->prev;
    Link* head = p;
    while (p) {
        if ( p->succ ) {
            if ( p->value.name < n->value.name && n->value.name < p->succ->value.name ) {
                p->add(n);
                return head;
            }
        }
        else {
            p->add(n);
            return head;
        }
        p = p->succ;
    }
}
*/

Link* Link::find(const string& s)
{
    Link* p = this;
    while (p) {
        if (p->value.name == s) return p;
        p = next();
    }
    return nullptr;
}

// Deleting can only from head in the singly-linked list
Link* Link::erase()
{
    Link* p = this->succ;
    delete this;
    return p;
}

void print_all(Link* p)
{
    if (p) {
        cout << "{\n";
        while (p) {
            cout << "name: " << p->value.name
                << ", mythology: " << p->value.mythology
                << ", vehicle: " << p->value.vehicle
                << ", weapon: " << p->value.weapon;
            if (p = p->next()) cout << endl;
        }
        cout << "\n}\n";
    }
}

/*
Link* new_mythology_list(Link* link, const string& myth)
{
    Link* p = link, *tmp = nullptr, *new_mythology = nullptr;
    while (p) {
        if ( p->value.mythology == myth ) {
            tmp = p;
            p = p->next();
            new_mythology = new_mythology->add_ordered(tmp);
        }
        else
            p = p->next();
    }
    return new_mythology;
}
*/

int main() 
{ 
    Link *norse_gods = new Link{God{"Thor","Norse","","Hammer"}};
    norse_gods = norse_gods->insert(new Link{God{"Odin", "Norse", "Eight-legged \
flying horse called Sleipner", "Spear called Gungnir"}});
    norse_gods = norse_gods->insert(new Link{God{"Freia","Norse","Rides a chariot \
pulled by two cats",""}});
    Link *greek_gods = greek_gods->insert(new Link{God{"Hera","Greek","Chariot drawn by peacocks",""}});
    greek_gods = greek_gods->insert(new Link{God{"Athena","Greek","",""}});
    greek_gods = greek_gods->insert(new Link{God{"Mars","Greek","","God of war"}});
    greek_gods = greek_gods->insert(new Link{God{"Poseidon","Greek","The chariot \
pulled by sea horses","Trident"}});

    cout << "Norse gods:\n";
    print_all(norse_gods);

    cout << "Greek gods:\n";
    print_all(greek_gods);

    return 0;
}
