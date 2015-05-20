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
    int useDay;//背完这个set设定的时间
    int beginDay;//开始的时间
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
    int GetRecitedSize(){
        return recited.size();
    }
    Word* GetWord(int i){
        return words[i];
    }
    int GetUseDay(){
        return useDay;
    }
    int GetBeginDay(){
        return beginDay;
    }
    Set();
    Set (std::string n): setName(n)	{
        beginDay=177;
        useDay=120;
    }
    friend class recite;
};
#endif