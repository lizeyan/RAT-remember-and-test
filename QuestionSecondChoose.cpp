#include "QuestionSecondChoose.h"

using namespace std;

QuestionSecondChoose::QuestionSecondChoose(Word* m, int lev, Set* n): wordsecond(m), setSecond(n), level(lev){
    num=wordsecond->EntrySize();
    int* lin=searchEntry(m, 1, 1);
    choose=lin[0];
    answer=0;
}

void QuestionSecondChoose::AddQuestion(){
    question[0].s=wordsecond->GetSpell();
    if(wordsecond->GetEntry(0)->GetPhonogram().length()!=0){
        question[0].s+="  |";
        question[0].s+=wordsecond->GetEntry(0)->GetPhonogram();
        question[0].s+="|";
    }else{
        question[0].s+="  ";
        question[0].s+=wordsecond->GetEntry(0)->GetPhonogram();
    }
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
        if(lin->GetEntry(0)->GetPhonogram().length()!=0){
            question[k].s+="  |";
            question[k].s+=lin->GetEntry(0)->GetPhonogram();
            question[k].s+="|";
        }else{
            question[k].s+="  ";
            question[k].s+=lin->GetEntry(0)->GetPhonogram();
        }
        question[k].num=k;
    }
}

void QuestionSecondChoose::DisorganizeQuestion(){
    std::random_shuffle(question, question+level);
    for(int i=0; i<level; i++){
        if(question[i].num==0){
            answer=i;
        }
    }
}

void QuestionSecondChoose::ShowInScreen(std::ostream& osout){
    osout<<wordsecond->GetEntry(choose)->GetMeaningC()<<std::endl;
    osout<<std::endl;
    osout<<std::endl;
    char choose[10]={' ','A','B','C','D','E','F','G','H'};
    for(int i=0; i<level; i++){
        osout<<choose[i+1]<<". "<<question[i].s<<std::endl;
    }
}

void QuestionSecondChoose::GetTheAnswer(std::string s, std::ostream& osout, bool exam){
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
        wordsecond->GetEntry(choose)->test->wrongNum1++;
    }else{
        if(ans[0]!=Answer){
            check=false;
            wordsecond->GetEntry(choose)->test->wrongNum1++;
        }else{
            wordsecond->GetEntry(choose)->test->rightNum1++;
        }
    }
    wordsecond->GetEntry(choose)->test->QuanChange1();
    wordsecond->Quanchange1();
    if(check){
        Test::staticRightNum1++;
        Test::staticTmpRightNum1++;
        Test::RightRateChange1();
        osout<<"Right!!!"<<std::endl;
        osout<<std::endl;
        osout<<std::endl;
        osout<<"now the right rate is:  ";
        if(exam){
            osout<<Test::staticTmpRightNum1*1.0/(Test::staticTmpWrongNum1+Test::staticTmpRightNum1 ==0 ? 1 : Test::staticTmpWrongNum1+Test::staticTmpRightNum1)*100.0<<"%"<<std::endl;
        }else{
            osout<<Test::staticRightNum1*1.0/(Test::staticWrongNum1+Test::staticRightNum1 ==0 ? 1 : Test::staticWrongNum1+Test::staticRightNum1)*100.0<<"%"<<std::endl;
        }
        osout<<"-------------------------------------------------------------"<<std::endl;
        osout<<std::endl;
        osout<<std::endl;
    }else{
        Test::staticWrongNum1++;
        Test::staticTmpWrongNum1++;
        Test::RightRateChange1();
        osout<<"Wrong!!!"<<std::endl;
        osout<<"The Answer is:"<<std::endl;
        osout<<Answer<<std::endl;
        osout<<std::endl;
        osout<<std::endl;
        osout<<"now the right rate is:  ";
        if(exam){
            osout<<Test::staticTmpRightNum1*1.0/(Test::staticTmpWrongNum1+Test::staticTmpRightNum1 ==0 ? 1 : Test::staticTmpWrongNum1+Test::staticTmpRightNum1)*100.0<<"%"<<std::endl;
        }else{
            osout<<Test::staticRightNum1*1.0/(Test::staticWrongNum1+Test::staticRightNum1 ==0 ? 1 : Test::staticWrongNum1+Test::staticRightNum1)*100.0<<"%"<<std::endl;
        }
        osout<<"-------------------------------------------------------------"<<std::endl;
        osout<<std::endl;
        osout<<std::endl;
    }
}