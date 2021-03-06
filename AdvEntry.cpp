#include "AdvEntry.h"
using namespace std;


AdvEntry::AdvEntry (string& ph, string& wo, string& mec, string& mee,
                    std::vector<string>& ex, vector<string>& co, vector<string>& hi):
Entry(ph, wo, mec, mee, ex),comparative(co), highest(hi)
{
    //test = new AdvTest;
}
AdvEntry::AdvEntry ()
{
    //test = new AdvTest;
}
void AdvEntry::Output(ostream& out) const
{
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
ostream& operator<< (ostream& out, vector<string> v);
void AdvEntry::OutputSource(ostream& fout) const
{
    fout << comparative << highest;
}
bool AdvEntry::Match(string& str) const
{
    if (binary_search(comparative.begin(), comparative.end(), str))
        return true;
    if (binary_search(highest.begin(), highest.end(), str))
        return true;
    return false;
}