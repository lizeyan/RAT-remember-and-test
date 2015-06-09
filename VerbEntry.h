#ifndef _______VerbEntry__
#define _______VerbEntry__

#include "Entry.h"
#include <iostream>
#include <algorithm>

class VerbEntry:public Entry
{
private:
    int viOrVt;
    std::string tpsForm;
    std::vector<std::string> presentForm;
    std::vector<std::string> pastTense;
    std::vector<std::string> pastParticle;
    std::vector<std::string> phrase;
protected:
    void Output(std::ostream&) const;
public:
    bool Match(std::string&) const;
    VerbEntry ();
    VerbEntry (std::string&, std::string&, std::string&, std::string&, std::vector<std::string>&,
               int, std::string&, std::vector<std::string>&, std::vector<std::string>&,
               std::vector<std::string>&, std::vector<std::string>&);
    int GetViOrVt()	{return viOrVt;}
    std::string GetPhrase(int)const;
    std::string GetTpsForm()	const {return tpsForm;}
    std::string GetPresentFoem(int)const;
    std::string GetPastForm(int)const;
    std::string GetPastParticle(int)const;
    void OutputSource(std::ostream&) const;
    ~VerbEntry() {}
};

#endif /* defined(_______VerbEntry__) */
