// c++ -o code code.cpp -std=c++11
//
// This is example code from Chapter 7.8.3 "Predefined names" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

/*
    Simple calculator

    Revision history:

        Revised by Bjarne Stroustrup May 2007
        Revised by Bjarne Stroustrup August 2006
        Revised by Bjarne Stroustrup August 2004
        Originally written by Bjarne Stroustrup
            (bs@cs.tamu.edu) Spring 2004.

    This program implements a basic expression calculator.
    Input from cin; output to cout.

    The grammar for input is:

    Calculation:
        Statement
        Print
        Quit
        Calculation Statement
    
    Statement:
        Declaration
        Expression
    
    Declaration:
        "let" Name "=" Expression
        "let" "const" Name "=" Expression

    Print:
        ;
        '\n'

    Quit:
        quit

    Expression:
        Term
        Expression + Term
        Expression - Term
    Term:
        Primary
        Term * Primary
        Term / Primary
        Term % Primary
    Primary:
        Number
        Name
        sqrt(Expression)
        pow(Expression,Y)
        ( Expression )
        - Primary
        + Primary
        help
    help:
    	"Руководство пользователя..."
    sqrt(Expression):
    	корень_квадратный ( Expression )
    pow(Expression,Y):
    	Возведение Expression в степень Y
    Number:
        floating-point-literal


        Input comes from cin through the Token_stream called ts.
*/

//------------------------------------------------------------------------------

const char		help	= 'h';		// Вывод руководства пользователя
const string	helpkey = "help";	//
const char 		number 	= '8';   	// t.kind==number means that t is a number Token
const string 	quitkey	= "quit";	// declaration keyword for exit is this programm
const char 		quit 	= 'q';    	// t.kind==number means that t is a number Token
const char 		print 	= ';';    	// t.kind==print means that t is a print Token
const char 		name	= 'a';    	// name token
const char		let    	= 'L';    	// declaration token
const string	declkey = "let";		// declaration keyword 
const string	sqrtkey	= "sqrt";
const char	 	Sqrt 	= 's';
const string 	powkey	= "pow";
const char	 	Pow 	= 'p';
const string 	prompt  = "> ";
const string 	result  = "= "; // used to indicate that what follows is a result

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    string name;      // for names: name itself
    Token(char ch)             : kind(ch), value(0)   {}
    Token(char ch, double val) : kind(ch), value(val) {}
    Token(char ch, string n)   : kind(ch), name(n)    {}
};

//------------------------------------------------------------------------------

class Token_stream {
public: 
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
    void ignore(char c);      // discard tokens up to an including a c
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
:full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get() // read characters from cin and compose a Token
{
    if (full) {         // check if we already have a Token ready
        full=false;
        return buffer;
    }  

    char ch;
    cin.get(ch);		//
    while (ch == ' ')	//специально для обработки '\n'
	    cin.get(ch);	//

//    cin >> ch;	// note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case print:				//
    case '(':				//
    case ')':				//
    case '+':				//
    case '-':				//
    case '*':				//
    case '/':				//
    case '%':				//
    case '=':				//
    case ',':				//
        return Token(ch); 	// let each character represent itself
    case '.': // a floating-point literal can start with a dot
    case '0': case '1': case '2': case '3': case '4':	//
    case '5': case '6': case '7': case '8': case '9':	// numeric literal
    {
        cin.putback(ch);// put digit back into the input stream
        double val;
        cin >> val;     // read a floating-point number
        return Token(number,val);
    }
    default:
        if (isspace(ch)) {	//обработка ввода ENTER('\n')
        	return Token(print);
        }
        if (isalpha(ch)) {
            string s;
            s += ch;
            while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_' ) ) s+=ch;
            cin.putback(ch);
            if (s == declkey)	return Token(let); 		// keyword "let"
            if (s == sqrtkey)	return Token(Sqrt,s);	// keyword "sqrt"
            if (s == powkey)	return Token(Pow,s);	// keyword "pow"
            if (s == quitkey)	return Token(quit);		// keyword "quit"
            if (s == helpkey)	return Token(help);		// keyword "help"
            return Token(name,s);
        }
        error("Bad token");
    }
}

//------------------------------------------------------------------------------

