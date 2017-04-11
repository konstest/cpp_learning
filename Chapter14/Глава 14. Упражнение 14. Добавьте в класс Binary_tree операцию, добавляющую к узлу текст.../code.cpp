/*
 Глава 14. Упражнение 14.
		Добавьте в класс Binary_tree операцию, добавляющую к узлу текст. Для того,
 чтобы сделать это элегантно, можете модифицировать проект класса Binary_tree.
 Выберите способ идентификации узла: например, для перехода налево, направо, направо,
 налево и направо вниз по бинарному дереву можете использовать строку "lrrlr"
 (корневой узел может соответствовать как переходу влево, так и вправо).
 clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code
*/

#include "code.h"
#include "cmath"

const double PI = 3.141592653589;

//------------------------------------------------------------------------------
//	Округление числа с плавающей точкой
unsigned int rounding(double k)
{
	return ( (k-(int)k) < 0.5 ) ? k : k+1;
}

// Поворачиваем точку P на угол angle с радиусом R
Point rotation(Point P, double angle, int R)
{
	double x = P.x - (double)R * cos((angle*PI)/180);
	double y = P.y - (double)R * sin((angle*PI)/180);
	return Point(rounding(x),rounding(y));
}

//------------------------------------------------------------------------------

void Arrow::draw_lines()	const
{
	if ( color().visibility() && ( r1 != 0 || r2 != 0 ) ) {
		//Узнаём под под каким углом лежит наша "стрелка"
		double length_arrow = sqrt( double(pow(point(1).x-point(0).x,2) + pow(point(1).y-point(0).y,2)) );
		double angle = acos((point(1).x - point(0).x)/length_arrow);
		angle = (angle*180)/PI;		//translate radians into the gradus
		if (point(1).y < point(0).y) angle += 180;
		Point P1 = rotation(point(1),angle-r2,r1);
		Point P2 = rotation(point(1),angle+r2,r1);
		fl_line(point(1).x,point(1).y,P1.x,P1.y );
		fl_line(point(1).x,point(1).y,P2.x,P2.y );
	}
	//Дорисовываем саму (длинную) линию стрелки
	Shape::draw_lines();
}

//------------------------------------------------------------------------------
//конструктор создания правильной n- угольной звезды
Star::Star(Point cc, int nn, int pp, int RR, int AA)
:center_xy(cc), n(nn), p(pp), R(RR), r(0), A(AA)
{ }

//Конструктор создания звезды с ручной установкой радиуса внутренней окружности 
Star::Star(Point cc, int nn, int pp, int RR, int rr, int AA)
:center_xy(cc), n(nn), p(pp), R(RR), r(rr), A(AA)
{ }

// Отрисовка звезды
void Star::draw_lines() const
{
	double angle = 360/n;	//определяем угол вершин
	double a = 0 + A;
	vector<Point> P;
	if (r == 0) {
		for (int i = 0; i < n; i++) {						//
			P.push_back( rotation(center_xy, a, R) );		//ищем координаты
			a = a + angle;									//вершин правильной
		}													//звезды
	}
	else {
		for (int i = 0; i < n; i++) {						//ищем координаты вершин
			P.push_back( rotation(center_xy, a, R) );			//на внешней и
			P.push_back( rotation(center_xy, a+angle/2, r) );	//на внутренней окружностях
			a = a + angle;									//
		}													//
	}

	int np = P.size();
	if (r == 0) {//Рисование правильной звезды, не заполненной
		if (color().visibility())
			for (int i = 0; i < np; i++)
				if (i+p < np - 1)//рисуется линия от точки минуя p кол-во вершин
					fl_line(P[i].x,P[i].y,P[i+p+1].x,P[i+p+1].y);
				else
					fl_line(P[i].x,P[i].y,P[i+p-(np-1)].x,P[i+p-(np-1)].y);
	}
	else {//рисуем звезду с установленным внутренним радиусом
		if (fill_color().visibility()) {				//
		    fl_color(fill_color().as_int());			//
		    fl_begin_complex_polygon();					//заполняем цветом
		    for(int i=0; i<np; ++i)						//внутреннюю часть
		        fl_vertex(P[i].x, P[i].y);				//звезды
		    fl_end_complex_polygon();					//
		    fl_color(color().as_int());		// reset color	//
		}

		if (color().visibility()) {
		    for (unsigned int i=1; i<np; ++i)
		        fl_line(P[i-1].x,P[i-1].y,P[i].x,P[i].y);
		    fl_line(P[np-1].x,P[np-1].y,P[0].x,P[0].y);
		}
	}
}

