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
    bool judge;
    QuestionChoose(){}
    virtual void AddQuestion()=0;
    virtual void DisorganizeQuestion()=0;
    virtual void ShowInScreen(std::ostream& osout)=0;
    virtual void GetTheAnswer(std::string s, std::ostream& osout, bool exam=false)=0;
};

#endif /* defined(_______Question__) */