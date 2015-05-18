//:Word.h
#ifndef ___WORD___
#define ___WORD___
#include "Entry.h"
#include <string>
#include <vector>
class Remember;
class Word
{
private:
    friend class WordFactory;
    std::string spell;
    std::vector<Entry*> entries;
    Remember* remember;
public:
    friend std::ostream& operator<< (std::ostream&, Word&);
    std::string GetSpell()	const	{return spell;}
    Word ();
    Word (const Word&);
    void Test();
    int EntrySize(){
        return entries.size();
    }
    Entry* GetEntry(int i){
        return entries[i];
    }
};
#endif