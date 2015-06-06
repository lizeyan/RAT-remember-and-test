#ifndef _______QuestionSecondFillBlank__
#define _______QuestionSecondFillBlank__

#include "Question.h"
#include <iostream>

class QuestionSecondFillBlank: public QuestionChoose{//由单词意思给出相应的单词拼写和一些属性，填空题
    Word* wordFillBlank;
    Set* setFillBlank;
    int num;//单词的释义的个数
    int choose;//选了第几个意思
public:
    QuestionSecondFillBlank(Word* m, Set* n);
    void AddQuestion();
    void DisorganizeQuestion();
    void ShowInScreen(std::ostream& osout);
    void GetTheAnswer(std::string s, std::ostream& osout, bool exam=false);
};

#endif /* defined(_______QuestionSecondFillBlank__) */
