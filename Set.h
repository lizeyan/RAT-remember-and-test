//:Set.h
#ifndef ___SET___
#define ___SET___
#include <vector>
#include <string>
#include "Word.h"
/*
 格式
 顺序列出单词的拼写即可
 */
class Set
{
private:
    std::string setName;
    std::vector <Word*> words;
public:
    friend std::ostream& operator<< (std::ostream&, Set&);
    std::string GetName()	const {return setName;}
    int Find(std::string targetWord) const;
    Word& operator[] (int rank);
    int Insert (Word& targetWord);
    bool WordExist (std::string);
    void ReadAndAdd (std::istream& load);
    void Read (std::istream& load);
    int GetSize () {return words.size();}
    Word* GetWord(int i){
        return words[i];
    }
    Set();
    Set (std::string n): setName(n)	{}
};
#endif

