/* 
 * Заглолвочный файл
 */

struct out_of_range {};

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
    ~vector() { delete[ ] elem; }       // destructor

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
