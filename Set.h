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
    std::vector <Word*> recited;
    std::vector <Word*> killed;
    int plusDay;//今天要多背的单词量
    int useDay;//背完这个set设定的时间
    int beginDay[2];//开始的时间
    int lastRecite[2];//上次背诵时间
    int reciteToday;//今天已经背诵过的单词数量
    int reviewToday;//今天已经复习过的单词数量
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
    int GetRecitedSize(){return recited.size();}
    Word* GetWord(int i){return words[i];}
    int GetUseDay(){return useDay;}
    int* GetBeginDay(){return beginDay;}
    int removeWord(int rank);
    Set();
    Set (std::string n): setName(n)	{}
    friend class recite;
    friend class consoleInterface;
};
#endif