#ifndef _______recite__
#define _______recite__

#include "operation.h"
#include <ctime>
#include <stdlib.h>
#include <algorithm>

class recite{
    Set* set;//背诵的set
    bool Exit;
    bool done;//完成今日背诵任务了吗
    int reciteToday;//今日需要背得单词的数量
    int reviewToday;//今日需要复习的单词的数量
    std::vector<Word*> reciteWord;//所需背诵的单词
    std::vector<Word*> reviewWord;//所需复习的单词
    std::vector<Word*> reciteThis;//这个学习组需要背诵的临时变量
    std::vector<Word*> reviewThis;//这个学习组需要复习的临时变量
public:
    recite(Set* m);
    void DoRecite(Word* m, std::ostream& osout, std::istream& input);
    void DoReview(Word* m, std::ostream& osout, std::istream& input, int huihe);
    void ReciteControl(std::ostream& osout, std::istream& input);
    bool GetDone(){return done;}
    int ReciteNeedTime(Word* m);
    int ReciteThisTime();
    int ReviewThisTime();
    std::vector<int> SearchReview(std::vector<Word*> &m, int num);
    void ReviewQuanUpdate(Word* m);
};

#endif /* defined(_______recite__) */
