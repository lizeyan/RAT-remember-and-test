#ifndef _______PrepEntry__
#define _______PrepEntry__

#include "Entry.h"
#include <iostream>

class PrepEntry:public Entry
{
protected:
    void Output (std::ostream&) const;
public:
    PrepEntry ();
    PrepEntry (std::string&, std::string&, std::string&, std::string&, std::vector<std::string>&);
    ~PrepEntry() {}
};

#endif /* defined(_______PrepEntry__) */
