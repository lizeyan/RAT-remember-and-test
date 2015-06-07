#ifndef _______VerbEntryFactory__
#define _______VerbEntryFactory__

#include "EntryFactory.h"
#include <iostream>
#include <cstdlib>

class VerbEntryFactory:public EntryFactory
{
public:
    Entry* create (std::vector<std::string>&);
};

#endif /* defined(_______VerbEntryFactory__) */
