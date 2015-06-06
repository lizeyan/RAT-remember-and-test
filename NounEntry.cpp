#include "NounEntry.h"

using namespace std;

void OutputString(ostream& out, string tips, const string source);

NounEntry::NounEntry(string& ph, string& wo, string& mec, string& mee,
                     std::vector<string>& ex, int co, int a, int p, int s, string& c,
                     string& ab, string& pl):Entry(ph, wo, mec, mee, ex), countable(co),
aOrAn(a), proper(p), single(s), completeForm(c), abbrForm(ab),
pluralForm(pl)
{
    //test = new NounTest;
}
NounEntry::NounEntry()
{
    //test = new NounTest;
}
void NounEntry::Output(ostream& out) const
{
    if (countable >= 0)
        out << (countable?"countable noun":"uncountable noun") << endl;
    if (aOrAn >= 0)
        out << (aOrAn?"a":"an") << endl;
    if (proper >= 0)
        out << (proper?"proper noun":"not proper noun") << endl;
    if (single >= 0)
        out << (single?"single":"plural") << endl;
    OutputString (out, "completeForm", completeForm);
    OutputString (out, "abbrForm", abbrForm);
    OutputString (out, "pluralForm", pluralForm);
}