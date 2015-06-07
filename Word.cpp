//:Word.cpp
#include "Word.h"
#include "Entry.h"
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
bool operator < (const Word& a, const Word& b) {return a.GetSpell() < b.GetSpell();}
Word::Word ()
{
    quan0=EntrySize();
    quan1=EntrySize();
    quan2=EntrySize();
}
void Word::Quanchange0(){
    int lin=0;
    for(int i=0; i<EntrySize(); i++){
        lin+=entries[i]->test->quan0;
    }
    quan0=lin;
}
void Word::Quanchange1(){
    int lin=0;
    for(int i=0; i<EntrySize(); i++){
        lin+=entries[i]->test->quan1;
    }
    quan1=lin;
}
void Word::Quanchange2(){
    int lin=0;
    for(int i=0; i<EntrySize(); i++){
        lin+=entries[i]->test->quan2;
    }
    quan2=lin;
}
ostream& operator<< (ostream& out, Word& w)
{
    out << "******************************************************************************" << endl;
    out << w.spell << ":" << endl;
    for (int i = 0; i < w.entries.size(); ++i)
    {
        out << "------------------------------------------------------------------------------" << endl;
        out << *(w.entries[i]) << endl;
    }
    return out;
    
}
bool Word::Familiar()
{
    if (!haveRecited)
        return false;
    if (kill)
        return true;
    int correct = 0;
    int allNum = 0;
    for (int i = check.size() - 1; i >= 0; i--)
    {
        allNum++;
        if (check[i])
            correct++;
    }
    return double(correct) / allNum > 0.6;
}
string Word::sort()
{
    if (!haveRecited)
        return "hasn't recited yet";
    else if (kill)
        return "has been killed";
    else
    {
        int all = 0, ri = 0;
        for (int i = 0; i < check.size(); ++i)
        {
            all++;
            if (check[i])
                ri++;
        }
        stringstream ss;
        string r, a;
        ss << right;
        ss >> r;
        ss << (right + wrong);
        ss >> a;
        if ((double(ri) / all) > 0.5)
            return "familiar:" + r+ "/" + a;
        else
            return  "unfamiliar:" + r + "/" + a;
    }
}