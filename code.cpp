/* 
 * Chapter 18. Standard library vector drill.
 * clear; c++ -o code code.cpp -std=c++11 && ./code
 */

#include "code.h"

using namespace std;

vector<int> gv{1,2,4,8,16,32,64,128,256,512};

void f(vector<int> v)
{
    vector<int> lv{gv};
    for(int i=0;i<lv.size();i++) {
        cout << lv[i] << " ";
    }
    cout << endl;

    vector<int> lv2{v};
    for(int i=0;i<lv2.size();i++) {
        cout << lv2[i] << " ";
    }
    cout << endl;
}

unsigned long fack(unsigned long n) // FACKtorial )))))
{
    if (n>0) return n*fack(n-1);
    else return 1;
}

int main()
{
    f(gv);

    vector<int> vv;
    for (int i=1; i<=10; i++)
        vv.push_back(fack(i));
    f(vv);

    return 0;
}

