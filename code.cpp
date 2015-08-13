//
// Глава 14. Задание 1-7. Практическое изучение наследования, полиморфизма и инкапсуляции.
// Измененая команда компиляции, а именно code.cpp добавлена в конец.
// cleab1 && c++ -o code GUI/Simple_window.cpp GUI/Gb1aph.cpp GUI/GUI.cpp GUI/Window.cpp code.cpp -lfltk -lfltk_images -std=c++11 && ./code

#include "code.h"

//------------------------------------------------------------------------------
void call(const B1& b)
{
    b.vf();
    b.f();
    b.pvf();
}

void f(B2& b)
{
	b.pvf();
}

D2& D2_addr(D2& d)
{
	return d;
}





int main ()
try
{

	Q q1;
	W w1;
	E e1;
	
	cout << "Q: " << endl;
	q1.f1();
	cout << "i= " << q1.val() << endl;
	q1.f2();
	cout << "i= " << q1.val() << endl;
	q1.f3();
	cout << "i= " << q1.val() << endl;

	cout << "W: " << endl;
	w1.f1();
	cout << "i= " << w1.val() << endl;
	w1.f2();
	cout << "i= " << w1.val() << endl;
	w1.f3();
	cout << "i= " << w1.val() << endl;

	cout << "E: " << endl;
	e1.f1();
	cout << "i= " << e1.val() << endl;
	e1.f2();
	cout << "i= " << e1.val() << endl;
	e1.f3();
	cout << "i= " << e1.val() << endl;

	
	Q &q_ = w1;
	cout << "Q q_: " << endl;
	q_.f1();
	cout << "i= " << q_.val() << endl;
	q_.f2();
	cout << "i= " << q_.val() << endl;
	q_.f3();
	cout << "i= " << q_.val() << endl;

	q_=e1;
	cout << "q_=e1: " << endl;
	q_.f1();
	cout << "i= " << q_.val() << endl;
	q_.f2();
	cout << "i= " << q_.val() << endl;
	q_.f3();
	cout << "i= " << q_.val() << endl;

	Q *q__ = &w1;
	q__ = &e1;
	cout << "Q *q__: " << endl;
	q__->f1();
	cout << "i= " << q__->val() << endl;
	q__->f2();
	cout << "i= " << q__->val() << endl;
	q__->f3();
	cout << "i= " << q__->val() << endl;
	
/*
	B1 b;
	D1 d;
	D2 d2;
	B1 &b1=d;

	b.vf();
	b.f();
	b.pvf();
cout << endl;

	d.vf();
	d.f();
	d.pvf();
cout << endl;

	d2.vf();
	d2.f();
	d2.pvf();
cout << endl;

	b1.vf();
	b1.f();
	b1.pvf();
cout << endl;

cout << "call(b): ";
	call(b);
cout << "call(d): ";
	call(d);
cout << "call(d2): ";
	call(d2);
cout << "call(b1): ";
	call(b1);
cout << endl;
	
	b1 = d2;
	b1.vf();
	b1.f();
	b1.pvf();
cout << endl;

cout << "call(b): ";
	call(b);
cout << "call(d): ";
	call(d);
cout << "call(d2): ";
	call(d2);
cout << "call(b1): ";
	call(b1);
cout << endl;


/*
OUTPUT:
B1::vf()
B1::f()
B1::pvf()

D1::vf()
D1::f()
B1::pvf()

D1::vf()
D1::f()
D2::pvf()

D1::vf()
B1::f()
B1::pvf()

call(b): B1::vf()
B1::f()
B1::pvf()
call(d): D1::vf()
B1::f()
B1::pvf()
call(d2): D1::vf()
B1::f()
D2::pvf()
call(b1): D1::vf()
B1::f()
B1::pvf()

D1::vf()
B1::f()
B1::pvf()

call(b): B1::vf()
B1::f()
B1::pvf()
call(d): D1::vf()
B1::f()
B1::pvf()
call(d2): D1::vf()
B1::f()
D2::pvf()
call(b1): D1::vf()
B1::f()
B1::pvf()


*/

/*
//............
	B1 b;
cout << "B1 b;\n";
	D1 d;
cout << "D1 d;\n";
	D2 d2;
cout << "D2 d2;\n";
	B1 &b1=d;
cout << "B1 &b1=d;\n";
cout << endl;
	
cout << "b.vf(): ";
	b.vf();
cout << "b.f(): ";
	b.f();
cout << "b.pvf(): ";
	b.pvf();
cout << endl;


cout << "d.f(): ";
	d.vf();
cout << "d.f(): ";
	d.f();
cout << "d.pvf(): ";
	d.pvf();
cout << endl;

cout << "d2.f(): ";
	d2.vf();
cout << "d2.f(): ";
	d2.f();
cout << "d2.pvf(): ";
	d2.pvf();
cout << endl;

cout << "b1.f(): ";
	b1.vf();
cout << "b1.f(): ";
	b1.f();
cout << "b1.pvf(): ";
	b1.pvf();
cout << endl;

cout << "b1 = d2;\n";
//	b1 = D2_addr(d2);
	b1 = d2;

cout << "b1.f(): ";
	b1.vf();
cout << "b1.f(): ";
	b1.f();
cout << "b1.pvf(): ";
	b1.pvf();
cout << endl;

cout << "call(b): ";
	call(b);
cout << "call(d): ";
	call(d);
cout << "call(d2): ";
	call(d2);
cout << "call(b1: ";
	call(b1);
cout << endl;


	D21 d21;
	D22 d22;
	
cout << "f(d21): ";
	f(d21);
cout << "f(d22): ";
	f(d22);
cout << endl;
*/
}
catch(exception& e) {
    return 1;
}
catch(...) {
    return 2;
}

