/* 
 * Chapter 17. Exercise 13.
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
    if (prev) prev->succ = n;
    n->prev = prev;
    prev = n;
    return n;
}

Link* Link::add(Link* n) // add n after this object;
{
    if (n==nullptr) return this;
    if (this==nullptr) return n;
    n->prev = this;
    if (succ) succ->prev = n;
    n->succ = succ;
    succ = n;
    return n;
}

// places new element in its correct lexicographical position.
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

Link* Link::find(const string& s)
{
    Link* p = this;
    while (p) {
        if (p->value.name == s) return p;
        p = next();
    }
    p = this;
    while (p) {
        if (p->value.name == s) return p;
        p = previous();
    }
    return nullptr;
}

Link* Link::erase()
{
    if (prev) prev->succ = succ;
    if (succ) succ->prev = prev;
    if (succ)
        return succ;
    else if (prev)
        return prev;
    delete this;
    return nullptr;
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
            if (p=p->next()) cout << endl;
        }
        cout << "\n}\n";
    }
}

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

int main() 
{ 
    Link *norse_gods = nullptr, *greek_gods = nullptr, *egypt_gods = nullptr;
    Link* gods = new Link{God{"Thor","Norse","","Hammer"}};
    gods = gods->insert(new Link{God{"Odin", "Norse", "Eight-legged \
flying horse called Sleipner", "Spear called Gungnir"}});
    gods = gods->insert(new Link{God{"Zeus", "Greek", "", "lightning"}});
    gods = gods->insert(new Link{God{"Taurt","Egypt","","Patroness of women and children"}});
    gods = gods->insert(new Link{God{"Freia","Norse","Rides a chariot \
pulled by two cats",""}});
    gods = gods->insert(new Link{God{"Hera","Greek","Chariot drawn by peacocks",""}});
    gods = gods->insert(new Link{God{"Athena","Greek","",""}});
    gods = gods->insert(new Link{God{"Osiris","Egypt","","God of rebirth"}});
    gods = gods->insert(new Link{God{"Mars","Greek","","God of war"}});
    gods = gods->insert(new Link{God{"Poseidon","Greek","The chariot \
pulled by sea horses","Trident"}});
    gods = gods->insert(new Link{God{"Anubis","Egypt","","Conductor dead in the \
underworld kingdom, oberegatel cemeteries and mummies"}});

    cout << "All gods:\n";
    print_all(gods);
    
    cout << endl;
    norse_gods = new_mythology_list(gods,"Norse");
    greek_gods = new_mythology_list(gods,"Greek");
    egypt_gods = new_mythology_list(gods,"Egypt");

    cout << "Norse gods:\n";
    print_all(norse_gods);

    cout << "Greek gods:\n";
    print_all(greek_gods);

    cout << "Egypt gods:\n";
    print_all(egypt_gods);

    return 0;
}
