//:Entry.cpp
#include "Entry.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

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