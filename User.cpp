//:User.cpp
#include "User.h"
#include <fstream>
#include <string>
#include <vector>
using namespace std;
User::User(string n, string p):name(n), password(p)
{
    ifstream fin((name + ".set").c_str());
    string setName;
    while (fin >> setName)
    {
        ifstream finSet ((setName + ".txt").c_str());
        Set* tmp = new Set(setName);
        tmp->Read (finSet);
        finSet.close();
        wordSets.push_back(tmp);
    }
    fin.close();
}
int  User::InsertSet(Set& targetSet)
{
    int pos = FindSet(targetSet.GetName());
    wordSets.insert(wordSets.begin() + pos + 1, &targetSet);
    return pos;
}
int User::FindSet (string targetSet) const
{
    int lo = 0, hi = wordSets.size();
    while (lo < hi)
    {
        int mi = (lo + hi) >> 1;
        (targetSet < wordSets[mi]->GetName())? hi = mi: lo = mi + 1;
    }
    return --lo;
}