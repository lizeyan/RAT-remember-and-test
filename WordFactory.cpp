#include "WordFactory.h"
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
    result->wrong=0;
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
        result->quanSelect=1;
        for(int i=0; i<zhiShuDian; i++){
            result->quanSelect*=2;
        }
        result->quanSelect*=(result->wrong/(result->right+1)+1)>8? 8: result->wrong/(result->right+1)+1;
        result->quanSelect-=result->reviewDay;
        result->quanSelect=result->quanSelect>=1? result->quanSelect : 1;
    }else{
        result->quanSelect=0;
    }
    return result;
}