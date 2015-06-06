#ifndef _______QuestionSecondChoose__
#define _______QuestionSecondChoose__

#include "Question.h"
#include <iostream>

class QuestionSecondChoose: public QuestionChoose{//由单词意思给出相应的单词拼写和一些属性，选择题
    Word* wordsecond;
    Set* setSecond;
    int num;//单词的释义的个数
    int level;//选项的个数
    int choose;//选择了第几个意思
    int answer;
    Question question[10];
public:
    QuestionSecondChoose(Word* m, int lev, Set* n);
    void AddQuestion();
    void DisorganizeQuestion();
    void ShowInScreen(std::ostream& osout);
    void GetTheAnswer(std::string s, std::ostream& osout, bool exam=false);
};

#endif /* defined(_______QuestionSecondChoose__) */
