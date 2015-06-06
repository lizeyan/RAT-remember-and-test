#ifndef _______NounEntryFactory__
#define _______NounEntryFactory__

#include "EntryFactory.h"
#include <iostream>

class NounEntryFactory:public EntryFactory
{
public:
    Entry* create (std::vector<std::string>&);
};

#endif /* defined(_______NounEntryFactory__) */
