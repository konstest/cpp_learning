//
//	Глава 11. Упражнение 7. Интересное использование ifstream с istringstream
//	п.с. доработанная програма из главы 11.7 для считывания данных из файла.

//
// This is example code from Chapter 11.7 "Using non-standard separators" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "code.h"

using namespace std;

//------------------------------------------------------------------------------

class Punct_stream { // like an istream, but the user can add to
                     // the set of whitespace characters
public:
//    Punct_stream(istream& is)
    Punct_stream(ifstream& is)
        : source(is), sensitive(true) { }

    void whitespace(const string& s)       // make s the whitespace set
    { white = s; }    
    void add_white(char c) { white += c; } // add to the whitespace set
    bool is_whitespace(char c);            // is c in the whitespace set?

    void case_sensitive(bool b) { sensitive = b; }
    bool is_case_sensitive() { return sensitive; }

    Punct_stream& operator>>(string& s);
    operator bool();
private:
//    istream& source;       // character source
    ifstream& source;       // character source
    istringstream buffer;  // we let buffer do our formatting
    string white;          // characters considered "whitespace"
    bool sensitive;        // is the stream case sensitive?
};

//------------------------------------------------------------------------------

Punct_stream& Punct_stream::operator>>(string& s)
{
    while (!(buffer>>s)) {    // try to read from buffer
//        if (buffer.bad() || !source.good()) return *this;
        if (buffer.bad() || source.eof()) return *this;
        buffer.clear();

        string line;
        getline(source,line); // get a line from source

        // do character replacement as needed:
        for (int i =0; i<line.size(); ++i)
//            if (is_whitespace(line[i]))
            if (!isalnum(line[i]))
                line[i]= ' ';
            else if (!sensitive)
                line[i] = tolower(line[i]);

        buffer.str(line);     // put string into stream
    }
    return *this;
}

//------------------------------------------------------------------------------

bool Punct_stream::is_whitespace(char c)
{
    for (int i = 0; i<white.size(); ++i) if (c==white[i]) return true;
    return false;
}

//------------------------------------------------------------------------------

Punct_stream::operator bool()
{
    return !(source.fail() || source.bad()) && source.good();
}

//------------------------------------------------------------------------------

int main()
// given in text file input, produce a sorted list of all words in that text
// ignore punctuation and case differences eliminate duplicates from the output
try
{
    cout << "Please enter filename: \n";
    string filename;
    cin >> filename;
    ifstream f(filename);
    if (!f) error ("Don`t read this file: ",filename);
    Punct_stream ps(f);
//    ps.whitespace(";:,.?!()\"{}<>/&$@#%^*|~"); // note \" means " in string
    ps.case_sensitive(false);

    string word;
    vector<string> vs;
    while (ps>>word) vs.push_back(word);    // read words

    sort(vs.begin(),vs.end());              // sort in lexicographical order
    for (int i=0; i<vs.size(); ++i)         // write dictionary
        if (i==0 || vs[i]!=vs[i-1]) cout << vs[i] << endl;
}
catch (exception& e) {
    cerr << e.what() << endl;
    return 1;
}
catch (...) {
    cerr << "Oops... exception...\n";
    return 2;
}

