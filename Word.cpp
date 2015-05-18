//:Word.cpp
#include "Word.h"
#include "Entry.h"
#include <iostream>
using namespace std;
Word::Word ()
{
    //remember = new remember;
}
Word::Word (const Word& w): spell(w.spell), entries(w.entries)
{
    //remember = new remember(w.remember);
}
void Word::Test()
{
    cout << "test: " << spell << endl;
    for (int i = 0; i < entries.size(); ++i)
    {
        //
    }
}
ostream& operator<< (ostream& out, Word& w)
{
    out << w.spell << endl;
    for (int i = 0; i < w.entries.size(); ++i)
    {
        out << "entry " << i + 1 << endl;
        out << *(w.entries[i]) << endl;
    }
    return out;
    
}