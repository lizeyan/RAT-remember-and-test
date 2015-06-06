#ifndef _______AdjEntry__
#define _______AdjEntry__

#include "Entry.h"
#include <iostream>

class AdjEntry:public Entry
{
private:
    int predOrAttr;
    std::vector<std::string> comparative;
    std::vector<std::string> highest;
protected:
    void Output(std::ostream&) const;
public:
    AdjEntry();
    AdjEntry(std::string&, std::string&, std::string&, std::string&, std::vector<std::string>&,
             int, std::vector<std::string>&, std::vector<std::string>&);
    int GetPredOrAttr ()	const {return predOrAttr;}
    std::string GetComparative(int)const;
    std::string GetHighest(int)const;
    ~AdjEntry() {}
};

#endif /* defined(_______AdjEntry__) */
