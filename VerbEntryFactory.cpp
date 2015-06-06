#include "VerbEntryFactory.h"
using namespace std;

Entry* VerbEntryFactory::create(vector<string>& source)
{
    int exampleBegin = 4, exampleEnd = 3;
    while (source[++exampleEnd] != ".");
    vector<string> examples;
    examples.clear();
    for (int i = exampleBegin; i < exampleEnd; ++i)
        examples.push_back(source[i]);
    int viOrVt = atoi (source[exampleEnd + 1].c_str());
    int preBegin = exampleEnd + 3, preEnd = exampleEnd + 2, ptBegin, ptEnd, ppBegin, ppEnd, pBegin, pEnd;
    while (source[++preEnd] != ".");
    ptBegin = preEnd + 1;
    ptEnd = ptBegin - 1;
    while (source[++ptEnd] != ".");
    ppBegin = ptEnd + 1;
    ppEnd = ppBegin - 1;
    while (source[++ppEnd] != ".");
    pBegin = ppEnd + 1;
    pEnd = pBegin - 1;
    while (source[++pEnd] != ".");
    vector<string> preForm;
    for (int i = preBegin; i < preEnd; ++i)
        preForm.push_back (source[i]);
    vector<string> pastTense;
    for (int i = ptBegin; i < ptEnd; ++i)
        pastTense.push_back (source[i]);
    vector<string> pastParticle;
    for (int i = ppBegin; i < ppEnd; ++i)
        pastParticle.push_back (source[i]);
    vector<string> phrase;
    for (int i = pBegin; i < pEnd; ++i)
        phrase.push_back (source[i]);
    return new VerbEntry (source[0], source[1], source[2],
                          source[3], examples, viOrVt, source[exampleEnd + 2], preForm, pastTense,
                          pastParticle, phrase);
}