#include "WordFactory.h"
#include "Entry.h"
#include "NounEntry.h"
#include "VerbEntry.h"
#include "AdjEntry.h"
#include "AdvEntry.h"
#include "PronEntry.h"
#include "PrepEntry.h"
#include "ConjEntry.h"
#include <ctime>
#include <cmath>
using namespace std;

EntryFactory* WordFactory::typeChoose (string& typeString)
{
    if (typeString == "noun")
        return new NounEntryFactory;
    else if (typeString == "verb")
        return new VerbEntryFactory;
    else if (typeString == "adj")
        return new AdjEntryFactory;
    else if (typeString == "adv")
        return new AdvEntryFactory;
    else if (typeString == "pron")
        return new PronEntryFactory;
    else if (typeString == "conj")
        return new ConjEntryFactory;
    else if (typeString == "prep")
        return new PrepEntryFactory;
    else
    {
        cout << "wrong in source file: wrong entry wordClass" << endl
        << "\tWhat's " << typeString << "?" << endl;
        exit(1);
    }
}

Word* WordFactory::create(vector<string>& source)
{
    int p = 0;
    Word* result = new Word;
    result->spell = source[p++];
    std::vector<string> entry;
    while (p < source.size())
    {
        entry.clear();
        EntryFactory* ef=NULL;
        int i = 0;
        while (source[p + i] != "#")
        {
            entry.push_back (source[p + i]);
            if (i == 1)
            {
                ef = typeChoose (source[p + i]);
            }//end if
            i++;
        }//end while
        p = p + i + 1;
        result->entries.push_back(ef->create(entry));
        if(p<source.size()){
            delete ef;
        }
    }//end while
    result->quan0=result->EntrySize();
    result->quan1=result->EntrySize();
    result->quan2=result->EntrySize();
    result->right=0;
    result->reviewDay=0;
    result->haveRecited=false;
    //remember = new remember;
    result->quanReview=1;
    result->zu=false;
    result->huiHe=0;
    if(result->haveRecited){
        int zhiShuDian=0;
        time_t t = time(0);
        char tmp[5];
        strftime( tmp, sizeof(tmp), "%j",localtime(&t) );
        int lishi=atoi(tmp);
        lishi-=result->reciteTime[0][0];
        int i;
        for(i=0; ; i++){
            if(pow(2,i)>lishi) break;
        }
        int have=result->reviewDay;
        i-=have;
        zhiShuDian=i>=0?i:0;
        result->quanSelect[0]=1;
        result->quanSelect[1]=rand()%100000;
        for(int i=0; i<zhiShuDian; i++){
            result->quanSelect[0]*=2;
        }
        result->quanSelect[0]*=(result->wrong/(result->right+1)+1)>8? 8: result->wrong/(result->right+1)+1;
        result->quanSelect[0]-=result->reviewDay;
        result->quanSelect[0]=result->quanSelect[0]>=1? result->quanSelect[0] : 1;
    }else{
        result->quanSelect[0]=0;
    }
    return result;
}

Word* WordFactory::youdaoCreate(vector<string>& source)
{
    string sp;
    int begin = 0;
    while (begin < source[0].size() && source[0][begin] != ',')
        begin++;
    begin += 2;
    int end = begin;
    while (end < source[0].size() && source[0][end] != ' ')
        end++;
    for (int i = begin; i < end; ++i)
        sp += source[0][i];
    while (begin < source[0].size() && source[0][begin] != '[')
        begin++;
    while (end < source[0].size() && source[0][end] != ']')
        end++;
    if (end >= source[0].size() || source[0][end] != ']')
        return NULL;
    string phono;
    Word* w = new Word;
    w->spell = sp;
    for (int i = begin + 1; i < end; ++i)
        phono += source[0][i];
    source.erase(source.begin());
    for (int i = 0; i < source.size(); ++i)
    {
        string wordClass;
        int a = 0;
        while (a < source[i].size() && source[i][a] != '.')
            a++;
        for (int j = 0; j < a; ++j)
            wordClass += source[i][j];
        string m;
        for (int j = a + 2; j < source[i].size(); ++j)
            m += source[i][j];
        vector<string> tmp;
        string empty;
        if (wordClass == "n")
        {
            string wc = "noun";
            w->entries.push_back(new NounEntry(phono,wc , m, empty, tmp,-1,-1,-1,-1,empty, empty,empty));
        }
        else if (wordClass == "vi")
        {
            string wc = "verb";
            w->entries.push_back(new VerbEntry(phono,wc, m, empty,tmp, 0,empty,tmp,tmp,tmp,tmp));
        }
        else if (wordClass == "vt")
        {
            string wc = "verb";
            w->entries.push_back(new VerbEntry(phono,wc, m, empty,tmp,1,empty,tmp,tmp,tmp,tmp));
        }
        else if (wordClass == "adj")
            w->entries.push_back(new AdjEntry(phono, wordClass, m, empty, tmp,-1,tmp, tmp));
        else if (wordClass == "adv")
            w->entries.push_back(new AdvEntry(phono, wordClass, m, empty,tmp,tmp,tmp));
        else if (wordClass == "pron")
            w->entries.push_back(new PronEntry(phono, wordClass, m, empty,tmp,-1,-1));
        else if (wordClass == "prep")
            w->entries.push_back(new PrepEntry(phono, wordClass, m, empty,tmp));
        else if (wordClass == "conj")
            w->entries.push_back(new ConjEntry(phono, wordClass, m, empty,tmp,empty));
    }
    return w;
}