// Установка радиуса внутренней окружности
void Star::set_intradius(int rr)
{
	if (rr < R-10) r = rr;
	else error ("Слишком большой радиус внтуренний окружности");
}

// Установка числа вершин пропуская которые соединяются рёбрами вершины, т.е.
// в 5- конечной звезде через 1, в 7 уже можно и через 2, в 9 - 3, и.т.д.
void Star::set_num_across_vert(int pp)
{//Если рисуется не правильная звезда, а с вручную установленным радиусом, то
// изменение количества промежуточных вершин нам ничего даст, т.к. там прорисовка
// выполняется через дополнительный поворот координат лежащих на внутренней 
// окружности ещё на половину угла angle/2, т.е. по середине между вершинами
	if (r == 0) {
		if ( (3 + pp*2) <= n)	//проверяем корректность установки 
			p = pp;
		else
			error("Не правильное установка количества промежуточных вершин");
	}
}

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
Binary_tree::Binary_tree(Point xy, int level, Nodes_type nt, Links_type lt, Color line_color ) :
node_label(Point(0,0),"")
{
	int y=0, x=0;
	if (level > 0) {
	//Draw nodes:
		x = width*(nodes_count(level)-1);
		for (int i=level; i > 1; i--) {
			y = (i - 1)*height;
			for (int j = xy.x-x/2, k = 0; k < nodes_count(i); k++, j=j+x/(nodes_count(i)-1)){
				if (nt == Nodes_type::circle)
					nodes.push_back(new Star(Point(j,xy.y+y), 17, 0, nodes_radius, 90));;
				if (nt == Nodes_type::star)
					nodes.push_back(new Star(Point(j,xy.y+y), 5, 1, nodes_radius, 90));
				if (nt == Nodes_type::triangle)
					nodes.push_back(new Star(Point(j,xy.y+y), 3, 0, nodes_radius, 90));
			}
			x = x - (x/(nodes_count(i)-1));
		}
		//root tree
		if (nt == Nodes_type::circle)
			nodes.push_back(new Star(xy, 13, 0, nodes_radius, 90));;
		if (nt == Nodes_type::star)
			nodes.push_back(new Star(xy, 5, 1, nodes_radius, 90));
		if (nt == Nodes_type::triangle)
			nodes.push_back(new Star(xy, 3, 0, nodes_radius, 90));
	//Draw links:
		int count = nodes_count(level),d = 0,i = 0,c = 0;
		while ( count > 1 ) {
			d += count;
			c = i + count;
			while (i < d) {
				Point P1 = nodes[i].center(), P2 = nodes[i+1].center(), P3 = nodes[c].center();
				if (lt == arrow_up) {
					links.push_back(new Arrow(Point(P1.x,P1.y-nodes_radius), Point(P3.x,P3.y+nodes_radius),
											arrow_length,arrow_angle));
					links.push_back(new Arrow(Point(P2.x,P2.y-nodes_radius), Point(P3.x,P3.y+nodes_radius),
											arrow_length,arrow_angle));
				}
				else if (lt == arrow_down) {
					links.push_back(new Arrow(Point(P3.x,P3.y+nodes_radius), Point(P2.x,P2.y-nodes_radius),
											arrow_length,arrow_angle));
					links.push_back(new Arrow(Point(P3.x,P3.y+nodes_radius), Point(P1.x,P1.y-nodes_radius),
											arrow_length,arrow_angle));
				}
				else {
					links.push_back(new Arrow(Point(P1.x,P1.y-nodes_radius), Point(P3.x,P3.y+nodes_radius)));
					links.push_back(new Arrow(Point(P2.x,P2.y-nodes_radius), Point(P3.x,P3.y+nodes_radius)));
				}
				int links_size = links.size();
				links[links_size-1].set_color(line_color);
				links[links_size-1].set_style(Line_style(Line_style::solid,2));
				links[links_size-2].set_color(line_color);
				links[links_size-2].set_style(Line_style(Line_style::solid,2));
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
		links[i].draw();
	for (int i=0; i < nodes_labels.size(); i++)
		nodes_labels[i].draw();
	node_label.draw();

}

//------------------------------------------------------------------------------
//Отрисовка итераций просчитывания ходов алгоритма по расчёту расположения узла
// п.с. была удобна для отладки
void Binary_tree::nodes_labels_draw(const Point& P, string text, int text_length, Color c)
{
	nodes_labels.push_back(new Text(Point(P.x,P.y+7),text.substr(0,text_length+1)));
	nodes_labels[nodes_labels.size()-1].set_font_size(nodes_radius*0.7);
	nodes_labels[nodes_labels.size()-1].set_color(c);
}

//------------------------------------------------------------------------------
//Установка текста на узел
void Binary_tree::set_text_node(string path, string text)
{
	//Начинаем пойск с корня(верх)
	Point find_node = Point(nodes[nodes.size()-1].center().x,nodes[nodes.size()-1].center().y + nodes_radius);
	int k = 1, i = links.size()-1, diameter = 2*nodes_radius;
	int path_size = path.size();
	while (i >= 0 && k < path_size) {
		//стрелка рисуется сверху вних (arrow_down)
		if ( links[i].point(0).y < links[i].point(1).y ) {
			if (links[i].point(0) == find_node) {
				if ( path[k] == 'l' ) {
					if ( links[i].point(1).x < links[i].point(0).x ) {
					//стрелка указывает налево
						find_node = Point(links[i].point(1).x,links[i].point(1).y + diameter);
						nodes_labels_draw(find_node,path,k,links[0].color());
						k++;
					}
				}
				if ( path[k] == 'r' ) {
					if ( links[i].point(1).x > links[i].point(0).x ) {
					//стрелка указывает направо 
						find_node = Point(links[i].point(1).x,links[i].point(1).y + diameter);
						nodes_labels_draw(find_node,path,k,links[0].color());
						k++;
					}
				}
			}
		}
		else {	//стрелка рисуется снизу вверх (line, arrow_up)
			if (links[i].point(1) == find_node) {
				if ( path[k] == 'l' ) {
					if ( links[i].point(0).x < links[i].point(1).x ) {
					//стрелка указывает налево
						find_node = Point(links[i].point(0).x,links[i].point(0).y + diameter);
						nodes_labels_draw(find_node,path,k,links[0].color());
						k++;
					}
				}
				if ( path[k] == 'r' ) {
					if ( links[i].point(0).x > links[i].point(1).x ) {
					//стрелка указывает направо 
						find_node = Point(links[i].point(0).x,links[i].point(0).y + diameter);
						nodes_labels_draw(find_node,path,k,links[0].color());
						k++;
					}
				}
			}
		}
		i--;
	}
	node_label.set_label(text);
	node_label.set_font_size(nodes_radius);
	node_label.set_color(links[0].color());
	node_label.move(find_node.x-nodes_radius/2,find_node.y-nodes_radius/2);
}

//------------------------------------------------------------------------------
int main ()
try
{
	int w = 1920;
	int h = 1000;
	Simple_window win(Point((x_max() - w)/2,(y_max() - h)/2),w,h,"Chapter 14. Exam 14.");

	Binary_tree	tree(Point(win.x_max()/2,50),6, Binary_tree::triangle, Binary_tree::line, Color::blue);
	tree.set_color(Color::red);
	tree.set_style(Line_style(Line_style::solid,2));
	tree.set_text_node("lrrlr","_.oO");
	win.attach(tree);

	win.wait_for_button();
}
catch(exception& e) {
    return 1;
}
catch(...) {
    return 2;
}

