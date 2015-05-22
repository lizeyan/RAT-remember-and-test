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
    int quanReview;//背诵单词时复习的权重
    int quanSelect;//一天中在总的词库中挑选所需复习的词的权重，这里用排序，不用随机
    bool haveRecited;//是否已经背过
    bool kill;//判断是否斩掉
    std::vector<int*> reciteTime;//上次背诵的日期，用这一年的第几天表示,虽然就背过一次
    std::vector<int*> reviewTime;//上次复习的日期
    std::vector<bool> check;//统计最近十次的正确情况
    int right;//总共正确的次数
    int wrong;//错误的次数
    int reviewDay;//复习过的天数
    bool zu;//分小组背诵时权重的分配；
    int huiHe;//背诵时回合的变量
public:
    friend std::ostream& operator<< (std::ostream&, Word&);
    std::string GetSpell()	const	{return spell;}
    Word ();
    int EntrySize(){
        return entries.size();
    }
    Entry* GetEntry(int i){
        return entries[i];
    }
    bool GetHaveRecited(){
        return haveRecited;
    }
    int GetQuanSelect(){
        return quanSelect;
    }
    void Quanchange0();
    void Quanchange1();
    void Quanchange2();
    bool Familiar();
    friend int search(Set* m, int type);
    friend int* searchEntry(Word* m, int num, int type);
    friend class recite;
};
#endif