//
// Глава 14. Упражнение 9. Определить класс Group служащий контейнером объектов класса Shape с удобными операциями
//над членами класса Group. Подсказака вектор: Vector_ref. Используя класс Group, определите класс, рисующий шахматную доску
//по которой шашки могут перемещаться под управлением программы.
// clear && c++ -o code GUI/Simple_window.cpp GUI/Graph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "code.h"

static const double PI = 3.14159265359;

const Color numbers_color(Color::red);	//Цвет боковых индексов шахматной доски
const Color black_checkers_color(Color::black);	//Цвет чёрных шашек
const Color white_checkers_color(Color::white);	//Цвет белых шашек
const Color white_cells_color(Color::white);	//Цвет белых ячеек доски
const Color black_cells_color(Color::blue);		//Цвет чёрных ячеек доски

//------------------------------------------------------------------------------

//	Инициализация ячейки фона
void Checkers::draw_cell(int i, int j, Color C1, Color C2)
{
	board_items.push_back(new Rectangle(Point(i*cell_size,j*cell_size),cell_size,cell_size));
	int last_added = board_items.size() - 1;
	if (j%2 == 0) {
		board_items[last_added].set_color(C2);
		board_items[last_added].set_fill_color(C2);
	}
	else {
		board_items[last_added].set_color(C1);
		board_items[last_added].set_fill_color(C1);
	}
}

void Checkers::draw_text(int i, int j, Color C, string S)
{
	numbers.push_back(new Text(Point(i*cell_size + cell_size/3,j*cell_size + cell_size/2), S));
	numbers[numbers.size()-1].set_color(C);
	numbers[numbers.size()-1].set_font_size(40);
}

int Checkers::draw_checker(int i, int j, Color C)
{
	board_items.push_back(new Circle(Point(i,j),cell_size/2 - cell_size/3));
	int index = board_items.size()-1;
	board_items[index].set_color(C);
	board_items[index].set_style(Line_style(Line_style::solid,cell_size/2));
	return index;
}

Checkers::Checkers()
{
	//инициализируем доску, её фон и т.д.
	ostringstream oss;
	for (int i=0; i<cell_count; i++) {
		oss << i;
		draw_text(cell_count,i,numbers_color,oss.str());
		draw_text(i,cell_count,numbers_color,oss.str());
		if (i%2==0)
			for (int j=0; j<cell_count; j++)
				draw_cell(i,j,black_cells_color,white_cells_color);
		else
			for (int j=0; j<cell_count; j++)
				draw_cell(i,j,white_cells_color,black_cells_color);
		oss.str("");
	}

	//инициализируем шашки
	for (int i=1; i<cell_count; i+=2) {
		int index;
	//размещаяем белые шашки:
		white_checkers.push_back(draw_checker(i*cell_size + cell_size/2,cell_size/2,Color::white));
		white_checkers.push_back(draw_checker((i-1)*cell_size + cell_size/2,cell_size + cell_size/2,Color::white));
		white_checkers.push_back(draw_checker(i*cell_size + cell_size/2,cell_size*2 + cell_size/2,Color::white));
	//чёрные шашки:
		black_checkers.push_back(draw_checker((i-1)*cell_size + cell_size/2,cell_count*cell_size-cell_size/2,Color::black));
		black_checkers.push_back(draw_checker((i-1)*cell_size + cell_size/2,cell_count*cell_size - 2*cell_size - cell_size/2,Color::black));
		black_checkers.push_back(draw_checker(i*cell_size + cell_size/2,cell_count*cell_size - cell_size - cell_size/2,Color::black));
	}
}

void Checkers::draw_lines()	const
{
	for (int i=0; i<board_items.size(); i++)
		board_items[i].draw();
		
	for (int i=0; i<numbers.size(); i++)
		numbers[i].draw();
}

void Checkers::move(bool white, int index, int to_x, int to_y)
{
	if (white) {
		Point P = board_items[white_checkers[index]].point(0);
		board_items[white_checkers[index]].move(to_x*cell_size-(P.x-cell_size/2)-15,to_y*cell_size-(P.y-cell_size/2)-15);
	}
	else {
		Point P = board_items[black_checkers[index]].point(0);
		board_items[black_checkers[index]].move(to_x*cell_size-(P.x-cell_size/2)-15,to_y*cell_size-(P.y-cell_size/2)-15);
	}
}
//------------------------------------------------------------------------------

int main ()
try
{
	Simple_window win(Point(10,10),900,900,"Chapter 14. Cheese 8x8.");

	Checkers shashki;
	win.attach(shashki);
	
	win.wait_for_button();

	bool black = false, white = true;
	shashki.move(white,2,2,3);
	win.wait_for_button();
	shashki.move(black,4,1,4);

	win.wait_for_button();
}
catch(exception& e) {
    return 1;
}
catch(...) {
    return 2;
}

