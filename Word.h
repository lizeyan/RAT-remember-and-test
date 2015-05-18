//:Word.h
#ifndef ___WORD___
#define ___WORD___
#include "Entry.h"
#include <string>
#include <vector>
class Remember;
class Set;
class Word
{
private:
    friend class WordFactory;
    std::string spell;
    std::vector<Entry*> entries;
    Remember* remember;
    int quan0;
    int quan1;
    int quan2;
public:
    friend std::ostream& operator<< (std::ostream&, Word&);
    std::string GetSpell()	const	{return spell;}
    Word ();
    Word (const Word&);
    int EntrySize(){
        return entries.size();
    }
    Entry* GetEntry(int i){
        return entries[i];
    }
    void Quanchange0();
    void Quanchange1();
    void Quanchange2();
    friend int search(Set* m, int type);
    friend int* searchEntry(Word* m, int num, int type);
};
#endif