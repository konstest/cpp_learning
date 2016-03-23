/* 
 * Chapter 18. Exercise 9.
 * Consider the memory layout in §17.4. Write a program that tells the order in
 * which static storage, the stack, and the free store are laid out in memory.
 * In which direction does the stack grow: upward toward higher addresses or
 * downward toward lower addresses? In an array on the free store, are elements
 * with higher indices allocated at higher or lower addresses?
 */

#include "code.h"

using namespace std;

int variable_in_statick_storage = 1;
int variable_in_statick_storage1 = 11;
int variable_in_statick_storage2 = 111;
const int const_variable_in_statick_storage = 2;
static int static_variable_in_statick_storage = 3;
static const int static_const_variable_in_statick_storage = 4;

int main()
{
    int variable_in_stack_storage = 1;
    int variable_in_stack_storage1 = 11;
    int variable_in_stack_storage2 = 111;
    const int const_variable_in_stack_storage = 2;
    static int static_variable_in_stack_storage = 3;
    static const int static_const_variable_in_stack_storage = 4;

    cout << "STATIC STORAGE:\n";
    cout << "int: " << &variable_in_statick_storage << endl;
    cout << "int1: " << &variable_in_statick_storage1 << endl;
    cout << "int2: " << &variable_in_statick_storage2 << endl;
    cout << "const int: " << &const_variable_in_statick_storage << endl;
    cout << "static int: " << &static_variable_in_statick_storage << endl;
    cout << "static const int: " << &static_const_variable_in_statick_storage << endl;

    cout << endl;

    cout << "STACK STORAGE:\n";
    cout << "int: " << &variable_in_stack_storage << endl;
    cout << "int1: " << &variable_in_stack_storage1 << endl;
    cout << "int2: " << &variable_in_stack_storage2 << endl;
    cout << "const int: " << &const_variable_in_stack_storage << endl;
    cout << "static int: " << &static_variable_in_stack_storage << endl;
    cout << "static const int: " << &static_const_variable_in_stack_storage << endl;
    cout << "In which direction does the stack grow?\n";
    cout << "\tAnswer: Downward toward lower addresses.\n";

    cout << endl;

    int* variable_in_free_storage = new int(1);
    int* variable_in_free_storage1 = new int(11);
    int* variable_in_free_storage2 = new int(111);
    const int* const_variable_in_free_storage = new const int(2);
    cout << "FREE STORAGE:\n";
    cout << "int*: " << &*variable_in_free_storage << endl;
    cout << "int1*: " << &*variable_in_free_storage1 << endl;
    cout << "int2*: " << &*variable_in_free_storage2 << endl;
    cout << "const int*: " << &*const_variable_in_free_storage << endl;

    cout << endl;

    int* ptr = new int[10000];
    cout << "int* ptr = new int[10000];\n";
    cout << "&*ptr: " << &*ptr << endl;
    cout << "&ptr[0]: " << &ptr[0] << endl;
    cout << "&ptr[1]: " << &ptr[1] << endl;
    cout << "&ptr[2]: " << &ptr[2] << endl;
    cout << "&ptr[9998]: " << &ptr[9998] << endl;
    cout << "&ptr[9999]: " << &ptr[9999] << endl;
    cout << "Error! &ptr[10000]: " << &ptr[10000] << endl;
    cout << "Question: In an array on the free store, are elements with \
higher indices allocated at higher or lower addresses?\n";
    cout << "\tAnswer: Allocated at higher address.\n";
    
    return 0;
}
