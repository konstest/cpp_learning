/* 
 * Chapter 19. Exercise 12.
 * Define a File_handle class with a constructor that takes a string
 * argument (the file name), opens the file in theconstructor, and closes
 * it in the destructor
 * clear; g++ -o code code.cpp -std=c++0x && ./code
 */

#include "code.h"

//------------------------------------------------------------------------------
File_handle::File_handle(const string& name)
{
    //http://www.cplusplus.com/reference/fstream/fstream/open/
    _file.open(name,ios_base::in);
    if (!_file) error("Can`t open file "+name);
    _filename = name;
}

void File_handle::output()
{
    char ch;
    while (_file.get(ch)) {
        cout << ch;
    }
}
//------------------------------------------------------------------------------
int main()
{
    File_handle f("code.h");
    f.output();

    return 0;
}
