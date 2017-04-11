/* 
 * Chapter 19. Exercise 4.
 * Modify class Link from §17.9.3 to be a template with the type of value as
 * the template argument. Then redo exercise 13from Chapter 17 with Link<God>.
 * clear; g++ -o code code.cpp -std=c++0x && ./code
 */

#include <iostream> 
#include "code.h"

using namespace std;

template<typename T>
Link<T>* Link<T>::insert(Link<T>* n) // insert n before this object;
{
    if (n==nullptr) return this;
    if (this==nullptr) return n;
    n->succ = this;
    if (prev) prev->succ = n;
    n->prev = prev;
    prev = n;
    return n;
}

template<typename T>
Link<T>* Link<T>::add(Link<T>* n) // add n after this object;
{
    if (n==nullptr) return this;
    if (this==nullptr) return n;
    n->prev = this;
    if (succ) succ->prev = n;
    n->succ = succ;
    succ = n;
    return n;
}

template<typename T>
// places new element in its correct lexicographical position.
Link<T>* Link<T>::add_ordered(Link<T>* n) 
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

    Link<T>* p = this;
    while (p->prev)
        p = p->prev;
    Link<T>* head = p;
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

template<typename T>
Link<T>* Link<T>::find(const string& s)
{
    Link<T>* p = this;
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

template<typename T>
Link<T>* Link<T>::erase()
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

template<typename T>
void print_all(Link<T>* p)
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

template<typename T>
Link<T>* new_mythology_list(Link<T>* link, const string& myth)
{
    Link<T>* p = link, *tmp = nullptr, *new_mythology = nullptr;
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
    try {
        Link<God> *norse_gods = nullptr, *greek_gods = nullptr, *egypt_gods = nullptr;
        Link<God> *gods = new Link<God>{God{"Thor","Norse","","Hammer"}};
        gods = gods->insert(new Link<God>{God{"Odin", "Norse", "Eight-legged \
    flying horse called Sleipner", "Spear called Gungnir"}});
        gods = gods->insert(new Link<God>{God{"Zeus", "Greek", "", "lightning"}});
        gods = gods->insert(new Link<God>{God{"Taurt","Egypt","","Patroness of women and children"}});
        gods = gods->insert(new Link<God>{God{"Freia","Norse","Rides a chariot \
    pulled by two cats",""}});
        gods = gods->insert(new Link<God>{God{"Hera","Greek","Chariot drawn by peacocks",""}});
        gods = gods->insert(new Link<God>{God{"Athena","Greek","",""}});
        gods = gods->insert(new Link<God>{God{"Osiris","Egypt","","God of rebirth"}});
        gods = gods->insert(new Link<God>{God{"Mars","Greek","","God of war"}});
        gods = gods->insert(new Link<God>{God{"Poseidon","Greek","The chariot \
    pulled by sea horses","Trident"}});
        gods = gods->insert(new Link<God>{God{"Anubis","Egypt","","Conductor dead in the \
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

        //Test on error
        cout << endl << "Test on error\n";
        Link<int> *test = new Link<int>(1);
        test = test->insert(new Link<int>(2));
        test = test->insert(new Link<int>(3));
        test = test->insert(new Link<int>(4));
//        test = test->add_ordered(new Link<int>(5));     //error: request for member ‘name’ in ‘p->Link<int>::succ->Link<int>::value’, 
                                                        //which is of non-class type ‘int’
                                                        //error: request for member ‘name’ in ‘n->Link<int>::value’, which is
                                                        //of non-class type ‘int’
        while (test) {
            cout << test->value << endl;
            test = test->next();
        }

        Link<Type1> *test1 = new Link<Type1>(Type1());
        test1 = test1->insert(new Link<Type1>(Type1()));
//        test1 = test1->add_ordered(new Link<Type1>(Type1()));   //error: ‘struct Type1’ has no member named ‘name’
        return 0;
    }
    catch (...) {
        error("Catch error!");
        return 1;
    }
}
