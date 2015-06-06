#ifndef _______AdvEntry__
#define _______AdvEntry__

#include "Entry.h"
#include <iostream>

class AdvEntry:public Entry
{
private:
    std::vector<std::string> comparative;
    std::vector<std::string> highest;
protected:
    void Output(std::ostream&) const;
public:
    AdvEntry();
    AdvEntry (std::string&, std::string&, std::string&, std::string&, std::vector<std::string>&,
              std::vector<std::string>&, std::vector<std::string>&);
    std::string GetComparative(int)const;
    std::string GetHighest(int)const;
    ~AdvEntry() {}
};

#endif /* defined(_______AdvEntry__) */
