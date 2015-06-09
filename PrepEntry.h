#ifndef _______PrepEntry__
#define _______PrepEntry__

#include "Entry.h"
#include <iostream>
#include <algorithm>

class PrepEntry:public Entry
{
protected:
    void Output (std::ostream&) const;
public:
    bool Match(std::string&) const;
    PrepEntry ();
    PrepEntry (std::string&, std::string&, std::string&, std::string&, std::vector<std::string>&);
    ~PrepEntry() {}
    void OutputSource(std::ostream&) const;
};

#endif /* defined(_______PrepEntry__) */
