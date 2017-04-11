/*
	c++ -o code code.cpp -std=c++98
	Глава 6. Упражнение 8. Игра "Быки и коровы"? используя буквы вместо цифр.
*/
#include <iostream>         // std::cerr
#include <stdexcept>        // std::out_of_range
#include <vector>           // std::vector
#include <cstdlib>		    // rand function

using namespace std;
const int v_size = 4;		//Размер вектора для отгадывания

//------------------------------------------------------------------------------
//загадывание значений вектора компьютером
vector<int> make_vector()
{
	vector<int> v(v_size);
// Буквы 'a' по 'z' идут с 97 по 122 номер в таблице ANSI, количество букв - 26
	for (int i = 0; i < v_size; i++)
		v[i] = rand() % 26 + 97;
	
	return v;
}

//------------------------------------------------------------------------------
//Ввод вектора пользователя для угадывания
vector<int> input_vector()
{
	vector<int> p;
	int i = 0;
	char element;

	while (i < v_size)
	{
		cin >> element;
		//допустимый диапазон кодов символов
		if ( int(element) < 97 || 122 < int(element) )
			throw runtime_error("Разрешены символы от 'a' до 'z'.\n");
		p.push_back(int(element));
		i++;
	}

	return p;
}

//------------------------------------------------------------------------------
//Вывод вектора
int output_vector(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
		cout << char(v[i]) << " ";

	cout << endl;
}

//------------------------------------------------------------------------------
//Сравнение загаданного и введённого векторов и соответсвующий вывод
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

	if (bull == v_size)
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

//------------------------------------------------------------------------------
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

