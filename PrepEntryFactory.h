#ifndef _______PrepEntryFactory__
#define _______PrepEntryFactory__

#include "EntryFactory.h"
#include "PrepEntry.h"
#include <iostream>
#include <cstdlib>

class PrepEntryFactory:public EntryFactory
{
public:
    Entry* create (std::vector<std::string>&);
};

#endif /* defined(_______PrepEntryFactory__) */
