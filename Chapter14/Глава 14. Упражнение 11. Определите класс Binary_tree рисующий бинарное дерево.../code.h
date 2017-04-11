//
// Заглолвочный файл
//
// clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "std_lib_facilities.h"
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"

using namespace Graph_lib;

struct Binary_tree : Shape {
    Binary_tree(Point xy, int level );
    void draw_lines()	const;
private:
	int level;
	int height = 75;			//растягивание по оси ординат между уровнями
	int width = 50;				//по оси абцисс
	int links_radius = 20;		//радиус узла
	Vector_ref<Circle> nodes;	//хранение узлов
	Vector_ref<Lines> links;	//хранение связей
	int nodes_count(int lvl);	//определениеколичества узолов на данном уровне
};

