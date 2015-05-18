//:User.cpp
#include "User.h"
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
User::User(string n, string p, string level):name(n), password(p)
{
    stringstream ss;
    ss << level;
    int levelInt;
    ss >> levelInt;
    this->level = levelInt;
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