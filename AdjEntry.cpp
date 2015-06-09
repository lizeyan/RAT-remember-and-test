#include "AdjEntry.h"

using namespace std;

std::string GetMember(const std::vector<string>& ve, int rank);
ostream& operator<< (ostream& out, vector<string> v);
AdjEntry::AdjEntry (string& ph, string& wo, string& mec, string& mee,
                    std::vector<string>& ex, int pre, std::vector<string>& co, std::vector<string>& hi):
Entry(ph, wo, mec, mee, ex), predOrAttr(pre), comparative(co), highest(hi)
{
    //test = new AdjTest;
}
AdjEntry::AdjEntry ()
{
    //test = new AdjEntry;
}
string AdjEntry::GetComparative(int rank) const
{
    return GetMember(comparative, rank);
}
string AdjEntry::GetHighest(int rank) const
{
    return GetMember(highest, rank);
}
void AdjEntry::Output (ostream& out) const
{
    if (predOrAttr >= 0)
        out << (predOrAttr? "attribute adjective": "preadicative adjective") << endl;
    for (int i = 0; i < comparative.size(); ++i)
    {
        if (i == 0)
            out << "comparative form:" << endl;
        out << "\t" << comparative[i] << endl;
    }
    for (int i = 0; i < highest.size(); ++i)
    {
        if (i == 0)
            out << "highest form:" << endl;
        out << "\t" << highest[i] << endl;
    }
}
bool AdjEntry::Match(string& str) const
{
    if (binary_search(comparative.begin(), comparative.end(), str))
        return true;
    if (binary_search(highest.begin(), highest.end(), str))
        return true;
    return false;
}
void AdjEntry::OutputSource(ostream& fout) const
{
    fout << predOrAttr << endl
    << comparative << highest;
}