#ifndef _______ConjEntryFactory__
#define _______ConjEntryFactory__

#include "EntryFactory.h"
#include <iostream>
#include <cstdlib>

class ConjEntryFactory:public EntryFactory
{
public:
    Entry* create (std::vector<std::string>&);
};

#endif /* defined(_______ConjEntryFactory__) */
