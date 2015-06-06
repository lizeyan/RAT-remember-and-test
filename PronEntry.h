#ifndef _______PronEntry__
#define _______PronEntry__

#include "Entry.h"
#include <iostream>

class PronEntry:public Entry
{
private:
    int person;
    int single;
protected:
    void Output(std::ostream&) const;
public:
    PronEntry();
    PronEntry (std::string&, std::string&, std::string&, std::string&, std::vector<std::string>&,
               int ,int);
    int GetPerson()	const{return person;}
    int GetSingle() const{return single;}
    ~PronEntry() {}
};

#endif /* defined(_______PronEntry__) */
