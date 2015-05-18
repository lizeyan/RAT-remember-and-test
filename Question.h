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
    QuestionFirst(Word* m, int Level, Set* n){
        srand(time(0));
        entryFirst.clear();
        wordFirst=m;
        level=Level;
        setFirst=n;
        num=wordFirst->EntrySize();
        right=rand()%(num>level?level:num)+1;
    }
    void AddQuestion(){
        int chooseEntry[10];
        for(int i=0; i<10; i++) chooseEntry[i]=i;
        std::random_shuffle(chooseEntry, chooseEntry+num);
        for(int i=0; i<right; i++){
            question[i].s+=(wordFirst->GetEntry(chooseEntry[i]))->GetMeaningC();
            question[i].s+="  ";
            question[i].s+=(wordFirst->GetEntry(chooseEntry[i]))->GetWordClass();
            question[i].num=i;
            entryFirst.push_back(wordFirst->GetEntry(chooseEntry[i]));
        }
        int dos[5000];
        for(int i=0; i<5000; i++) dos[i]=i;
        std::random_shuffle(dos, dos+setFirst->GetSize());
        bool plus=false;
        int lef=right, rig=level;
        for(int i=right; i<level; i++){
            if(wordFirst->GetSpell()==setFirst->GetWord(dos[i])->GetSpell()){
                lef+=level;
                rig+=level;
                plus=true;
                break;
            }
        }
        for(int i=lef; i<rig; i++){
            Word* lin=setFirst->GetWord(dos[i]);
            int k;
            if(plus) k=i-level;
            else k=i;
            question[k].s+=(lin->GetEntry(0))->GetMeaningC();
            question[k].s+="  ";
            question[k].s+=(lin->GetEntry(0))->GetWordClass();
            question[k].num=k;
            //delete lin;
        }
    }
    void DisorganizeQuestion(){
        srand(time(0));
        std::random_shuffle(question, question+level);
        int lin=0;
        for(int i=0; i<level; i++){
            if(question[i].num<right){
                answer[lin]=i+1;
                lin++;
            }
        }
    }
    void ShowInScreen(std::ostream& osout){
        osout<<wordFirst->GetSpell()<<std::endl;
        osout<<std::endl;
        osout<<std::endl;
        char choose[10]={' ','A','B','C','D','E','F','G','H'};
        for(int i=0; i<level; i++){
            osout<<choose[i+1]<<". "<<question[i].s<<std::endl;
        }
    }
    void GetTheAnswer(std::string s, std::ostream& osout){
        std::string ans="";
        for(int i=0; i<s.length(); i++){
            if(s[i]==' ') continue;
            if(s[i]>='a'&&s[i]<='z'){
                int m='a'-'A';
                s[i]-=m;
            }
            if(s[i]>='0'&&s[i]<='9'){
                int m='A'-'1';
                s[i]+=m;
            }
            ans+=s[i];
        }
        bool check=true;
        char Answer[10];
        for(int i=0; i<right; i++){
            Answer[i]=answer[i]+'A'-1;
        }
        sort(ans.begin(), ans.end());
        if(ans.length()!=right){
            check=false;
            for(int i=0; i<right; i++){
                bool lin=false;
                for(int k=0; k<ans.length(); k++){
                    if(Answer[i]==ans[k]) lin=true;
                }
                checkFirst[i]=lin;
            }
        }else{
            for(int i=0; i<right; i++){
                if(Answer[i]!=ans[i]) check=false;
                for(int i=0; i<right; i++){
                    bool lin=false;
                    for(int k=0; k<ans.length(); k++){
                        if(Answer[i]==ans[k]) lin=true;
                    }
                    checkFirst[i]=lin;
                }
            }
        }
        if(check){
            osout<<"Right!!"<<std::endl;
            osout<<std::endl;
            osout<<std::endl;
            osout<<"-------------------------------------------------------------"<<std::endl;
            osout<<std::endl;
            osout<<std::endl;
            for(int i=0; i<entryFirst.size(); i++){
                entryFirst[i]->test->RightNumPlus();
            }
        }else{
            osout<<"Wrong!!"<<std::endl;
            osout<<"The Answer is:"<<std::endl;
            for(int i=0; i<right; i++){
                char m='A'-1+answer[i];
                osout<<m<<' ';
            }
            osout<<std::endl;
            osout<<std::endl;
            osout<<"-------------------------------------------------------------"<<std::endl;
            osout<<std::endl;
            osout<<std::endl;
            for(int i=0; i<entryFirst.size(); i++){
                if(checkFirst[i]){
                    entryFirst[i]->test->RightNumPlus();
                }else{
                    entryFirst[i]->test->WrongNumPlus();
                }
            }
        }
    }
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
    QuestionSecondChoose(Word* m, int lev, Set* n): wordsecond(m), setSecond(n), level(lev){
        num=wordsecond->EntrySize();
        choose=rand()%num;
        answer=0;
    }
    void AddQuestion(){
        question[0].s=wordsecond->GetSpell();
        question[0].num=0;
        int dos[5000];
        for(int i=0; i<5000; i++) dos[i]=i;
        std::random_shuffle(dos, dos+setSecond->GetSize());
        int lef=1, rig=level;
        bool plus=false;
        for(int i=1; i<level; i++){
            if(wordsecond->GetSpell()==setSecond->GetWord(dos[i])->GetSpell()){
                lef+=level;
                rig+=level;
                plus=true;
                break;
            }
        }
        for(int i=lef; i<rig; i++){
            Word* lin=setSecond->GetWord(dos[i]);
            int k;
            if(plus) k=i-level;
            else k=i;
            question[k].s=lin->GetSpell();
            question[k].num=k;
        }
    }
    void DisorganizeQuestion(){
        std::random_shuffle(question, question+level);
        for(int i=0; i<level; i++){
            if(question[i].num==0){
                answer=i;
            }
        }
    }
    void ShowInScreen(std::ostream& osout){
        osout<<wordsecond->GetEntry(choose)->GetMeaningC()<<std::endl;
        osout<<std::endl;
        osout<<std::endl;
        char choose[10]={' ','A','B','C','D','E','F','G','H'};
        for(int i=0; i<level; i++){
            osout<<choose[i+1]<<". "<<question[i].s<<std::endl;
        }
    }
    void GetTheAnswer(std::string s, std::ostream& osout){
        std::string ans="";
        for(int i=0; i<s.length(); i++){
            if(s[i]==' ') continue;
            if(s[i]>='a'&&s[i]<='z'){
                int m='a'-'A';
                s[i]-=m;
            }
            if(s[i]>='0'&&s[i]<='9'){
                int m='A'-'1';
                s[i]+=m;
            }
            ans+=s[i];
        }
        char Answer=answer+'A';
        bool check=true;
        if(ans.length()!=1){
            check=false;
        }else{
            if(ans[0]!=Answer){
                check=false;
                wordsecond->GetEntry(choose)->test->WrongNumPlus();
            }else{
                wordsecond->GetEntry(choose)->test->RightNumPlus();
            }
        }
        if(check){
            osout<<"Right!!!"<<std::endl;
            osout<<std::endl;
            osout<<std::endl;
            osout<<"-------------------------------------------------------------"<<std::endl;
            osout<<std::endl;
            osout<<std::endl;
        }else{
            osout<<"Wrong!!!"<<std::endl;
            osout<<"The Answer is:"<<std::endl;
            osout<<Answer<<std::endl;
            osout<<std::endl;
            osout<<std::endl;
            osout<<"-------------------------------------------------------------"<<std::endl;
            osout<<std::endl;
            osout<<std::endl;
        }
    }
};

