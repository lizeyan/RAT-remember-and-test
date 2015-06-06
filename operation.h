#ifndef _______operation__
#define _______operation__

#include "Question.h"
#include "QuestionFirst.h"
#include "QuestionSecondChoose.h"
#include "QuestionSecondFillBlank.h"
#include <iostream>

class opera{
    Set* set;
    QuestionChoose* ques;
    int level;
    int type;
    bool Exam;
public:
    opera(Set* m, int k, int Type, bool exam=false);
    opera(Word* m, int k, int type, Set*, bool exam=false);
    ~opera();
    void ope(std::ostream& osout);
    void first(std::string ans, std::ostream& osout);
    friend class recite;
};

#endif /* defined(_______operation__) */
