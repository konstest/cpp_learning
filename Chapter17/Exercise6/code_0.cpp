/* 
 * Chapter 17 Exercises 6
 * c++ -o code code.cpp -std=c++11
 */
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void allocate_memory()
{
    char* f = new char[9999999999999999999];
    while (true)
        f = new char[9999999999999999999];
}

int main ()
{
    allocate_memory();
    return 0;
}
