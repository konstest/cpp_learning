//	code.cpp
//c++ -o code -std=c++11 code.cpp
//
// Глава 9. Упражнение 5,6,7. Создать класс Book с перечислениями(enum), 
// перегрузкой операторов ==, !=, << и так далее.

#include "std_lib_facilities.h"
#include <cstdlib>
#include "code.h"

//------------------------------------------------------------------------------
namespace Books_space {

//конструктор
Book::Book (const string& isbn, const string& t, const string& a, Genres g, const string& cp, bool f)
:ISBN(isbn), TITLE(t), author_surname(a), book_genre(g), copyrighted_date(cp), issued(f)
{
	if (!is_isbn(isbn))	throw error();	//	генерация исключения, пока не знаю
	if (!is_date(cp)) 	throw error();	//	как можно конкретизировать ошибку
	if (!is_genre(g))	throw error();	//
}

//true, if 'g' of genres
bool	is_genre(Book::Genres g)
{
	switch (g) {
	case Book::Fantastic:
	case Book::Prose:
	case Book::Periodic:
	case Book::Biography:
	case Book::Childrens:
		return true;
	}
	return false;
}
//true - если ISBN code is n-n-n-x, where N-number and X-character
bool	is_isbn (const string& isbn)
{
	for (int i=0,k=0; i<isbn.size(); i++) {
		switch (k) {
			case 0:	// N-n-n-x
				if (!isdigit(isbn[i]))
					if (isbn[i] == isbn_delimiter) k++;
					else return false;
				break;
			case 1:	// n-N-n-x
				if (!isdigit(isbn[i]))
					if (isbn[i] == isbn_delimiter) k++;
					else return false;
				break;
			case 2:	// n-n-N-x
				if (!isdigit(isbn[i]))
					if (isbn[i] == isbn_delimiter) k++;
					else return false;
				break;
			case 3:	// n-n-n-X
				if (!isalpha(isbn[i])) return false;
				break;
		}
	}
	return true;
}

//true - if date is correct
bool	is_date (const string& cp)
{
	static const int min_year = 1800;
	static const int max_year = 2200;
	string buff="";
    int day = 0, month = 0;
    for (int i=0,j=0,k=0; i<cp.size(); i++) {
	    switch (k) {
    	case 0:		// первые 1-2 цифры это ДЕНЬ
    		if ( isdigit(cp[i]) ) {
    			buff[j] = cp[i];
    			j++;		
    		}
    		else if (cp[i] == date_delimiter && j<=2 ) {
    			k++;
    			j=0;
    			if ( !(day = stoi(buff)) )
	    			return false;
	    		buff = "";
    		}
    		else
    			return false;
    		break;
    	case 1:		//вторые две цифры это МЕСЯЦ (после разделителя)
    		if ( isdigit(cp[i]) ) {
    			buff[j] = cp[i];
    			j++;
    		}
    		else if (cp[i] == date_delimiter && j<=2 ) {
    			k++;
    			j=0;
    			if ( !(month = stoi(buff)) )
	    			return false;
	    		buff = "";
    		}
    		else
    			return false;
    		break;
    	case 2:
    		if ( isdigit(cp[i]) ) {
    			buff[j] = cp[i];
    			j++;
    		}
    		else
    			return false;
    		break;
	    }
	}
	int year = 0;
	if ( !(year = stoi(buff)) )
		return false;

// Next, we determine whether the correct date?
	if ( !(1 <= month && month <= 12) )
		return false;
	if ( !(min_year <= year && year <= max_year) )
		return false;
	
	int days_in_month = 31;
	switch (month) { // Look what month?
	case 2:	//February 
		if (year%4 == 0) //if a leap year
			days_in_month = 29;
		else
			days_in_month = 28;
		break;
	case 4: case 6: case 9: case 11:
		days_in_month = 30;
		break;
	}
	if (days_in_month < month) return false;
	
	return true;	//Is true DATE!
}

bool operator==(const Book& a, const Book& b)
{
	return a.isbn() == b.isbn();
}

bool operator!=(const Book& a, const Book& b)
{
	return !(a==b);
}

ostream& operator<<(ostream& os, const Book& p)
{
	return os << p.author() << " - "
		<< p.title() << ", "
		<< p.isbn();
}

} //Books_space
//------------------------------------------------------------------------------

int main()
try {
	Books_space::Book T("12-15-17-A","Программирование. Принципы и практика использования C++",	"Бьерн Страуструп", Books_space::Book::Fantastic, "01.07.2011",false);

	Books_space::Book F = T;
	cout << T << endl;
	if (T == F)
		cout << F << endl;
    return 0;
}
catch (exception& e) {
    cerr << "Ошибка: " << e.what() << endl; 
	return 1;
}
//------------------------------------------------------------------------------
