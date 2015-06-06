#ifndef _______EntryFactory__
#define _______EntryFactory__

#include "Entry.h"
#include "PrepEntry.h"
#include "ConjEntry.h"
#include "PronEntry.h"
#include "AdvEntry.h"
#include "AdjEntry.h"
#include "VerbEntry.h"
#include "NounEntry.h"
#include <iostream>

class EntryFactory
{
public:
    virtual Entry* create (std::vector<std::string>&) = 0;//new一个entry*传出去
};

#endif /* defined(_______EntryFactory__) */
