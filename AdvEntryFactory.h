#ifndef _______AdvEntryFactory__
#define _______AdvEntryFactory__

#include "EntryFactory.h"
#include <iostream>

class AdvEntryFactory:public EntryFactory
{
public:
    Entry* create (std::vector<std::string>&);
};

#endif /* defined(_______AdvEntryFactory__) */
