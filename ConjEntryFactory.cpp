#include "ConjEntryFactory.h"
using namespace std;

Entry* ConjEntryFactory::create(vector<string>& source)
{
    int exampleBegin = 4, exampleEnd = 3;
    while (source[++exampleEnd] != ".");
    vector<string> examples;
    examples.clear();
    for (int i = exampleBegin; i < exampleEnd; ++i)
        examples.push_back(source[i]);
    return new ConjEntry (source[0], source[1], source[2],
                          source[3], examples, source[exampleEnd + 1]);
}