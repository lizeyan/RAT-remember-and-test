#include "PrepEntry.h"
using namespace std;

PrepEntry::PrepEntry (string& ph, string& wo, string& mec, string& mee,
                      std::vector<string>& ex):Entry(ph, wo, mec, mee, ex)
{
    //
}
PrepEntry::PrepEntry ()
{
    //
}
void PrepEntry::Output(ostream& out) const	{}

bool PrepEntry::Match(string& str) const
{
    return false;
}
void PrepEntry::OutputSource(ostream&) const	{}