//Dictionary.h
#ifndef ___DICTIONARY___
#define ___DICTIONARY___
#include "Word.h"
#include "Set.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
/*
 格式说明:
 按头文件中出现顺序依次逐行列出,数据缺失空行
 vector的结尾是 .(单独一行)
 entry的结尾是 #(单独一行)
 word的结尾是 * (单独一行)
 */
class Set;
class Word;
class Dictionary
{
private:
    std::vector<Word> words;
    static Dictionary* instance;
protected:
    friend class Interface;
    void getNext(int*, std::string);
    int kmp(std::string, std::string);
    Dictionary ();
    Dictionary (const Dictionary&);
    Dictionary& operator=(const Dictionary&);
    bool particalFind(int, int, std::vector<Word*>&, std::string&);
public:
    int FindWordExact(std::string) const;
    friend std::ostream& operator<< (std::ostream&, Dictionary&);
    static Dictionary* GetInstance ();
    bool FindWordFuzzy(std::string, std::vector<Word*>&);
    int FindWord(std::string targetWord, bool = false) const;
    Word& operator[](int rank);
    int Insert(Word&);
    bool WordExist (std::string targetWord, bool = false);
    int GetSize() const {return words.size();}
    void ReadAndAdd (std::istream& load);
    void Read (std::istream& load);
    void Sort();
};
#endif