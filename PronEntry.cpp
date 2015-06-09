#include "PronEntry.h"
using namespace std;

PronEntry::PronEntry(string& ph, string& wo, string& mec, string& mee,
                     std::vector<string>& ex, int p, int s):
Entry(ph, wo, mec, mee, ex), person(p), single(s)
{
    //test = new PronTest;
}
PronEntry::PronEntry ()
{
    //test = new PronTest;
}
void PronEntry::Output (ostream& out) const
{
    string personString[3] = {"first", "second", "third"};
    if (person >= 1)
        out << personString[person - 1] << " person" << endl;
    if (single >= 0)
        out << (single?"single form":"plural form") << endl;
}
void PronEntry::OutputSource(ostream& fout) const
{
    fout << person << endl << single << endl;
}
bool  PronEntry::Match(string& str) const
{
    return false;
}