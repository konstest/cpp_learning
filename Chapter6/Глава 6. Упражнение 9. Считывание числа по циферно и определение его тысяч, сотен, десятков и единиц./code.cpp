/*
	c++ -o code code.cpp -std=c++98
	Глава 6. Упражнение 9. Считывание числа по циферно и определение его 
	тысяч, сотен, десятков и единиц.
*/
#include <iostream>         // std::cerr
#include <stdexcept>        // std::out_of_range
#include <vector>           // std::vector
#include <string>		    // std::string
#include "std_lib_facilities.h"

using namespace std;
const int v_size = 4;		//Размер вектора для отгадывания

//------------------------------------------------------------------------------
vector<int> input_int()
{
    vector<int> T;
    char ch;
    string num="";
    int i=0;
    cout << "Введите целое число состоящее максимум из 4-ёх разрядов:\n";
    ch = cin.get();
    while (ch != '\n')
    {
        if ( int('0')<=int(ch) && int(ch)<=int('9') && i<4 )
        {
            i++;
            num += ch;
            T.push_back(ch-'0');
            ch = cin.get();
        }
        else
            error("Ошибка ввода данных.");
    }
    return T;
}

//------------------------------------------------------------------------------
//Переводит вектор целочисленных чисел в одно 10-тичное число
int to_number(vector<int> T)
{
    int k = 0,j=1;
    for (int i=T.size(); i>0; i--)
        {
        k += T[i-1]*j;
        j *= 10;
        }
    return k;
}

//------------------------------------------------------------------------------
int main ()
try {
    vector<int> N;
    //INPUT
    N = input_int();
    
    switch( N.size() )
        {
        case 1:
            cout << N[0] << " - это " << N[0] << " единиц.\n";
            break;
        case 2:
            cout << to_number(N) << " - это " << N[0] << " десятков, "
            << N[1] << " единиц.\n";
            break;
        case 3:
            cout << to_number(N) << " - это " << N[0] << " сотен, "
            << N[1] << " десятков, " << N[2] << " единиц.\n";
            break;
        case 4:
            cout << to_number(N) << " - это " << N[0] << " тысяч, " << N[1] 
            << " сотен, "<< N[2] << " десятков, " << N[3] << " единиц.\n";
            break;
        }
return 0;
}
catch (exception& e) {
  cerr << "Ошибка-прерывание: " << e.what() << '\n'; 
  return 1;
}
catch (...) {
  cerr << "ОШИБКА: Не известное исключение!\n";
  return 2;
}

