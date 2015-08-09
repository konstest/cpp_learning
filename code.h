//
// Заглолвочный файл
//
// c++ -o code code.cpp GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp -lfltk -lfltk_images -std=c++11

#include "std_lib_facilities.h"
#include "GUI/Simple_window.h"    // if we want that "Next" button
#include "GUI/Graph.h"
#include <cmath>

//------------------------------------------------------------------------------

struct Star : Shape {
	Star(Point center, int nn, int pp, int RR, int AA);//рисует "правильную" звезду
	Star(Point center, int nn, int pp, int RR, int rr, int AA);//рисует практически какую хошь звезду :)
	void set_angle(int AA) { A = AA; }			//меняет угол поворота
	void set_intradius(int rr);					//меняет внутренний радиус
	void set_radius(int RR) { R = RR; }			//меняет внешний радиус
	void set_num_vert(int nn) { n = nn; }		//установить количество вершин
	void set_num_across_vert(int pp);			//уст. кол. вершин через которое
	void draw_lines()	const;
	int radius() { return R; }		//узнаём внешний радиус
private:
	Point center;	//Координаты центра звезды 
	int n;	//Количество вершин
	int p;	//количество вершин через которое происходит соединение вершин
			//т.е. 1 начиная с 5 конечных звёзд, 2 - 7-и, 3 - 9, и т.д.
	int R;	//радиус внешней окружности
	int r;	//радиус внутренней окружности
	int A;	//угол поворота звезды
};
//------------------------------------------------------------------------------

