//:Word.cpp
#include "Word.h"
#include "Entry.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <cmath>
using namespace std;
Word::Word ()
{
    quan0=EntrySize();
    quan1=EntrySize();
    quan2=EntrySize();
    //remember = new remember;
    quanReview=1;
    zu=false;
    huiHe=0;
    int zhiShuDian=0;
    time_t t = time(0);
    char tmp[5];
    strftime( tmp, sizeof(tmp), "%j",localtime(&t) );
    int lishi=atoi(tmp);
    lishi-=reciteTime[0][0];
    int i;
    for(i=0; ; i++){
        if(pow(2,i)>lishi) break;
    }
    int have=reviewDay;
    i-=have;
    zhiShuDian=i>=0?i:0;
    quanSelect=1;
    for(int i=0; i<zhiShuDian; i++){
        quanSelect*=2;
    }
    quanSelect*=(wrong/(right+1)+1)>8? 8: wrong/(right+1)+1;
    quanSelect-=reviewDay;
    quanSelect=quanSelect>=1? quanSelect : 1;
}
Word::Word (const Word& w): spell(w.spell), entries(w.entries)
{
    quan0=EntrySize();
    quan1=EntrySize();
    quan2=EntrySize();
    //remember = new remember(w.remember);
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
    out << w.spell << endl;
    for (int i = 0; i < w.entries.size(); ++i)
    {
        out << "entry " << i + 1 << endl;
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