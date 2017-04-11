/* 
 * Chapter 17 Exercises 6 
 * c++ -o code code.cpp -std=c++11 && ./code
 */
#include <iostream> 

using namespace std;

int main() 
{ 
    unsigned long i = 0; 
    int* a = nullptr; 
    try { 
        unsigned long k = 0, j = 0;
        while (true) {
            a = new int;
            i++;
            j = (i*4)/(1024*1024);  //convert to Mbyte
            if (k != j) {
                cout << "(Ptr a = " << a;
                cout << ", Allocated: " << k << "Mb)\n";
                k = j;
            }
        }
    }
    catch( std::bad_alloc )
    {
        cout << "No memory!!!" << endl;
        cout << "Ptr a = " << a << endl;
        cout << "Allocated: " << (unsigned long)(i*8)/(1024*2) << "Mb" << endl;
    }

    return 0;
}
