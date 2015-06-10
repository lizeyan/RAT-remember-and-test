#ifndef _______AdvEntryFactory__
#define _______AdvEntryFactory__

#include "EntryFactory.h"
#include "AdvEntry.h"
#include <iostream>
#include <cstdlib>

class AdvEntryFactory:public EntryFactory
{
public:
    Entry* create (std::vector<std::string>&);
};

#endif /* defined(_______AdvEntryFactory__) */
