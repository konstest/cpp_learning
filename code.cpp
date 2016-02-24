/* 
 * Chapter 17.5 "Try This"
 * Write a little program using base classes and members where you define the
 * constructors and destructors to output a line of information when they are
 * called. Then, create a few objects and see how their constructors
 * and destructors are called.
 * c++ -o code code.cpp -std=c++11
 */
#include <iostream>
#include <vector>

using namespace std;

double* init_d(double dd, string str)
{
    cout << str+" " << dd << " init_d initializator" << endl;
    return new double(dd);
}

class Parent {
    public:
        void date() { cout << *d << endl; } 
        virtual ~Parent() { cout << "Parent " << *d <<  " DEstructor" << endl; delete d; }
        Parent(double dd): d(init_d(dd,"Parent")) { cout << "Parent " << *d <<  " constructor" << endl; }
    private:
        double* d;
};

class Child : public Parent {
    public:
        void date() { cout << *r << endl; }
        virtual ~Child() { cout << "Child " << *r <<  " DEstructor" << endl; delete r; }
        Child(double dd): r(init_d(dd,"Child")), Parent(dd+1) { cout << "Child " << *r <<  " constructor" << endl; }
    private:
        double* r;
};

Parent* fct()
{
    Parent* p = new Child(7);
    return p;
}

int main ()
{
    cout << "Parent* q = fct();" << endl;
    Parent* q = fct();
    cout << "Parent k(3);" << endl;
    Parent k(5);
    cout << "Child f(2);" << endl;
    Child f(2);
    cout << "delete q;" << endl;
    delete q;
    cout << "return 0;" << endl;
    return 0;
}
