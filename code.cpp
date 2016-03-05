/* 
 * Chapter 17 Exercises 9 
 * Which way does the stack grow: up (toward higher addresses) or down (toward
 * lower addresses)? Which way does the free store initially grow (that is, 
 * before you use delete)? Write a program to determine the answers.
 * Answers:
 *      STACK grow to DOWN;
 *      FREE stoew grow to UP.
 * c++ -o code code.cpp -std=c++11 && ./code
 */
#include <iostream> 
#include <vector> 

using namespace std;

void func1()
{
    cout << "STACK STORE:" << endl;
    int q = 203;
    cout << "int[" << sizeof(q) << "] q[" << &q << "] = " << q << ";" << endl;
    vector<int> e;
    cout << "vector<int>[" << sizeof(e) << "] e[" << &e << "];\n";
    cout << "FREE STORE:" << endl;
    e.push_back(88);
    cout << "e.push_back(" << e[e.size()-1] << ")[" << &e[e.size()-1] << "];" << endl;
    e.push_back(8);
    cout << "e.push_back(" << e[e.size()-1] << ")[" << &e[e.size()-1] << "];" << endl;
}

void func2()
{
    cout << "STACK STORE:" << endl;
    vector<int> e;
    cout << "vector<int>[" << sizeof(e) << "] e[" << &e << "];\n";
    short q = 233;
    cout << "short[" << sizeof(q) << "] q[" << &q << "] = " << q << ";" << endl;
    char C[15] = "192.168.0.7";
    cout << "char[" << sizeof(C) << "] C[" << &C << "] = " << C << ";" << endl;
    cout << "FREE STORE:" << endl;
    e.push_back(88);
    cout << "e.push_back(" << e[e.size()-1] << ")[" << &e[e.size()-1] << "];" << endl;
}

void func3()
{
    cout << "STACK STORE:" << endl;
    double q = 2;
    cout << "double[" << sizeof(q) << "] q[" << &q << "] = " << q << ";" << endl;
    vector<int> e;
    cout << "vector<int>[" << sizeof(e) << "] e[" << &e << "];\n";
    cout << "FREE STORE:" << endl;
    e.push_back(18);
    cout << "e.push_back(" << e[e.size()-1] << ")[" << &e[e.size()-1] << "];" << endl;
    e.push_back(19);
    cout << "e.push_back(" << e[e.size()-1] << ")[" << &e[e.size()-1] << "];" << endl;
    e.push_back(20);
    cout << "e.push_back(" << e[e.size()-1] << ")[" << &e[e.size()-1] << "];" << endl;
}

int main() 
{ 
    cout << "\tfunc1(): \n";
    func1();
    cout << "\tfunc2(): \n";
    func2();
    cout << "\tfunc3(): \n";
    func3();
    cout << "\n\tAnswers:\n";
    cout << "STACK grow to DOWN;\n";
    cout << "FREE stoew grow to UP.\n";
    return 0;
}

