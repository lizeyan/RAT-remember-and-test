#ifndef _______WordFactory__
#define _______WordFactory__

#include "EntryFactory.h"
#include "Word.h"
#include "PrepEntryFactory.h"
#include "ConjEntryFactory.h"
#include "PronEntryFactory.h"
#include "AdvEntryFactory.h"
#include "AdjEntryFactory.h"
#include "VerbEntryFactory.h"
#include "NounEntryFactory.h"
#include <iostream>
#include <cstdlib>

class WordFactory
{
protected:
    EntryFactory* typeChoose (std::string&);
public:
    Word* create (std::vector<std::string>&);//new 一个word*,传出去
};

#endif /* defined(_______WordFactory__) */
