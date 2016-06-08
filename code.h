/* 
 * Заглолвочный файл
 */
#include "std_lib_facilities.h"
#include <fstream>

//------------------------------------------------------------------------------
class File_handle {
    string _filename;
    fstream _file;
public:
    File_handle(const string& name);
    ~File_handle() {
        _file.close();
    }
    const string& filename() const { return _filename; }
    void output();      // read all file data
};

//------------------------------------------------------------------------------
