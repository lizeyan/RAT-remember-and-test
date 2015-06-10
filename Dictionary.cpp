//:dictionary.cpp
#include "Dictionary.h"
#include "WordFactory.h"
#include "Set.h"
#include "Word.h"
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
bool cmp(Word a, Word b){
    return a.GetSpell()<b.GetSpell();
}
const int MaxFuzzyResult = 100;
Dictionary* Dictionary::instance = NULL;
Dictionary::Dictionary()	{}
Dictionary::Dictionary(const Dictionary& s)
:words(s.words)	{}
Dictionary* Dictionary::GetInstance ()
{
    if (instance == NULL)
        instance = new Dictionary;
    return instance;
}
int Dictionary::FindWordExact(string targetWord) const
{
    int lo = 0, hi = words.size();
    while (lo < hi)
    {
        int mi = (lo + hi) >> 1;
        (targetWord < words[mi].GetSpell())? hi = mi: lo = mi + 1;
    }
    return --lo;
}
int Dictionary::FindWord(string targetWord, bool insert) const
{
    //exact search
    int x = FindWordExact(targetWord);
    //when we are trying to insert a word,
    //  we also need the postion even it is illegal.
    if ((x >= 0 && x < words.size()) || insert == 1)
        return x;
    //other forms
    for (int i = 0; i < words.size(); ++i)
    {
        for (int j = 0 ; j < words[i].EntrySize(); ++j)
        {
            if (words[i].GetEntry(j)->Match(targetWord))
            {
                return i;
            }
        }//end entry
    }//end worrd
    return -1;
}
bool Dictionary::WordExist(string targetWord, bool insert)
{
    int pos = FindWord (targetWord, insert);
    if (pos < 0 || pos >= words.size())
        return false;
    if (targetWord == words[pos].GetSpell())
        return true;
    string diff = "false";
    for (int i = 0; i <targetWord.size() ;++i)
    {
        if (targetWord[i] != words[pos].GetSpell()[i] && i >= words[pos].GetSpell().size() - 1)
        {
            diff = targetWord.substr(i, targetWord.size() - i);
            if (diff[0] == targetWord[i - 1])
                diff = diff.substr(1, diff.size() - 1);
            break;
        }
    }
    return diff == "" || diff == "ing" || diff == "es" || diff == "s" || diff == "ed";
}
Word& Dictionary::operator[](int rank)
{
    return words[rank];
}
int Dictionary::Insert(Word& targetWord)
{
    int pos = FindWord(targetWord.GetSpell(), true);
    words.insert(words.begin() + pos + 1, targetWord);
    return pos;
}
void Dictionary::Sort()
{
    sort (words.begin(), words.end(), cmp);
}
void Dictionary::ReadAndAdd (std::istream& load)
{
    vector<string> wordString;
    string temp;
    WordFactory* factory = new WordFactory;
    Word* wordTemp;
    while (getline (load, temp))
    {
        if (temp == "*")
        {
            wordTemp = factory->create (wordString);
            if (!WordExist (wordTemp->spell, true))
            {
                Insert (*wordTemp);
            }
            wordString.clear();
        }
        else
            wordString.push_back (temp);
    }
    delete factory;
}
void Dictionary::Read(istream& load)
{
    words.clear();
    ReadAndAdd (load);
}
ostream& operator<< (ostream& out, Dictionary& dic)
{
    for (int i = 0; i < dic.words.size(); ++i)
    {
        cout << "word " << i + 1 << endl;
        cout << dic.words[i];
    }
    return out;
}
void Dictionary::getNext(int* next, string par)
{
    int j = 0, k = -1;
    next[0] = -1;
    int length = par.size();
    while (j != length)
    {
        if (k == -1 || par[j] == par[k])
        {
            ++j;
            ++k;
            if (par[j] != par[k])
                next[j] = k;
            else
                next[j] = next[k];
        }
        else
            k = next[k];
    }
}
int Dictionary::kmp(string a, string b)
{
    int* next = new int[a.size() + 1];
    getNext (next, a);
    int p = 0, q = 0;
    while (p < b.size())
    {
        if (a[q] == b[p])
        {
            q++;
            p++;
            if (q == a.size())
            {
                return p - q;
            }
        }
        else
        {
            if (next[q] == -1)
            {
                q = 0;
                ++p;
            }
            else
                q = next[q];
        }
    }
    delete next;
    return -1;
}
bool Dictionary::FindWordFuzzy(string s, vector<Word*>& target)
{
    bool res = false;
    target.clear();
    int limit = min (4, int(s.size()) / 3 + 1);
    for (int i = 0; i < limit;  ++i)
    {
        bool tmp = particalFind(0,i,target,s);
        if (!res)
            res = tmp;
    }
    return res;
}
bool Dictionary::particalFind(int level, int maxLevel, vector<Word*>& target, string& s)
{
    if (level == maxLevel)
    {
        bool res = false;
        for (int i = 0; i < words.size(); ++i)
        {
            if (target.size() >= 20)
                return res;
            if (kmp(s, words[i].GetSpell()) >= 0)
            {
                target.push_back(&words[i]);
                res = true;
            }
        }
        return res;
    }
    bool res;
    for (int i = 0; i < s.size(); ++i)
    {
        if (target.size() >= 20)
            return res;
        string tmp = s;
        tmp.erase(tmp.begin() + i);
        bool r = particalFind(level + 1, maxLevel, target, tmp);
        if (!res)
            res = r;
    }
    return res;
}