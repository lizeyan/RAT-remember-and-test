#ifndef _______QuestionFirst__
#define _______QuestionFirst__

#include "Question.h"
#include <iostream>

class QuestionFirst: public QuestionChoose{//由单词拼写测试单词的释义和一些属性
    Word* wordFirst;
    Set* setFirst;
    std::vector<Entry*> entryFirst;
    int num;//这个单词拥有的解释个数
    int right;//正确答案的数量
    int level;//测试的难度
    int answer[10];//答案的序号，从1开始
    bool checkFirst[10];//记录每个解释的正确性
    Question question[10];//用于存储选择支，肯定不超过10个
public:
    QuestionFirst(Word* m, int Level, Set* n);
    void AddQuestion();
    void DisorganizeQuestion();
    void ShowInScreen(std::ostream& osout);
    void GetTheAnswer(std::string s, std::ostream& osout, bool exam=false);
};

#endif /* defined(_______QuestionFirst__) */
