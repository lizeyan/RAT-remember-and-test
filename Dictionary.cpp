//:dictionary.cpp
#include "Dictionary.h"
#include "Factory.h"
#include "Set.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
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
int Dictionary::FindWord(string targetWord) const
{
    int lo = 0, hi = words.size();
    while (lo < hi)
    {
        int mi = (lo + hi) >> 1;
        (targetWord < words[mi].GetSpell())? hi = mi: lo = mi + 1;
    }
    return --lo;
}
bool Dictionary::WordExist(string targetWord)
{
    int pos = FindWord (targetWord);
    if (pos < 0 || pos >= words.size())
        return false;
    return words[pos].GetSpell() == targetWord;
}
Word& Dictionary::operator[](int rank)
{
    return words[rank];
}
int Dictionary::Insert(Word& targetWord)
{
    int pos = FindWord(targetWord.GetSpell());
    words.insert(words.begin() + pos + 1, targetWord);
    return pos;
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
            //cout << wordTemp->GetSpell() <<endl;
            if (!WordExist (wordTemp->GetSpell()))
            {
                Insert (*wordTemp);
            }
            wordString.clear();
        }
        else
            wordString.push_back (temp);
    }
    delete wordTemp;
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
    for (int i = 0; i < words.size(); ++i)
    {
        if (kmp(s, words[i].GetSpell()) >= 0 
                && kmp(s, words[i].GetSpell()) < words[i].GetSpell().size())
        {
            target.push_back(&words[i]);
            res = true;
        }
    }
    return res;
}