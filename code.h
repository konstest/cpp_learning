//
// Заглолвочный файл
//
// clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "std_lib_facilities.h"
#include "GUI/Simple_window.h"    // if we want that "Next" button
#include "GUI/Graph.h"
#include <cmath>

//------------------------------------------------------------------------------
static const int cell_size = 100;
static const int cell_count = 8;

class Group {
    vector<Shape*> v;
public:
	Group() {}

    void push_back(Shape& s) { v.push_back(&s); }
    void push_back(Shape* p) { v.push_back(p); }

    Shape& operator[](int i) { return *v[i]; }
    const Shape& operator[](int i) const { return *v[i]; }

    int size() const { return v.size(); }
};

class Checkers : public Shape {
public:
	void draw_lines()	const;
	Checkers();		//конструктор
	void move(bool white_black, int index, int to_x, int to_y);//перемещение шашек
private:
	void draw_cell(int i, int j, Color C1, Color C2);	//инициализация ячейки фона
	void draw_text(int i, int j, Color C1, string S);	//инициализация текста
	int draw_checker(int i, int j, Color C);			//создаёт шашки
	Group board_items;
	vector<int> white_checkers;				// индексы белых шашек из board_items
	vector<int> black_checkers;				// -|-
	Vector_ref<Text> numbers;
};

//------------------------------------------------------------------------------

