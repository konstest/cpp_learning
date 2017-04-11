/* 
 * Chapter 19. Exercise 11.
 * Design and implement a counted_ptr<T> that is a type that holds a pointer to
 * an object of type T and a pointer to a“use count” (an int) shared by all
 * counted pointers to the same object of type T. The use count should hold the
 * number ofcounted pointers pointing to a given T. Let the counted_ptr’s
 * constructor allocate a T object and a use count on the freestore. Let
 * counted_ptr’s constructor take an argument to be used as the initial value
 * of the T elements. When the lastcounted_ptr for a T is destroyed,
 * counted_ptr’s destructor should delete the T. Give the counted_ptr
 * operationsthat allow us to use it as a pointer. This is an example of
 * a “smart pointer” used to ensure that an object doesn’t getdestroyed until
 * after its last user has stopped using it. Write a set of test cases for
 * counted_ptr using it as an argumentin calls, container elements, etc.
 * clear; g++ -o code code.cpp -std=c++0x && ./code
 */

#include <iostream> 
#include <cstring>
#include <cstdlib>
#include <vector>
#include <memory>
#include "code.h"

//------------------------------------------------------------------------------

template<typename T, typename A> 
void vector<T,A>::reserve(int newalloc)
{
    if (newalloc<=space) return;     // never decrease allocation
    unique_ptr<T> _p { alloc.allocate(newalloc) }; // allocate new space
    T* p = _p.get();
    for (int i=0; i<sz; ++i) alloc.construct(&p[i],elem[i]); // copy
    for (int i=0; i<sz; ++i) alloc.destroy(&elem[i]);        // destroy
    alloc.deallocate(elem,space);    // deallocate old space
    elem = _p.release();
    space = newalloc; 
}

//------------------------------------------------------------------------------

template<class T, class A>
void vector<T,A>::resize(int newsize, T val)
{
    reserve(newsize);
    for (int i=sz; i<newsize; ++i) alloc.construct(&elem[i],val); // construct
    for (int i=newsize; i<sz; ++i) alloc.destroy(&elem[i]);       // destroy
    sz = newsize; 
}

//------------------------------------------------------------------------------
//allocate space for n objects of type T
template<class T> T* allocator<T>::allocate(int n)
{
    return (T*)malloc(sizeof(T)*n);
}

//------------------------------------------------------------------------------
//deallocate n objects of type T starting at p
template<class T> void allocator<T>::deallocate(T* p, int n)
{
    free(p);    //free func know about size allocation
}

//------------------------------------------------------------------------------
//construct a T with the value v in p
template<class T> void allocator<T>::construct(T* p, const T &v)
{
//    memcpy(p,&v,sizeof(v));
    std::copy(&v,&v+1,p);   //invokes copy constructor!
}

//------------------------------------------------------------------------------
//
template<class T> void allocator<T>::destroy(T* p)
{
    p->~T();
}

//------------------------------------------------------------------------------

template<class T, class A>
void vector<T,A>::push_back(const T& val)
{
    // no more free space: get more
    if (space==0)
        reserve(8);
    else 
    if (space==sz)
        reserve(2*space);

    alloc.construct(&elem[sz],val);  // add val at end
    ++sz;                            // increase the size
}

//------------------------------------------------------------------------------
//copy assigment
template<class T, class A> vector<T,A>& vector<T,A>::operator=(const vector<T,A>& a)
{
    if (this == &a) return *this;     // self-assignment, no work needed
    if (a.sz<=space) {              // enough space, no need for new allocation
        for (int i=0; i<a.sz; ++i) alloc.construct(&elem[i],a.elem[i]); // copy
        sz = a.sz;
        return *this;
    }
    unique_ptr<T> _p { alloc.allocate(a.sz) }; // allocate new space
    T* p = _p.get();
    for (int i=0; i<a.sz; ++i) alloc.construct(&p[i],a.elem[i]); // copy
    alloc.deallocate(elem,space);    // deallocate old space

    space = sz = a.sz;              // set new size
    elem = _p.release();            // set new elements 
    return *this;                   // return a self-reference 
}

