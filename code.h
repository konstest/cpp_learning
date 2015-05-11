//	code.cpp
//c++ -o code -std=c++11 code.cpp
//
// Глава 9. Упражнение 3. Перегрузить в созданном класск Name_pairs операторы <<, ==, !=.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------
namespace Books_space {

class Book {
public:
	enum Genres {
		Fantastic, Prose, Periodic, Biography, Childrens
	};
	string	isbn()				const {return ISBN;}
	string	title()				const {return TITLE;}
	string	author()			const {return author_surname;}
	Genres	genre()				const {return book_genre;}
	string	copyrighted()		const {return copyrighted_date;}
	bool	on_hands()			const {return issued;}
	//конструктор
	Book (const string& isbn, const string& t, const string& a, Genres g, const string& cp, bool f);
	struct error{ };
private:
	string	ISBN;				//Код ISBN
	string	TITLE;				//Название книги
	string	author_surname;		//Фамилия автора
	Genres	book_genre;				//Genres of books
	string	copyrighted_date;	//дата регистрации авторских прав
	bool	issued;				//выдана на руки или нет
};

const char date_delimiter = '.';		// Разделитель в дате. #11.05.2015
const char isbn_delimiter = '-';		// Разделитель в ISBN коде. 34-25-5552-F

//true - если ISBN code is n-n-n-x, where N-number and X-character
bool	is_isbn (const string& isbn);
//true - if date is correct
bool	is_date (const string& cp);
bool	is_genre(Book::Genres g);
bool	operator==(const Book& a, const Book& b);
bool	operator!=(const Book& a, const Book& b);

}	//Books_space

