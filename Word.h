//:Word.h
#ifndef ___WORD___
#define ___WORD___
#include "Entry.h"
#include <string>
#include <vector>
class Remember;
class Set;
class Word
{
private:
    friend class WordFactory;
    std::string spell;
    std::vector<Entry*> entries;
    Remember* remember;
    int quan0;//三种测试方法的抽签权重
    int quan1;
    int quan2;
    bool haveRecited;//是否已经背过
    bool kill;//判断是否斩掉
    std::vector<int[4]> reciteTime;//上次背诵的日期，用这一年的第几天表示
    std::vector<int[4]> reviewTime;
    std::vector<bool> check;//统计最近十次的正确情况
    int right;//总共正确的次数
    int wrong;//错误的次数
public:
    friend std::ostream& operator<< (std::ostream&, Word&);
    std::string GetSpell()	const	{return spell;}
    Word ();
    Word (const Word&);
    int EntrySize(){
        return entries.size();
    }
    Entry* GetEntry(int i){
        return entries[i];
    }
    bool GetHaveRecited(){
        return haveRecited;
    }
    void Quanchange0();
    void Quanchange1();
    void Quanchange2();
    friend int search(Set* m, int type);
    friend int* searchEntry(Word* m, int num, int type);
    friend class recite;
};
#endif