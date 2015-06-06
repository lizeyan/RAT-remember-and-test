#include "VerbEntry.h"

using namespace std;

void OutputString(ostream& out, string tips, const string source);
std::string GetMember(const std::vector<string>& ve, int rank);

VerbEntry::VerbEntry(string& ph, string& wo, string& mec, string& mee,
                     std::vector<string>& ex, int v, string& tp, std::vector<string>& pr,
                     std::vector<string>& pat, std::vector<string>& pap, std::vector<string>& p):
Entry(ph, wo, mec,mee, ex), viOrVt(v), phrase(p), tpsForm(tp),
presentForm(pr), pastTense(pat), pastParticle(pap)
{
    //test = new VerbTest;
}
VerbEntry::VerbEntry ()
{
    //test = new VerbTest;
}
void VerbEntry::Output(ostream& out) const
{
    if (viOrVt >= 0)
        out << (viOrVt? "vt": "vi") << endl;
    OutputString (out, "tpsForm", tpsForm);
    for (int i = 0; i < presentForm.size(); ++i)
    {
        if (i == 0)
            out << "presentForm:" << endl;
        out << "\t" << presentForm[i] << endl;
    }
    for (int i = 0; i < pastTense.size(); ++i)
    {
        if (i == 0)
            out << "pastTense:" << endl;
        out << "\t" << pastTense[i] << endl;
    }
    for (int i = 0; i < pastParticle.size(); ++i)
    {
        if (i == 0)
            out << "pastParticle:" << endl;
        out << "\t" << pastParticle[i] << endl;
    }
    for (int i = 0; i < phrase.size(); ++i)
    {
        if (i == 0)
            out << "phrase:" << endl;
        out << "\t" << phrase[i] << endl;
    }
}
string VerbEntry::GetPresentFoem(int rank) const
{
    return GetMember(presentForm, rank);
}
string VerbEntry::GetPastForm(int rank) const
{
    return GetMember(pastTense, rank);
}
string VerbEntry::GetPastParticle(int rank) const
{
    return GetMember(pastParticle, rank);
}