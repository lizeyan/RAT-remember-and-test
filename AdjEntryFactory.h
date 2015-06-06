#ifndef _______AdjEntryFactory__
#define _______AdjEntryFactory__

#include "EntryFactory.h"
#include <iostream>

class AdjEntryFactory:public EntryFactory
{
public:
    Entry* create (std::vector<std::string>&);
};

#endif /* defined(_______AdjEntryFactory__) */
