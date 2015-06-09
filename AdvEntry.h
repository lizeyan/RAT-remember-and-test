#ifndef _______AdvEntry__
#define _______AdvEntry__

#include "Entry.h"
#include <iostream>
#include <algorithm>

class AdvEntry:public Entry
{
private:
    std::vector<std::string> comparative;
    std::vector<std::string> highest;
protected:
    void Output(std::ostream&) const;
public:
    bool Match(std::string&) const;
    AdvEntry();
    AdvEntry (std::string&, std::string&, std::string&, std::string&, std::vector<std::string>&,
              std::vector<std::string>&, std::vector<std::string>&);
    std::string GetComparative(int)const;
    std::string GetHighest(int)const;
    void OutputSource(std::ostream&) const;
    ~AdvEntry() {}
};

#endif /* defined(_______AdvEntry__) */
