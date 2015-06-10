#ifndef _______PronEntryFactory__
#define _______PronEntryFactory__

#include "EntryFactory.h"
#include "PronEntry.h"
#include <iostream>
#include <cstdlib>

class PronEntryFactory:public EntryFactory
{
public:
    Entry* create (std::vector<std::string>&);
};

#endif /* defined(_______PronEntryFactory__) */
