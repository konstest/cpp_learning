//------------------------------------------------------------------------------
/*
 * Chapter 20. Try this from part: 20.3 Sequences and iterators.
 * Write a function void copy(int* f1, int* e1, int* f2) that copies the
 * elements of an array of ints defined by[f1:e1) into another [f2:f2+(e1-f1)).
 * Use only the iterator operations mentioned above (not subscripting).
 */

#include "code.h"

void copy(int* f1, int* e1, int* f2) {
    while (true) {
        *f2 = *f1;
        if (f1 == e1)
            return;
        f2++;
        f1++;
    }
}

void print(int A[], int n) {
    for (int i=0; i<n; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

//------------------------------------------------------------------------------

int main()
try {
    int A[5] = {1,2,3,4,5}, B[5] = { 6,7,8,9,10 };
    int *Abegin = &A[0], *Aend = &A[4];
    int *Bbegin = &B[0], *Bend = &B[4];

    print(A,5);
    print(B,5);

    copy(Abegin,Aend,Bbegin);

    print(A,5);
    print(B,5);

    return 0;
}
catch (...) {
    std::cerr << "Some exception";
    return 1;
}
