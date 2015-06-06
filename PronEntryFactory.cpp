#include "PronEntryFactory.h"
using namespace std;

Entry* PronEntryFactory::create(vector<string>& source)
{
    int exampleBegin = 4, exampleEnd = 3;
    while (source[++exampleEnd] != ".");
    vector<string> examples;
    examples.clear();
    for (int i = exampleBegin; i < exampleEnd; ++i)
        examples.push_back(source[i]);
    int person = atoi (source[exampleEnd + 1].c_str());
    int single = atoi (source[exampleEnd + 2].c_str());
    return new PronEntry (source[0], source[1], source[2],
                          source[3], examples, person, single);
}