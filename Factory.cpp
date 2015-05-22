//:Factory.cpp
#include "Word.h"
#include "Entry.h"
#include "Factory.h"
#include <vector>
#include <string>
#include <cstdio>//exit
#include <cstdlib>//atoi
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
    //cout << result->spell << endl;
    std::vector<string> entry;
    while (p < source.size())
    {
        entry.clear();
        EntryFactory* ef;
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
        delete ef;
    }//end while
    result->quan0=result->EntrySize();
    result->quan1=result->EntrySize();
    result->quan2=result->EntrySize();
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
Entry* NounEntryFactory::create(vector<string>& source)
{
    int exampleBegin = 4, exampleEnd = 3;
    while (source[++exampleEnd] != ".");
    vector<string> examples;
    examples.clear();
    for (int i = exampleBegin; i < exampleEnd; ++i)
        examples.push_back(source[i]);
    int count = atoi (source[++exampleEnd].c_str());
    int a = atoi (source[++exampleEnd].c_str());
    int pro = atoi (source[++exampleEnd].c_str());
    int sing = atoi (source[++exampleEnd].c_str());
    return new NounEntry(source[0], source[1], source[2],
                         source[3], examples, count, a, pro, sing,
                         source[++exampleEnd], source[++exampleEnd],
                         source[++exampleEnd]);
}
Entry* VerbEntryFactory::create(vector<string>& source)
{
    int exampleBegin = 4, exampleEnd = 3;
    while (source[++exampleEnd] != ".");
    vector<string> examples;
    examples.clear();
    for (int i = exampleBegin; i < exampleEnd; ++i)
        examples.push_back(source[i]);
    int viOrVt = atoi (source[exampleEnd + 1].c_str());
    int preBegin = exampleEnd + 3, preEnd = exampleEnd + 2, ptBegin, ptEnd, ppBegin, ppEnd, pBegin, pEnd;
    while (source[++preEnd] != ".");
    ptBegin = preEnd + 1;
    ptEnd = ptBegin - 1;
    while (source[++ptEnd] != ".");
    ppBegin = ptEnd + 1;
    ppEnd = ppBegin - 1;
    while (source[++ppEnd] != ".");
    pBegin = ppEnd + 1;
    pEnd = pBegin - 1;
    while (source[++pEnd] != ".");
    vector<string> preForm;
    for (int i = preBegin; i < preEnd; ++i)
        preForm.push_back (source[i]);
    vector<string> pastTense;
    for (int i = ptBegin; i < ptEnd; ++i)
        pastTense.push_back (source[i]);
    vector<string> pastParticle;
    for (int i = ppBegin; i < ppEnd; ++i)
        pastParticle.push_back (source[i]);
    vector<string> phrase;
    for (int i = pBegin; i < pEnd; ++i)
        phrase.push_back (source[i]);
    return new VerbEntry (source[0], source[1], source[2],
                          source[3], examples, viOrVt, source[exampleEnd + 2], preForm, pastTense,
                          pastParticle, phrase);
}
Entry* AdjEntryFactory::create(vector<string>& source)
{
    int exampleBegin = 4, exampleEnd = 3;
    while (source[++exampleEnd] != ".");
    vector<string> examples;
    examples.clear();
    for (int i = exampleBegin; i < exampleEnd; ++i)
        examples.push_back(source[i]);
    int predOrAttr = atoi (source[exampleEnd + 1].c_str());
    int comBegin = exampleEnd + 2, comEnd = exampleEnd + 1, hiBegin, hiEnd;
    while (source[++comEnd] != ".");
    hiBegin = comEnd + 1;
    hiEnd = hiBegin - 1;
    while (source[++hiEnd] != ".");
    vector<string> comparative;
    for (int i = comBegin; i < comEnd; ++i)
        comparative.push_back (source[i]);
    vector<string> highest;
    for (int i = hiBegin; i < hiEnd; ++i)
        highest.push_back (source[i]);
    return new AdjEntry (source[0], source[1], source[2],
                         source[3], examples, predOrAttr, comparative, highest);
}
Entry* AdvEntryFactory::create(vector<string>& source)
{
    int exampleBegin = 4, exampleEnd = 3;
    while (source[++exampleEnd] != ".");
    vector<string> examples;
    examples.clear();
    for (int i = exampleBegin; i < exampleEnd; ++i)
        examples.push_back(source[i]);
    int comBegin = exampleEnd + 1, comEnd = exampleEnd, hiBegin, hiEnd;
    while (source[++comEnd] != ".");
    hiBegin = comEnd + 1;
    hiEnd = hiBegin - 1;
    while (source[++hiEnd] != ".");
    vector<string> comparative;
    for (int i = comBegin; i < comEnd; ++i)
        comparative.push_back (source[i]);
    vector<string> highest;
    for (int i = hiBegin; i < hiEnd; ++i)
        highest.push_back (source[i]);
    return new AdvEntry (source[0], source[1], source[2],
                         source[3], examples, comparative, highest);
}
Entry* PronEntryFactory::create(vector<string>& source)
{
    int exampleBegin = 4, exampleEnd = 3;
    while (source[++exampleEnd] != ".");
    vector<string> examples;
    examples.clear();
    for (int i = exampleBegin; i < exampleEnd; ++i)
        examples.push_back(source[i]);
    int person = atoi (source[exampleEnd + 1].c_str());
    int single = atoi (source[exampleEnd + 2].c_str());
    return new PronEntry (source[0], source[1], source[2],
                          source[3], examples, person, single);
}
Entry* ConjEntryFactory::create(vector<string>& source)
{
    int exampleBegin = 4, exampleEnd = 3;
    while (source[++exampleEnd] != ".");
    vector<string> examples;
    examples.clear();
    for (int i = exampleBegin; i < exampleEnd; ++i)
        examples.push_back(source[i]);
    return new ConjEntry (source[0], source[1], source[2],
                          source[3], examples, source[exampleEnd + 1]);
}
Entry* PrepEntryFactory::create (vector<string>& source)
{
    int exampleBegin = 4, exampleEnd = 3;
    while (source[++exampleEnd] != ".");
    vector<string> examples;
    examples.clear();
    for (int i = exampleBegin; i < exampleEnd; ++i)
        examples.push_back(source[i]);
    return new PrepEntry (source[0], source[1], source[2],
                          source[3], examples);
    
}