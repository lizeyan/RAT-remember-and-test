#include "ConjEntry.h"

using namespace std;

void OutputString(ostream& out, string tips, const string source);

ConjEntry::ConjEntry(string& ph, string& wo, string& mec, string& mee,
                     std::vector<string>& ex, string& c):
Entry(ph, wo, mec, mee, ex), category(c)
{
    //test = new ConjTest;
}
ConjEntry::ConjEntry ()
{
    //test = new ConjTest;
}
void ConjEntry::Output (ostream& out) const
{
    OutputString (out, "category", category);
}
bool ConjEntry::Match(string& str) const
{
    return str == category;
}