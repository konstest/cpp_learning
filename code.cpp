//c++ -o code code.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
	double min, max, a, summ;
	string ed_izm;
	int i;
	vector<double> v;
	bool k;
	cout << "Введите числа: ";
	while ( cin >> a >> ed_izm )
		if (ed_izm=="cm")
			{
			v.push_back(a/100); //Записываем в вектор значения в метрах
			cout << a << ed_izm << "= " <<a/100 <<"m = " <<a/2.54<<"in = "<<a/(12*2.54)<<"ft\n";
			}
			else if (ed_izm=="m")
				{
				v.push_back(a); //Записываем в вектор значения в метрах
				cout << a << ed_izm << "= " <<a*100 <<"cm = " 
						<<(a*100)/2.54<<"in = "<<(a*100)/(2.54*12)<<"ft\n";
				}
				else if (ed_izm=="in")
					{
					v.push_back((a*2.54)/100); //Записываем в вектор значения в метрах
					cout << a << ed_izm << "= " <<a/12 <<"ft = " 
							<<a*(2.54)<<"cm = "<<(a*2.54)/100<<"m\n";
					}
					else if (ed_izm=="ft")
						{
						v.push_back((a*12*2.54)/100); //Записываем в вектор значения в метрах
						cout << a << ed_izm << "= " <<a*12 <<"in = " 
								<<(a*12*2.54)<<"cm = "<<(a*12*2.54)/100<<"m\n";
						}
						else
							cout << "Не знаю такую единицу измерения\n";
		sort(v.begin(),v.end());
		cout << v[0] << "m " << "= " <<v[0]*100 <<"cm = " 
				<<(v[0]*100)/2.54<<"in = "<<(v[0]*100)/(2.54*12)<<"ft - наименьшее значение\n";
		cout << v[v.size()-1] << "m " << "= " <<v[v.size()-1]*100 <<"cm = " 
				<<(v[v.size()-1]*100)/2.54<<"in = "<<(v[v.size()-1]*100)/(2.54*12)<<"ft - наибольшее значение\n";
		summ=0;
		for (i=1; i<v.size()-1; i++)
			summ+=v[i];
		cout << "Кол-во суммир-х значений (без min&max): " << i-1 << " Сумма: " << summ << "m " << "= " <<summ*100 <<"cm = " 
		<<(summ*100)/2.54<<"in = "<<(summ*100)/(2.54*12)<< "ft\n";
		for (i=0;i<v.size(); i++)
			cout << v[i] << "m ";
		cout << endl;	
	return 0;
}

