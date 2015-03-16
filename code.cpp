#include <iostream>
#include <fstream>

using namespace std;

//
int main () {

cout << "Введите количество миль: ";
double mill;
cin >> mill;
cout << mill << " миль в км -> " << mill*1.609 << endl;

return 0;
}
