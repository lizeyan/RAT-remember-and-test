#include "NounEntryFactory.h"
using namespace std;

Entry* NounEntryFactory::create(vector<string>& source)
{
    int exampleBegin = 4, exampleEnd = 3;
    while (source[++exampleEnd] != ".");
    vector<string> examples;
    examples.clear();
    for (int i = exampleBegin; i < exampleEnd; ++i)
        examples.push_back(source[i]);
    int count = atoi (source[++exampleEnd].c_str());
    int a = atoi (source[++exampleEnd].c_str());
    int pro = atoi (source[++exampleEnd].c_str());
    int sing = atoi (source[++exampleEnd].c_str());
    return new NounEntry(source[0], source[1], source[2],
                         source[3], examples, count, a, pro, sing,
                         source[++exampleEnd], source[++exampleEnd],
                         source[++exampleEnd]);
}