/* 
 * Заглолвочный файл
 */

struct out_of_range {};

//------------------------------------------------------------------------------
template <typename T> class counted_ptr {
private:
    T*      ptr;
    int*    ptr_count;
public:
    counted_ptr(): ptr(nullptr), ptr_count(nullptr) { } //default constructor
    counted_ptr(T val): ptr(new T(val)), ptr_count(new int) { *ptr_count = 1; } //constructor on value
    counted_ptr(const counted_ptr& a):  ptr(a.ptr), ptr_count(a.ptr_count) { *ptr_count+=1; }//copy constructor
    counted_ptr<T>& operator=(const counted_ptr<T>& a); //copy assigment
//    counted_ptr<T>& pointer_for_contaner() { *ptr_count+=1; return *this; }
    T* get() const { return ptr; }
    ~counted_ptr() {   //Destructor
        /*  Debug
        std::cout << "~counted_ptr();\n";
        std::cout << "ptr: " << ptr << std::endl;
        std::cout << "ptr_count--: " << ptr_count << std::endl;
        */
        if (*ptr_count > 1) {   
            *ptr_count-=1;      //decrease counts
//            std::cout << "ptr_count--: " << *ptr_count << std::endl;
        }
        else {
//            std::cout << "delete ptr/ptr_count;\n";
            delete ptr;
            delete ptr_count;
        }
    }
    T& operator[](int k) { return ptr[k]; }
    const T& operator[](int k) const { return ptr[k]; }
    T& operator*() { return *ptr; }
    const T& operator*() const { return *ptr; }
    T* operator->() { return ptr; }
    const T* operator->() const { return ptr; }
    int count() { return *ptr_count; }
};



//------------------------------------------------------------------------------
template <typename T> class unique_ptr {
private:
    T* ptr;
public:
    unique_ptr(): ptr(nullptr) {}
    unique_ptr(T* p): ptr(p) {}
    T* release();
    T* get() const { return ptr; }
    ~unique_ptr() { delete[] ptr; }
    T& operator[](int k) { return ptr[k]; }
    const T& operator[](int k) const { return ptr[k]; }
    T& operator*() { return *ptr; }
    const T& operator*() const { return *ptr; }
    T* operator->() { return ptr; }
    const T* operator->() const { return ptr; }
};



//------------------------------------------------------------------------------
// class allocator for class VECTOR
template<typename T> class allocator {
public:
    // ...
    T* allocate(int n);            // allocate space for n objects of type T
    void deallocate(T* p, int n);  // deallocate n objects of type T starting at p
    void construct(T* p, const T& v); // construct a T with the value v in p
    void destroy(T* p);            // destroy the T in p
};

//  CLASS VECTOR
template<typename T, typename A = allocator<T> > class vector {
    A alloc;    // use allocate to handle memory for elements
    int sz;     // the size
    T* elem;    // a pointer to the elements
    int space;  // size+free_space

    void reserve(int newalloc);
public:
    vector() : sz(0), elem(nullptr), space(0) { }    
    vector(int s);
    vector(const vector& a);            // copy constructor
    vector& operator=(const vector&);   // copy assignment
    ~vector() { 
//        std::cout << "~vector();\n";      //debug
//        (sz>1) ? delete[] elem : delete elem; 
/*        if (sz>1) {
            std::cout << elem->count() << std::endl; 
            std::cout << "delete[] elem;\n"; 
            delete[] elem;
        } else {
            std::cout << "delete elem;\n"; 
            delete elem;
        }
        */
        for (int i=0; i<sz; ++i) alloc.destroy(&elem[i]);   //invoke destructor;
        alloc.deallocate(elem,space);    // deallocate old space
    }       // destructor

    void resize(int newsize, T def = T()); // growth
    void push_back(const T& d);
    int size() { return sz; }
    int capacity() const { return space; }

    T& at(int n);           // checked accessconst 
    T& at(int n) const;     // checked access
    T& operator[](int n) { return elem[n]; }   // unchecked accessconst
    T& operator[](int n) const; // unchecked access
};






//------------------------------------------------------------------------------
class Type0 {
public:
    int i;
    int j;
    Type0(int ii, int jj): i(ii), j(jj) {}
};

std::ostream& operator<<(std::ostream&, const Type0&);