//------------------------------------------------------------------------------
//copy constructor
template<class T, class A> vector<T,A>::vector(const vector<T,A>& a)
{
    unique_ptr<T> _p { alloc.allocate(a.sz) }; // allocate new space
    T* p = _p.get();
    for (int i=0; i<a.sz; ++i) alloc.construct(&p[i],a.elem[i]); // copy
    space = sz = a.sz;              // set new size
    elem = _p.release();            // set new elements 
}

//------------------------------------------------------------------------------
// acces with out_of_range check
template<typename T, typename A > T& vector<T,A>::at(int n)
{
    if (n<0 || sz<=n) throw out_of_range();
    return elem[n];
}

//------------------------------------------------------------------------------
template<class T, class A> vector<T,A>::vector(int s)
{
    if (s < 0) std::cerr << "size can not be negative!";
    vector();
    resize(s);
}

//------------------------------------------------------------------------------
//  myself unique_ptr 
template<class T> T* unique_ptr<T>::release()
{
    T* p = ptr;
    ptr = nullptr;
    return p;
}

//------------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const Type0& T)
{
    os << "(" << T.i << ", " << T.j << ") ";
    return os;
}

template <typename T> void f(counted_ptr<T> t)
{
    std::cout << "*t: " << *t << ", ptr_count: " << t.count() << std::endl;
}

//copy assigment constructor
template <typename T> counted_ptr<T>& counted_ptr<T>::operator=(const counted_ptr<T>& a)
{
    ptr = a.ptr;
    ptr_count = a.ptr_count;
    *ptr_count+=1;
    return *this;
}

//------------------------------------------------------------------------------
int main()
{
    //test case 1:
    std::cout << "test case 1(copy constructor):\n";
    counted_ptr<Type0> ptr(Type0(3,14));
    std::cout << "*ptr: " << *ptr << ", ptr_count: " << ptr.count() << std::endl;
    std::cout << "f(ptr): ";
    f(ptr);
    std::cout << "*ptr: " << *ptr << ", ptr_count: " << ptr.count() << std::endl;
    std::cout << std::endl;

    std::cout << "test case 2(vector filling):\n";
    {
        vector< counted_ptr <Type0>> vc;
        for (int i=0; i<3; i++) {
            vc.push_back(ptr);
            std::cout << "*ptr: " << *ptr << ", ptr_count: " << ptr.count() << std::endl;
            std::cout << "*vc[" << i << "]: " << *vc[i] << " vc[" << i << "].ptr_count: " << vc[i].count() << std::endl;
        }
    }
    std::cout << "Deleted vector object - vc\n";
    std::cout << "*ptr: " << *ptr << ", ptr_count: " << ptr.count() << std::endl;
    std::cout << std::endl;

    std::cout << "test case 3(std::vector filling):\n";
    {
        std::vector< counted_ptr <Type0>> vc;
        for (int i=0; i<3; i++) {
            vc.push_back(ptr);
            std::cout << "*ptr: " << *ptr << ", ptr_count: " << ptr.count() << std::endl;
            std::cout << "*vc[" << i << "]: " << *vc[i] << " vc[" << i << "].ptr_count: " << vc[i].count() << std::endl;
        }
    }
    std::cout << "Deleted vector object - vs\n";
    std::cout << "*ptr: " << *ptr << ", ptr_count: " << ptr.count() << std::endl;
    std::cout << std::endl;

    std::cout << "test case 4(copy assigment):\n";
    {
        counted_ptr<Type0> ptr2;
        std::cout << "ptr2 = ptr;\n";
        ptr2 = ptr;
        std::cout << "*ptr2: " << *ptr2 << ", ptr_count: " << ptr2.count() << std::endl;
        std::cout << "*ptr: " << *ptr << ", ptr_count: " << ptr.count() << std::endl;
    }
    std::cout << "Deleted object - ptr2\n";
    std::cout << "*ptr: " << *ptr << ", ptr_count: " << ptr.count() << std::endl;
    std::cout << std::endl;

    return 0;
}
