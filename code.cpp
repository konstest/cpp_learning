/* 
 * Chapter 19. Exercise 8.
 * Implement an allocator (§19.3.7) using the basic allocation functions
 * malloc() and free() (§B.11.4). Get vector asdefined by the end of §19.4 to
 * work for a few simple test cases. Hint: Look up “placement new” and
 * “explicit call ofdestructor” in a complete C++ reference.
 * clear; g++ -o code code.cpp -std=c++0x && ./code
 */

#include <iostream> 
#include <cstring>
#include <cstdlib>
#include <memory>
#include "code.h"

//------------------------------------------------------------------------------

template<typename T, typename A> 
void vector<T,A>::reserve(int newalloc)
{
    if (newalloc<=space) return;     // never decrease allocation
    std::unique_ptr<T> _p { alloc.allocate(newalloc) }; // allocate new space
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
    memcpy(p,&v,sizeof(v));
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
std::ostream& operator<<(std::ostream& os, const Type0& T)
{
    os << "(" << T.i << ", " << T.j << ") ";
    return os;
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    vector<double> v1;
    std::cout << "v1.capacity: " << v1.capacity() << std::endl;

    v1.resize(7);                // add 100 copies of double(), that is 0.0
    std::cout << "v1.resize(7);\n";
    std::cout << "v1.capacity: " << v1.capacity() << std::endl;
    for (int i=0; i<v1.size(); i++)
        std::cout << v1[i] << " ";
    std::cout << std::endl;

    v1.resize(10, 2134);           // add 100 copies of 0.0 - mentioning 0.0 is redundant
    std::cout << "v1.resize(10, 2134);\n";
    std::cout << "v1.capacity: " << v1.capacity() << std::endl;
    for (int i=0; i<v1.size(); i++)
        std::cout << v1[i] << " ";
    std::cout << std::endl;

    v1.resize(50,13.11);
    std::cout << "v1.resize(50, 13.11);\n";
    std::cout << "v1.capacity: " << v1.capacity() << std::endl;
    for (int i=0; i<v1.size(); i++)
        std::cout << v1[i] << " ";
    std::cout << std::endl;

    v1.resize(10);
    std::cout << "v1.resize(10);\n";
    std::cout << "v1.capacity: " << v1.capacity() << std::endl;
    for (int i=0; i<v1.size(); i++)
        std::cout << v1[i] << " ";
    std::cout << std::endl;

    std::cout << std::endl;
    vector<Type0> v2;
//    vector<Type0> v2(3);  //error becouse Type0 has not a default constructor
    v2.resize(3,Type0(3,7));
    std::cout << "v2.resize(3,Type0(3,7));\n";
    std::cout << "v2.capacity: " << v2.capacity() << std::endl;
    for (int i=0; i<v2.size(); i++)
        std::cout << v2[i];
    std::cout << std::endl;
    v2.resize(10,Type0(10,20));
    std::cout << "v2.resize(10,Type0(10,20));\n";
    std::cout << "v2.capacity: " << v2.capacity() << std::endl;
    for (int i=0; i<v2.size(); i++)
        std::cout << v2[i];
    std::cout << std::endl;
    v2.resize(5,Type0(0,0));
    std::cout << "v2.resize(5,Type0(0,0));\n";
    std::cout << "v2.capacity: " << v2.capacity() << std::endl;
    for (int i=0; i<v2.size(); i++)
        std::cout << v2[i];
    std::cout << std::endl;
}

//------------------------------------------------------------------------------