class QuestionSecondFillBlank: public QuestionChoose{//由单词意思给出相应的单词拼写和一些属性，填空题
    Word* wordFillBlank;
    Set* setFillBlank;
    int num;//单词的释义的个数
    int choose;//选了第几个意思
public:
    QuestionSecondFillBlank(Word* m, Set* n): wordFillBlank(m), setFillBlank(n){
        num=wordFillBlank->EntrySize();
        choose=rand()%num;
    }
    void AddQuestion(){}
    void DisorganizeQuestion(){}
    void ShowInScreen(std::ostream& osout){
        osout<<wordFillBlank->GetEntry(choose)->GetMeaningC()<<std::endl;
        osout<<std::endl;
        osout<<std::endl;
    }
    void GetTheAnswer(std::string s, std::ostream& osout){
        std::string ans_word;
        std::string ans_wordclass;
        int begin=0;
        for(int i=0; ; i++){
            begin=i;
            if(s[i]==' ') break;
            ans_word+=s[i];
        }
        for(int i=begin; i<s.length(); i++){
            if(s[i]==' ') continue;
            ans_wordclass+=s[i];
        }
        bool word=true; bool wordclass=true;
        if(ans_word!=wordFillBlank->GetSpell()) word=false;
        if(ans_wordclass!=wordFillBlank->GetEntry(choose)->GetWordClass()) wordclass=false;
        osout<<std::endl;
        if(word && wordclass){
            osout<<"Both are right!!!"<<std::endl;
            osout<<std::endl;
            osout<<std::endl;
            osout<<"-------------------------------------------------------------"<<std::endl;
            osout<<std::endl;
            osout<<std::endl;
        }else if(word && !wordclass){
            osout<<"Word spell is right;  Wordclass is wrong!!"<<std::endl;
            osout<<std::endl;
            osout<<"the answer is: "<<std::endl;
            osout<<wordFillBlank->GetSpell()<<"    "<<wordFillBlank->GetEntry(choose)->GetWordClass()<<std::endl;
            osout<<std::endl;
            osout<<std::endl;
            osout<<"-------------------------------------------------------------"<<std::endl;
            osout<<std::endl;
            osout<<std::endl;
        }else if(!word && wordclass){
            osout<<"Word spell is wrong;  Wordclass is right!!"<<std::endl;
            osout<<std::endl;
            osout<<"the answer is: "<<std::endl;
            osout<<wordFillBlank->GetSpell()<<"    "<<wordFillBlank->GetEntry(choose)->GetWordClass()<<std::endl;
            osout<<std::endl;
            osout<<std::endl;
            osout<<"-------------------------------------------------------------"<<std::endl;
            osout<<std::endl;
            osout<<std::endl;
        }else{
            osout<<"Both is wrong!!!"<<std::endl;
            osout<<std::endl;
            osout<<"the answer is: "<<std::endl;
            osout<<wordFillBlank->GetSpell()<<"    "<<wordFillBlank->GetEntry(choose)->GetWordClass()<<std::endl;
            osout<<std::endl;
            osout<<std::endl;
            osout<<"-------------------------------------------------------------"<<std::endl;
            osout<<std::endl;
            osout<<std::endl;
        }
        if(word){
            wordFillBlank->GetEntry(choose)->test->RightNumPlus();
        }else{
            wordFillBlank->GetEntry(choose)->test->WrongNumPlus();
        }
        if(wordclass){
            wordFillBlank->GetEntry(choose)->test->RightNumPlus();
        }else{
            wordFillBlank->GetEntry(choose)->test->WrongNumPlus();
        }
    }
};

class opera{
    Set* set;
    QuestionChoose* ques;
    int level;
    int type;
public:
    opera(Set* m, int k, int Type): set(m), level(k), type(Type){
        if(type==0){
            ques = new QuestionFirst(set->GetWord(rand()%(set->GetSize())), k, set);
        }else if(type==1){
            ques = new QuestionSecondChoose(set->GetWord(rand()%(set->GetSize())), k, set);
        }else if(type==2){
            ques = new QuestionSecondFillBlank(set->GetWord(rand()%(set->GetSize())), set);
        }
    }
    ~opera(){
        delete set;
        delete ques;
    }
    void ope(std::ostream& osout){
        srand(time(0));
        ques->AddQuestion();
        ques->DisorganizeQuestion();
        ques->ShowInScreen(osout);
    }
    void first(std::string ans, std::ostream& osout){
        ques->GetTheAnswer(ans, osout);
    }
};

#endif /* defined(_______Question__) */



















