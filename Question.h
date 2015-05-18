#ifndef _______Question__
#define _______Question__

#include "Test.h"
#include "User.h"
#include "Entry.h"
#include "Word.h"
#include "Dictionary.h"
#include <ctime>
#include <algorithm>

struct Question{
    std::string s;
    int num;
};

class QuestionChoose{
public:
    QuestionChoose(){}
    virtual void AddQuestion()=0;
    virtual void DisorganizeQuestion()=0;
    virtual void ShowInScreen(std::ostream& osout)=0;
    virtual void GetTheAnswer(std::string s, std::ostream& osout)=0;
};

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
    void GetTheAnswer(std::string s, std::ostream& osout);
};

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
    void GetTheAnswer(std::string s, std::ostream& osout);
};

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
    void GetTheAnswer(std::string s, std::ostream& osout);
};

class opera{
    Set* set;
    QuestionChoose* ques;
    int level;
    int type;
public:
    opera(Set* m, int k, int Type);
    ~opera();
    void ope(std::ostream& osout);
    void first(std::string ans, std::ostream& osout);
};

#endif /* defined(_______Question__) */