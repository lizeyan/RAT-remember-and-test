#ifndef _______AdjEntryFactory__
#define _______AdjEntryFactory__
#include "EntryFactory.h"
#include "AdjEntry.h"
#include <iostream>
#include <cstdlib>

class AdjEntryFactory:public EntryFactory
{
public:
    Entry* create (std::vector<std::string>&);
};

#endif /* defined(_______AdjEntryFactory__) */
