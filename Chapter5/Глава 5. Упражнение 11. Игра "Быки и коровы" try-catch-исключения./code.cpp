#include <iostream>       // std::cerr
#include <stdexcept>      // std::out_of_range
#include <vector>         // std::vector
#include <cstdlib>				// rand function

using namespace std;
/*
	c++ -o code code.cpp -std=c++11
	try/catch-исключения. Глава 5. Упражнение 11. Игра "Быки и коровы".
*/
const int v_size = 4;		//Размер вектора для отгадывания

//загадывание значений вектора компьютером
vector<int> make_vector()
{
	vector<int> v(v_size);

	for (int i = 0; i < v_size; i++)
		v[i] = rand() % 10;
	
	return v;
}

//Ввод вектора пользователя для угадывания
vector<int> input_vector()
{
	vector<int> p;
	int element,i = 0;

	while (i < v_size)
	{
		cin >> element;
		if (element < 0 || 9 < element)
			throw runtime_error("Значения чисел должны быть типа int \
быть в пределах [0-9]!\n");
		p.push_back(element);
		i++;
	}

	return p;
}

int output_vector(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	cout << endl;
}

bool compare_vectors(vector<int> v, vector<int> p, int attempt)
{//Ищем угадал ли пользователь число и его позицию
	int bull = 0, cow = 0;
	vector<int> v_search, p_search;
	v_search = v;
	p_search = p;
	//сперва ищем быков, предварительно их помечая
	for (int i = 0; i < v_size; i++)
		if (p_search[i] == v_search[i])
		{
			bull++;
			v_search[i]=-1; //убираем даный элемент из дальнейшей проверки
			p_search[i]=-2; //убираем даный элемент из дальнейшей проверки
		}
	//потом коров
	for (int i = 0; i < v_size; i++)
		for (int j = 0; j < v_size; j++)
			if (p_search[i] == v_search[j])
			{
			cow++;
			v_search[j] = -1;
			break;
			}	

	if (bull == 4)
	{
		cout << "Поздравляю Вы угадали c " << attempt << " попытки!\n";
		return false;
	}
	else
	{
		cout << bull << " бык(-ов) и " << cow << " коровов(ы)\n";
		return true;	//Сообщаяем, что нужно продолжить игру, т.к. не угадали всех быков
	}
}

//--------------------------------------------------------------------------------
int main () {

try {
	vector<int> v;
	vector<int> p;
	bool next = true;
	srand (time(NULL));

	v = make_vector();	//загадываем вектор
	output_vector(v);

	// начинаем игру в угадывание
	cout << "Введите вектор из " << v_size << " элементов для отгадывания:\n";
	int attempt = 1;
	while (next)
	{
		p = input_vector();
		if ( next = compare_vectors(v,p,attempt) )
			cout << "попробуйте ещё раз!\n";
		attempt++;
	}
}
catch (exception& e) {
  cerr << "Ошибка-прерывание: " << e.what() << '\n'; 
  return 1;
}

return 0;
}

