#ifndef _______NounEntry__
#define _______NounEntry__

#include "Entry.h"
#include <iostream>

class NounEntry:public Entry
{
private:
    friend class NounFactory;
    int countable;
    int aOrAn;
    int proper;
    int single;
    std::string completeForm;
    std::string abbrForm;
    std::string pluralForm;
protected:
    void Output(std::ostream&) const;
public:
    NounEntry ();
    NounEntry (std::string&, std::string&, std::string&, std::string&,
               std::vector<std::string>&,
               int, int, int, int, std::string&, std::string&, std::string&);
    int GetCountable() const {return countable;}
    int getAOrAn()	const {return aOrAn;}
    int GetProper()	const {return proper;}
    int GetSingle()	const{return single;}
    std::string GetCompleteForm()	const {return completeForm;}
    std::string GetAbbrForm()	const {return abbrForm;}
    std::string GetPluralForm() const {return pluralForm;}
    ~NounEntry() {}
};

#endif /* defined(_______NounEntry__) */
