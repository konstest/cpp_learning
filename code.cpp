//c++ -o code code.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
	double temp;
	vector<double> temps;
	while (cin>>temp)
		temps.push_back(temp);
	double sum = 0;
	for (int i = 0; i < temps.size(); ++i) sum+=temps[i];
	cout << "Средняя температура: " << sum/temps.size() << endl;
	//вычисляем медиану температуры
	sort(temps.begin(),temps.end());
	if (temps.size()%2 != 0)
		cout << "Медиана температуры: " <<temps[temps.size()/2] << " Цельсия\n";
	else cout << "Медиана температуры: " << double( (temps[temps.size()/2] + temps[(temps.size()/2)-1])/2 ) << " Цельсия\n";
	return 0;
}

