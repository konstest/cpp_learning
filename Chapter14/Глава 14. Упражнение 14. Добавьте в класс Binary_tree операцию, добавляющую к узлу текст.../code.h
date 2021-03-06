//
// Заглолвочный файл
//
// clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "std_lib_facilities.h"
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------
struct Star : Shape {
	Star(Point c, int nn, int pp, int RR, int AA);//рисует "правильную" звезду
	Star(Point c, int nn, int pp, int RR, int rr, int AA);//рисует практически какую хошь звезду :)
	void set_angle(int AA) { A = AA; }			//меняет угол поворота
	void set_intradius(int rr);					//меняет внутренний радиус
	void set_radius(int RR) { R = RR; }			//меняет внешний радиус
	void set_num_vert(int nn) { n = nn; }		//установить количество вершин
	void set_num_across_vert(int pp);			//уст. кол. вершин через которое
	void draw_lines()	const;
	Point center() 	{ return center_xy; }
	int radius() 	{ return R; }
private:
	Point center_xy;	//Координаты центра звезды 
	int n;	//Количество вершин
	int p;	//количество вершин через которое происходит соединение вершин
			//т.е. 1 начиная с 5 конечных звёзд, 2 - 7-и, 3 - 9, и т.д.
	int R;	//радиус внешней окружности
	int r;	//радиус внутренней окружности
	int A;	//угол поворота звезды
};

//------------------------------------------------------------------------------
struct Arrow : Shape {
	Arrow (Point p1, Point p2):r1(0), r2(0) { add(p1); add(p2); }
	Arrow (Point p1, Point p2, int r1, int r2): r1(r1), r2(r2) { add(p1); add(p2); }
	void draw_lines()	const;	//изменяем поведение
private:
	int r1;	//width 1
	int r2;	//width 2
};

//------------------------------------------------------------------------------
struct Binary_tree : Shape {
	enum Nodes_type {
		triangle,
		circle,
		star
	};
	enum Links_type {
		arrow_up,
		arrow_down,
		line
	};
    Binary_tree(Point xy, int level, Nodes_type nt, Links_type lt, Color c);
    void set_text_node(string path, string text);
    void draw_lines()	const;
private:
	int height = 75;			//растягивание по оси ординат между уровнями
	int width = 50;				//по оси абцисс
	int nodes_radius = 20;		//радиус узла
	Vector_ref<Star> nodes;		//хранение узлов
	Vector_ref<Arrow> links;	//хранение связей
	int arrow_angle = 30;		//угол под котороым рисуется указатель стрелки
	int arrow_length = 10;		//угол под котороым рисуется указатель стрелки
	int nodes_count(int lvl);	//определениеколичества узолов на данном уровне
	Vector_ref<Text> nodes_labels;
	Text node_label;
	void nodes_labels_draw(const Point& P, string text, int text_length, Color c);
};


