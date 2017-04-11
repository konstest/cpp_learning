/*
 Глава 14. Упражнение 11.
		Определите класс Binary_tree, производный от класса Shape. 
 Введите параметр, задающий колличство уровней (levels==0 означает, что в дереве
 нет ни одного узла, levels==1 означает, что в дереве есть один узел, levels==2
 означает, что дерево состоит из вершины и двух узлов, levels==3 означает, что
 дерево состоит из вершины и двух дочерних узлов, которые в свою очередь имеют
 по два дочерних узла, и т.д.). Пусть узел изображается маленьким кружочком.
 Соедините узлы линиями (как это принято).
 clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code
*/

#include "code.h"


//------------------------------------------------------------------------------
//Считает количество узлов на указанном уровне
int Binary_tree::nodes_count(int lvl)
{
	if (lvl < 3)
		return lvl;
	else {
		int k = 2;
		for (int i = 2; i < lvl; i++)
			k = k*2;
		return k;
	}
}

//------------------------------------------------------------------------------
//Конструктор в котором просчитывается 
Binary_tree::Binary_tree(Point xy, int l )
: level(l)
{
	int y=0, x=0;
	if (level > 0) {
	//Draw nodes:
		x = width*(nodes_count(level)-1);
		for (int i=level; i > 1; i--) {
			y = (i - 1)*height;
			for (int j = xy.x-x/2, k = 0; k < nodes_count(i); k++, j=j+x/(nodes_count(i)-1))
				nodes.push_back(new Circle(Point(j,xy.y+y),links_radius));
			x = x - (x/(nodes_count(i)-1));
		}
		nodes.push_back(new Circle(xy,links_radius));	//root tree
	//Draw links:
		int count = nodes_count(level),d = 0,i = 0,c = 0;
		while ( count > 1 ) {
			d += count;
			c = i + count;
			while (i < d) {
				links.push_back(new Lines());
				Point P1 = nodes[i].center(), P2 = nodes[i+1].center(), P3 = nodes[c].center();
				links[links.size()-1].add( Point(P1.x,P1.y-links_radius), Point(P3.x,P3.y+links_radius) );
				links.push_back(new Lines());
				links[links.size()-1].add( Point(P2.x,P2.y-links_radius), Point(P3.x,P3.y+links_radius) );
				i += 2;
				c++;
			}
			count = count/2;
		}
	}
}

//------------------------------------------------------------------------------
//Отрисовка на экране
void Binary_tree::draw_lines()	const
{
	for (int i=0; i < nodes.size(); i++)
		nodes[i].draw_lines();
	for (int i=0; i < links.size(); i++)
		links[i].draw_lines();
}

//------------------------------------------------------------------------------
int main ()
try
{
	int w = 1920;
	int h = 1000;
	Simple_window win(Point((x_max() - w)/2,(y_max() - h)/2),w,h,"Chapter 14. Exam 11.");

	Binary_tree	tree(Point(win.x_max()/2,50),6);
	tree.set_color(Color::blue);
	tree.set_style(Line_style(Line_style::solid,4));
	win.attach(tree);
	win.wait_for_button();
}
catch(exception& e) {
    return 1;
}
catch(...) {
    return 2;
}