void Token_stream::ignore(char c)
    // c represents the kind of a Token
{
    // first look in buffer:
    if (full && c==buffer.kind) {
        full = false;
        return;
    }
    full = false;

    // now search input:
    char ch = 0;
    while (cin>>ch)
        if (ch==c) return;
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

class Variable {
public:
	bool constanta;
    string name;
    double value;
    //создаём обычную переменную, которую потом межно изменять
    Variable (string n, double v) :constanta(false), name(n), value(v) { }
    //создаём константу
    Variable (bool c, string n, double v)
    	:constanta(true), name(n), value(v) { }
};

//------------------------------------------------------------------------------

class Symbol_table {
public:
	vector<Variable> var_table;
	void set(string, double);
	double get(string);
	bool is_declared(string);
	double define(string,double,bool);
};
//п.с. упраженение №9 выполнять не стал, т.к. не вижу смысла в 
//такой инкапсуляции из класса в класс, это при том, что смысл
//упражнения №9 практически идентичен №4 
Symbol_table table;		//для хранения переменных
//------------------------------------------------------------------------------

void Symbol_table::set(string var, double val)
//если данная переменная не константа, то устанавливаем её новое
//значение (example: c=9 -GOOD, e=3 -ERROR!)
{
    for (int i = 0; i<var_table.size(); ++i)
        if (var_table[i].name == var) {
        	if (var_table[i].constanta)
        		error ("This is constanta: ", var_table[i].name);
        	var_table[i].value = val;
        	return;
        }
	error ("There is no such variable: ", var);
}
//------------------------------------------------------------------------------

double Symbol_table::get(string s)
    // return the value of the Variable names s
{
    for (int i = 0; i<var_table.size(); ++i)
        if (var_table[i].name == s) return var_table[i].value;
    error("get: undefined variable ", s);
}


//------------------------------------------------------------------------------

bool Symbol_table::is_declared(string var)
    // is var already in var_table?
{
    for (int i = 0; i<var_table.size(); ++i)
        if (var_table[i].name == var)
        	return true;
    return false;
}

//------------------------------------------------------------------------------

double Symbol_table::define(string var, double val, bool constanta)
    // add (var,val) to var_table
{
    if (!is_declared(var)) {
    	if (constanta)	//объявляем константу
    		var_table.push_back(Variable(constanta,var,val));
    	else			//простую переменную
    		var_table.push_back(Variable(var,val));
    }
    else
    	error ("Already there is such a variable: ",var);
    return val;
}

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':           // handle '(' expression ')'
        {
	    	double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
	case help:
		error("Руководство пользователя:\n\
		ляляляля....\n\
		как пользоваться калькулятором...");
		return 0;
    case number:    
        return t.value;    // return the number's value
    case name:
    	{
    	Token k = ts.get();
		//это если идёт присваивание нового значения 
		//ранее объявленной переменной
    	if (k.kind == '=') {
	    	double d = expression();
	    	table.set(t.name,d);
	    	return d;
    	}
    	ts.putback(k);
        return table.get(t.name); // return the variable's value
    	}
    case Sqrt:  // return square root
        {
            double d = expression();
            if (d > 0) return sqrt(d);
            error("Error, sqrt argument <= 0!");
        }
    case Pow:  // возвращяем x в степени y
        {
            t = ts.get();
            if (t.kind != '(') error("pow(x,y) '(' expected");
            double d = expression();
            t = ts.get();
            if (t.kind != ',') error("pow(x,y) ',' expected");
            t = ts.get();
            if (t.kind != number ) error("pow(x,y) 'y' is not number");
//в принципе степень может равняться 0 или быть отрицательной, но я
//что бы не усложнять код решил, что она должна быть всегда больше 0
            if (t.value <= 0 ) error("pow(x,y) 'y' <= 0");
            if ( t.value != int(t.value) ) error("pow(x,y) 'y' is not INTEGER number");
            double k = d;
			for (unsigned int i = 1; i < t.value; i += 1)
				d = d * k;
            t = ts.get();
            if (t.kind != ')') error("pow(x,y) ')' expected");
			return d;
        }
    case '-':
        return - primary();
    case '+':
        return primary();
    default:
        error("primary expected");
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get(); // get the next token from token stream

    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
            {    
                double d = primary();
                if (d == 0) error("divide by zero");
                left /= d; 
                t = ts.get();
                break;
            }
        case '%':
            {    
                int i1 = narrow_cast<int>(left);
                int i2 = narrow_cast<int>(term());
                if (i2 == 0) error("%: divide by zero");
                left = i1%i2; 
                t = ts.get();
                break;
            }
        default: 
            ts.putback(t);        // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while(true) {    
        switch(t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

double declaration()
    // handle: name = expression
    // declare a variable called "name" with the initial value "expression"
{
	bool constanta = false;
    Token t = ts.get();
    if (t.kind != name) error ("name expected in declaration");
    if (t.name == "const") { //вводится именнованная константа
    	t = ts.get();	//т.е. после 'const' должно пойти имя константы
    	if (t.kind != name) error ("const 'name' expected in declaration");
    	constanta = true;
    }
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=') error("= missing in declaration of ", var_name);

    double d = expression();
    table.define(var_name,d,constanta);
    return d;
}

//------------------------------------------------------------------------------

double statement()
{
    Token t = ts.get();
    switch (t.kind) {
    case let:
        return declaration();
    default:
        ts.putback(t);
        return expression();
    }
}

//------------------------------------------------------------------------------

void clean_up_mess()
{ 
    ts.ignore(print);
}

//------------------------------------------------------------------------------

void calculate()
{
    while (cin)
      try {
        cout << prompt;
        Token t = ts.get();
        while (t.kind == print) t=ts.get();    // first discard all "prints"
        if (t.kind == quit) return;        // quit
        ts.putback(t);
        cout << result << statement() << endl;
    }
    catch (exception& e) {
//        cerr << e.what() << endl;        // write error message
        clean_up_mess();
    }
}

//------------------------------------------------------------------------------

int main()
try {
    // predefine names:
    table.define("pi",3.1415926535,true);
    table.define("e",2.7182818284,true);

    calculate();

    keep_window_open();    // cope with Windows console mode
    return 0;
}
catch (exception& e) {
    cerr << e.what() << endl;
    keep_window_open("~~");
    return 1;
}
catch (...) {
    cerr << "exception \n";
    keep_window_open("~~");
    return 2;
}

//------------------------------------------------------------------------------
