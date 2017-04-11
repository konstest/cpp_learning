/* 
 * Chapter 18. Exercises 1,2,3.
 * 1.
 * Write a function, char* strdup(const char*), that copies a C-style string
 * into memory it allocates on the free store. Do not use any standard library
 * functions. Do not use subscripting; use the dereference operator * instead.
 * clear; c++ -o code code.cpp -std=c++11 && ./code
 * 2.
 * Write a function, char* findx(const char* s, const char* x), that finds the
 * first occurrence of the C-style string x in s. Do not use any standard
 * library functions. Do not use subscripting; use the dereference operator
 * instead.
 * 3.
 * Write a function, int strcmp(const char* s1, const char* s2), that compares
 * C-style strings. Let it return a negative number if s1 is lexicographically
 * before s2, zero if s1 equals s2, and a positive number if s1 is
 * lexicographically after s2. Do not use any standard library functions. Do not
 * use subscripting; use the dereference operator * instead.
 * 4.
 * Consider what happens if you give strdup(), findx(), and strcmp() an
 * argument that is not a C-style string. Try it! First figure out how to get
 * a char* that doesn’t point to a zero-terminated array of characters and then
 * use it (never do this in real — non-experimental — code; it can create
 * havoc). Try it with free-store-allocated and stack-allocated “fake C-style
 * strings.” If the results still look reasonable, turn off debug mode.
 * Redesign and re-implement those three functions so that they take another
 * argument giving the maximum number of elements allowed in argument strings.
 * Then, test that with correct C-style strings and “bad” strings.
 */

#include "code.h"

using namespace std;

char* strdup(const char* s)
{
    int n=0;
    const char *p = s;      //
    while (*p) {            //
        n++;                //  Calculate numbers count
        p++;                //
    }                       //
    if (n>0) n++;   // up for '\0'
    char *ss = new char[n], *p1 = ss;
    p = s;
    while (*p)  {       // copy data to free store
        *p1 = *p;
        p++;
        p1++;
    }
    return ss;
}

char* findx(const char *s, const char *x)
{
    char *head_x = const_cast<char*>(x), *concur = nullptr;
    char *ss = const_cast<char*>(s), *xx = const_cast<char*>(x);
    bool ocur = true;
    while (*ss) {
        if (*ss == *head_x) {
            concur = const_cast<char*>(ss);
            while (*xx && *ss) {
                ss++; xx++;
                if ( *ss != *xx ) {
                    if (*xx)
                        ocur = false;
                    else
                        ocur = true;
                    break;
                }
            }
            if ( ocur )
                return concur;
        }
        if (*ss) ss++;
        xx = head_x;
        ocur = true;
    }
    return nullptr;
}

int strcmp(const char* s1, const char* s2)
{
    char *_s1 = const_cast<char*>(s1), *_s2 = const_cast<char*>(s2);
    while ( *_s1 && *_s2 ) {
        if (*_s1 < *_s2) 
            return -1;
        else if (*_s1 > *_s2) 
            return 1;
        else {
            _s1++; _s2++;
        }
    }
    if ( !*_s1 && !*_s2 )
        return 0;
    if ( !*_s1 && *_s2 )
        return -1;
    if ( *_s1 && !*_s2 )
        return 1;
}

int main()
{
    cout << "Chapter 18.\n" << endl;
    cout << "Exercises 1.\n";
    const char *str = "sjdf sd00ndjd 00fks jdn";
    char *s = strdup(str);
    cout << "STATIC store: " << str << endl;
    cout << "FREE store: " << s << endl;

    cout << endl << "Exercises 2.\n";
    const char *find_s = "01";
    cout << "Attempt 1:\n";
    cout << "STR: " << str << endl;
    cout << "Find ocur: " << find_s << endl;
    char *res = findx(str,find_s);
    if (res)
        cout << "Rezult: " << res << endl;
    else
        cout << "Not found ocurence :(" << endl;

    cout << "Attempt 2:\n";
    find_s = "00";
    cout << "STR: " << str << endl;
    cout << "Find ocur: " << find_s << endl;
    res = findx(str,find_s);
    if (res)
        cout << "Rezult: " << res << endl;
    else
        cout << "Not found ocurence :(" << endl;

    cout << endl << "Exercises 3.\n";
    const char *s1 = "qwe", *s2 = "qwerty";
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << strcmp(s1,s2) << endl;
    s1 = "qwerty";
    s2 = "qwe";
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << strcmp(s1,s2) << endl;
    s1 = "qwe";
    s2 = "qwe";
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << strcmp(s1,s2) << endl;

    cout << endl << "Exercises 4.1.\n";
    char *str_ = new char[5] { '1','2','3','4','5' };
    char *s_ = strdup(str_);
    cout << "STATIC store: " << str_ << endl;
    cout << "FREE store: " << s_ << endl;

    cout << endl << "Exercises 4.2.\n";
    char *find_s_ = new char[2] {'0','1'};
    cout << "Find ocur: " << find_s_ << endl;
    char *res_ = findx(str_,find_s_);
    if (res_)
        cout << "Rezult: " << res_ << endl;
    else
        cout << "Not found ocurence :(" << endl;

    cout << endl << "Exercises 4.3.\n";
    char S[3] = { 'q','w','e' };
    char S2[6] = { 'q','w','e','r','t','y' };
    const char *s1_ = S, *s2_ = S2;
    cout << "s1: " << s1_ << endl;
    cout << "s2: " << s2_ << endl;
    cout << strcmp(s1_,s2_) << endl;
    s1_ = S2;
    s2_ = S;
    cout << "s1: " << s1_ << endl;
    cout << "s2: " << s2_ << endl;
    cout << strcmp(s1_,s2_) << endl;
    s1_ = S;
    s2_ = S;
    cout << "s1: " << s1_ << endl;
    cout << "s2: " << s2_ << endl;
    cout << strcmp(s1_,s2_) << endl;

    return 0;
}
