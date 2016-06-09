/* 
 * Chapter 19. Exercise 13.
 * Write a Tracer class where its constructor prints a string and its
 * destructor prints a string. Give the strings asconstructor arguments. Use it
 * to see where RAII management objects will do their job (i.e., experiment
 * with Tracers aslocal objects, member objects, global objects, objects
 * allocated by new, etc.).
 * clear; g++ -o code code.cpp -std=c++0x && ./code
 */

#include "code.h"

//------------------------------------------------------------------------------
Tracer o("global object!");

//------------------------------------------------------------------------------
int main()
{
    Tracer ob("main object");

    Tracer* p = new Tracer("alloceted from free store object");

    Type2 t("class object");

    Tracer d = ob;

    delete p;   //call destructor
    return 0;
}
