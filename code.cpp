/* 
 * Chapter 18. Array drill.
 * clear; c++ -o code code.cpp -std=c++11 && ./code
 */

#include <iostream> 
#include <cstring>

using namespace std;

int ga[] = {1,2,4,8,16,32,64,128,256,512};

void f(int A[], int sz)
{
    int la[10];
    memcpy(la,ga,10*sizeof(int));
    for(int i=0;i<10;i++) {
        cout << la[i] << " ";
    }
    cout << endl;

    int *p = new int[sz];
    memcpy(p,A,sz*sizeof(int));

    for(int i=0;i<sz;i++) {
        cout << p[i] << " ";
    }

    delete[] p;
    cout << endl;
}

unsigned long fack(unsigned long n) // FACKtorial )))))
{
    if (n>0) return n*fack(n-1);
    else return 1;
}

int main()
{
    f(ga,10);

    int aa[10];
    for (int i=1; i<=10; i++)
        aa[i-1] = fack(i);
    f(aa,10);

    return 0;
}

