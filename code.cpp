/* 
 * Chapter 17. Exercise 11.
 * Complete the “list of gods” example from §17.10.1 and run it.
 * clear; c++ -o code code.cpp -std=c++11 && ./code
 */

#include <iostream> 
#include "code.h"

using namespace std;

Link* Link::insert(Link* n) // insert n before this object; return n
{
    if (n==nullptr) return this;
    if (this==nullptr) return n;
    n->succ = this;
    if (prev) prev->succ = n;
    n->prev = prev;
    prev = n;
    return n;
}

Link* Link::add(Link* n) // add n after this object; return n
{
    if (n==nullptr) return this;
    if (this==nullptr) return n;
    n->prev = this;
    if (succ) succ->prev = n;
    n->succ = succ;
    succ = n;
    return n;
}

Link* Link::find(const string& s)
{
    Link* p = this;
    while (p) {
        if (p->value == s) return p;
        p = next();
    }
    p = this;
    while (p) {
        if (p->value == s) return p;
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
    return nullptr;
}

void print_all(Link* p)
{
    cout << "{ ";
    while (p) {
        cout << p->value;
        if (p=p->next()) cout << ", ";
    }
    cout << " }";
}

int main() 
{ 
    Link* norse_gods = new Link{"Thor"};
    norse_gods = norse_gods->insert(new Link{"Odin"});
    norse_gods = norse_gods->insert(new Link{"Zeus"});
    norse_gods = norse_gods->insert(new Link{"Freia"});
    Link* greek_gods = new Link{"Hera"};
    greek_gods = greek_gods->insert(new Link{"Athena"});
    greek_gods = greek_gods->insert(new Link{"Mars"});
    greek_gods = greek_gods->insert(new Link{"Poseidon"});

    cout << "Benchmark data:\n";
    print_all(norse_gods);
    cout << "\n";
    print_all(greek_gods);
    cout << "\n";

    Link* p = greek_gods->find("Mars");
    if (p) p->value = "Ares";

    Link* p2 = norse_gods->find("Zeus");
    if (p2) {
        if (p2==norse_gods) norse_gods = p2->next();
        p2->erase();
        greek_gods = greek_gods->insert(p2);
    }

    cout << "Changed data:\n";
    print_all(norse_gods);
    cout << "\n";
    print_all(greek_gods);
    cout << "\n";

    return 0;
}
