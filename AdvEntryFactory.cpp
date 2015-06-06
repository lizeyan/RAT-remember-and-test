#include "AdvEntryFactory.h"
using namespace std;

Entry* AdvEntryFactory::create(vector<string>& source)
{
    int exampleBegin = 4, exampleEnd = 3;
    while (source[++exampleEnd] != ".");
    vector<string> examples;
    examples.clear();
    for (int i = exampleBegin; i < exampleEnd; ++i)
        examples.push_back(source[i]);
    int comBegin = exampleEnd + 1, comEnd = exampleEnd, hiBegin, hiEnd;
    while (source[++comEnd] != ".");
    hiBegin = comEnd + 1;
    hiEnd = hiBegin - 1;
    while (source[++hiEnd] != ".");
    vector<string> comparative;
    for (int i = comBegin; i < comEnd; ++i)
        comparative.push_back (source[i]);
    vector<string> highest;
    for (int i = hiBegin; i < hiEnd; ++i)
        highest.push_back (source[i]);
    return new AdvEntry (source[0], source[1], source[2],
                         source[3], examples, comparative, highest);
}