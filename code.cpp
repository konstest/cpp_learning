/*
 Глава 14. Упражнение 16.
	Определите класс Conroller, содержащий четыре виртуальные функции: on(), off(),
set_level(int), и show(). Выведите из класса Controller как минимум два класса.
Один из них должен быть простым тестовым классом, в котором функция show() выводит
на печать информацию, включён или выклёчен контроллер, а так же текущий уровень.
Второй производный класс должен управлять цветом объекта класса Shape; точный смысл
понятия "уровень" определите сами. Попробуйте найти третий объект для управления
с помощью класса Controller.
 clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code
*/

#include "code.h"
#include "cmath"

//------------------------------------------------------------------------------
void Test_controller::show()
{
	if (is_switcher()) 
		cout << "Is On.\n";
	else
		cout << "Is Off.\n";
	cout << "Level: " << is_level() << endl;
}

void Set_controller::set_color(Color col, Shape& obj)
{
	obj.set_color(col);
	obj.set_fill_color(col);
}

void Set_controller::set_style(Line_style ls, Shape& obj)
{
	obj.set_style(ls);
}

//------------------------------------------------------------------------------
int main ()
try
{
	Test_controller t;
	t.off();
	t.set_level(7);
	t.show();
	
	Set_controller s;
	Line L(Point(100,100),Point(400,400));
	s.set_color(Color::blue,L);
	s.set_style(Line_style::dot,L);
}
catch(exception& e) {
    return 1;
}
catch(...) {
    return 2;
}

