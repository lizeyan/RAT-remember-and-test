#include "operation.h"

using namespace std;

int search(Set* m, int type);

opera::opera(Set* m, int k, int Type, bool exam): set(m), level(k), type(Type){
    Exam=exam;
    if(type==0){
        ques = new QuestionFirst(set->GetWord(search(set, 0)), k, set);
    }else if(type==1){
        ques = new QuestionSecondChoose(set->GetWord(search(set, 1)), k, set);
    }else if(type==2){
        ques = new QuestionSecondFillBlank(set->GetWord(search(set, 2)), set);
    }
}

opera::opera(Word* m, int k, int Type, Set* s, bool exam): level(k), type(Type){
    set=s;
    Exam=exam;
    if(type==0){
        ques = new QuestionFirst(m, k, set);
    }else if(type==1){
        ques = new QuestionSecondChoose(m, k, set);
    }else if(type==2){
        ques = new QuestionSecondFillBlank(m, set);
    }
}

opera::~opera(){
    delete set;
    delete ques;
}

void opera::ope(std::ostream& osout){
    srand(time(0));
    ques->AddQuestion();
    ques->DisorganizeQuestion();
    ques->ShowInScreen(osout);
}

void opera::first(std::string ans, std::ostream& osout){
    ques->GetTheAnswer(ans, osout, Exam);
}