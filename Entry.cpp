//:Entry.cpp
#include "Entry.h"
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
void OutputString(ostream& out, string tips, const string source)
{
    if (tips != "")
        tips += ": ";
    if (source != "")
    {
        out << tips << source << endl;
    }
}
std::string GetMember(const std::vector<string>& ve, int rank)
{
    if (rank >= ve.size() || rank < 0)
        return string("");
    else
        return ve[rank];
}

Entry::Entry (string& ph, string& wo, string& mec, string& mee,
              std::vector<string>& ex): phonogram(ph), wordClass(wo), meaningC(mec),
meaningE(mee), example(ex)	{
    test=new Test();
}
Entry::Entry()	{
    test=new Test();
};
string Entry::GetExample(int rank) const
{
    return GetMember(example, rank);
}
void Entry::OutputEle(ostream& out) const
{
    if (phonogram != "")
        out << "/" << phonogram << "/\t";
    if (wordClass != "")
        out << wordClass << endl;
    if (meaningC != "")
        out << meaningC << endl;
    if (meaningE != "")
        out << meaningE << endl;
    for (int i = 0; i < example.size(); ++i)
    {
        out << "\t" << example[i] << endl;
    }
}
ostream& operator<< (ostream& out, const Entry& e)
{
    e.OutputEle (out);
    e.Output (out);
    return out;
}
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
//adv?
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
bool NounEntry::Match(string& str) const
{
    if (str == completeForm || str == abbrForm || str == pluralForm)
        return true;
    return false;
}
bool VerbEntry::Match(string& str) const
{
    if (binary_search(presentForm.begin(), presentForm.end(), str))
        return true;
    if (binary_search(pastTense.begin(), pastTense.end(), str))
        return true;
    if (binary_search(pastParticle.begin(), pastParticle.end(), str))
        return true;
    if (binary_search(phrase.begin(), phrase.end(), str))
        return true;
    return false;
}
bool AdjEntry::Match(string& str) const
{
    if (binary_search(comparative.begin(), comparative.end(), str))
        return true;
    if (binary_search(highest.begin(), highest.end(), str))
        return true;
    return false;
}
bool AdvEntry::Match(string& str) const
{
    if (binary_search(comparative.begin(), comparative.end(), str))
        return true;
    if (binary_search(highest.begin(), highest.end(), str))
        return true;
    return false;
}
bool  PronEntry::Match(string& str) const
{
    return false;
}
bool ConjEntry::Match(string& str) const
{
    return str == category;
}
bool PrepEntry::Match(string& str) const
{
    return false;
}
