#include "QuestionSecondFillBlank.h"

using namespace std;

QuestionSecondFillBlank::QuestionSecondFillBlank(Word* m, Set* n): wordFillBlank(m), setFillBlank(n){
    num=wordFillBlank->EntrySize();
    choose=rand()%num;
}

void QuestionSecondFillBlank::AddQuestion(){}

void QuestionSecondFillBlank::DisorganizeQuestion(){}

void QuestionSecondFillBlank::ShowInScreen(std::ostream& osout){
    osout<<wordFillBlank->GetEntry(choose)->GetMeaningC()<<std::endl;
    osout<<std::endl;
    osout<<std::endl;
}

void QuestionSecondFillBlank::GetTheAnswer(std::string s, std::ostream& osout, bool exam){
    std::string ans_word;
    std::string ans_wordclass;
    int begin=0;
    for(int i=0;i<s.length(); i++){
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
        wordFillBlank->GetEntry(choose)->test->rightNum2++;
        Test::staticRightNum2++;
        Test::staticTmpRightNum2++;
        Test::RightRateChange2();
        wordFillBlank->GetEntry(choose)->test->QuanChange2();
        wordFillBlank->Quanchange2();
        osout<<"Both are right!!!"<<std::endl;
        osout<<std::endl;
        osout<<std::endl;
        osout<<"now the right rate is:  ";
        if(exam){
            osout<<Test::staticTmpRightNum2*1.0/(Test::staticTmpWrongNum2+Test::staticTmpRightNum2 ==0 ? 1 : Test::staticTmpWrongNum2+Test::staticTmpRightNum2)*100.0<<"%"<<std::endl;
        }else{
            osout<<Test::staticRightNum2*1.0/(Test::staticWrongNum2+Test::staticRightNum2 ==0 ? 1 : Test::staticWrongNum2+Test::staticRightNum2)*100.0<<"%"<<std::endl;
        }
        osout<<"-------------------------------------------------------------"<<std::endl;
        osout<<std::endl;
        osout<<std::endl;
    }else if(word && !wordclass){
        wordFillBlank->GetEntry(choose)->test->rightNum2++;
        Test::staticRightNum2++;
        Test::staticTmpRightNum2++;
        Test::RightRateChange2();
        wordFillBlank->GetEntry(choose)->test->QuanChange2();
        wordFillBlank->Quanchange2();
        osout<<"Word spell is right;  Wordclass is wrong!!"<<std::endl;
        osout<<std::endl;
        osout<<"the answer is: "<<std::endl;
        osout<<wordFillBlank->GetSpell()<<"    "<<wordFillBlank->GetEntry(choose)->GetWordClass()<<std::endl;
        osout<<std::endl;
        osout<<std::endl;
        osout<<"now the right rate is:  ";
        if(exam){
            osout<<Test::staticTmpRightNum2*1.0/(Test::staticTmpWrongNum2+Test::staticTmpRightNum2 ==0 ? 1 : Test::staticTmpWrongNum2+Test::staticTmpRightNum2)*100.0<<"%"<<std::endl;
        }else{
            osout<<Test::staticRightNum2*1.0/(Test::staticWrongNum2+Test::staticRightNum2 ==0 ? 1 : Test::staticWrongNum2+Test::staticRightNum2)*100.0<<"%"<<std::endl;
        }
        osout<<"-------------------------------------------------------------"<<std::endl;
        osout<<std::endl;
        osout<<std::endl;
    }else if(!word && wordclass){
        wordFillBlank->GetEntry(choose)->test->wrongNum2++;
        Test::staticWrongNum2++;
        Test::staticTmpWrongNum2++;
        Test::RightRateChange2();
        wordFillBlank->GetEntry(choose)->test->QuanChange2();
        wordFillBlank->Quanchange2();
        osout<<"Word spell is wrong;  Wordclass is right!!"<<std::endl;
        osout<<std::endl;
        osout<<"the answer is: "<<std::endl;
        osout<<wordFillBlank->GetSpell()<<"    "<<wordFillBlank->GetEntry(choose)->GetWordClass()<<std::endl;
        osout<<std::endl;
        osout<<std::endl;
        osout<<"now the right rate is:  ";
        if(exam){
            osout<<Test::staticTmpRightNum2*1.0/(Test::staticTmpWrongNum2+Test::staticTmpRightNum2 ==0 ? 1 : Test::staticTmpWrongNum2+Test::staticTmpRightNum2)*100.0<<"%"<<std::endl;
        }else{
            osout<<Test::staticRightNum2*1.0/(Test::staticWrongNum2+Test::staticRightNum2 ==0 ? 1 : Test::staticWrongNum2+Test::staticRightNum2)*100.0<<"%"<<std::endl;
        }
        osout<<"-------------------------------------------------------------"<<std::endl;
        osout<<std::endl;
        osout<<std::endl;
    }else{
        wordFillBlank->GetEntry(choose)->test->wrongNum2++;
        Test::staticWrongNum2++;
        Test::staticTmpWrongNum2++;
        Test::RightRateChange2();
        wordFillBlank->GetEntry(choose)->test->QuanChange2();
        wordFillBlank->Quanchange2();
        osout<<"Both is wrong!!!"<<std::endl;
        osout<<std::endl;
        osout<<"the answer is: "<<std::endl;
        osout<<wordFillBlank->GetSpell()<<"    "<<wordFillBlank->GetEntry(choose)->GetWordClass()<<std::endl;
        osout<<std::endl;
        osout<<std::endl;
        osout<<"now the right rate is:  ";
        if(exam){
            osout<<Test::staticTmpRightNum2*1.0/(Test::staticTmpWrongNum2+Test::staticTmpRightNum2 ==0 ? 1 : Test::staticTmpWrongNum2+Test::staticTmpRightNum2)*100.0<<"%"<<std::endl;
        }else{
            osout<<Test::staticRightNum2*1.0/(Test::staticWrongNum2+Test::staticRightNum2 ==0 ? 1 : Test::staticWrongNum2+Test::staticRightNum2)*100.0<<"%"<<std::endl;
        }
        osout<<"-------------------------------------------------------------"<<std::endl;
        osout<<std::endl;
        osout<<std::endl;
    }
}