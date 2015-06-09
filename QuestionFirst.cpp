#include "QuestionFirst.h"

using namespace std;

QuestionFirst::QuestionFirst(Word* m, int Level, Set* n){
    srand(time(0));
    entryFirst.clear();
    wordFirst=m;
    level=Level;
    setFirst=n;
    num=wordFirst->EntrySize();
    right=rand()%(num>level?level:num)+1;
}

void QuestionFirst::AddQuestion(){
    int* chooseEntry=searchEntry(wordFirst, right, 0);
    for(int i=0; i<10; i++) chooseEntry[i]=i;
    int tmp2 = rand()%50 +1;
    for(int i=0; i<tmp2; i++){
        std::random_shuffle(chooseEntry, chooseEntry+num);
    }
    for(int i=0; i<right; i++){
        question[i].s+=(wordFirst->GetEntry(chooseEntry[i]))->GetMeaningC();
        question[i].s+="  ";
        question[i].s+=(wordFirst->GetEntry(chooseEntry[i]))->GetWordClass();
        question[i].num=i;
        entryFirst.push_back(wordFirst->GetEntry(chooseEntry[i]));
    }
    int dos[5000];
    for(int i=0; i<5000; i++) dos[i]=i;
    int tmp3 = rand()%50 +1;
    for(int i=0; i<tmp3; i++){
        std::random_shuffle(dos, dos+setFirst->GetSize());
    }
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

void QuestionFirst::DisorganizeQuestion(){
    int tmp3 = rand()%50 +1;
    for(int i=0; i<tmp3; i++){
        std::random_shuffle(question, question+level);
    }
    int lin=0;
    for(int i=0; i<level; i++){
        if(question[i].num<right){
            answer[lin]=i+1;
            lin++;
        }
    }
}

void QuestionFirst::ShowInScreen(std::ostream& osout){
    if(wordFirst->GetEntry(0)->GetPhonogram()!=""){
        osout<<wordFirst->GetSpell()<<"  |";
        osout<<wordFirst->GetEntry(0)->GetPhonogram()<<"|"<<std::endl;
    }else{
        osout<<wordFirst->GetSpell()<<"  ";
        osout<<wordFirst->GetEntry(0)->GetPhonogram()<<std::endl;
    }
    osout<<std::endl;
    osout<<std::endl;
    char choose[10]={' ','A','B','C','D','E','F','G','H'};
    for(int i=0; i<level; i++){
        osout<<choose[i+1]<<". "<<question[i].s<<std::endl;
    }
}

void QuestionFirst::GetTheAnswer(std::string s, std::ostream& osout, bool exam){
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
        judge=true;
        Test::staticRightNum0++;
        Test::staticTmpRightNum0++;
        Test::RightRateChange0();
        osout<<"Right!!"<<std::endl;
        osout<<std::endl;
        osout<<std::endl;
        osout<<"now the right rate is:  ";
        if(exam){
            osout<<Test::staticTmpRightNum0*1.0/(Test::staticTmpWrongNum0+Test::staticTmpRightNum0 ==0 ? 1 : Test::staticTmpWrongNum0+Test::staticTmpRightNum0)*100.0<<"%"<<std::endl;
        }else{
            osout<<Test::staticRightNum0*1.0/(Test::staticWrongNum0+Test::staticRightNum0 ==0 ? 1 : Test::staticWrongNum0+Test::staticRightNum0)*100.0<<"%"<<std::endl;
        }
        osout<<"-------------------------------------------------------------"<<std::endl;
        osout<<std::endl;
        osout<<std::endl;
        for(int i=0; i<entryFirst.size(); i++){
            entryFirst[i]->test->rightNum0++;
            entryFirst[i]->test->QuanChange0();
        }
    }else{
        judge=false;
        Test::staticWrongNum0++;
        Test::staticTmpWrongNum0++;
        Test::RightRateChange0();
        osout<<"Wrong!!"<<std::endl;
        osout<<"The Answer is:"<<std::endl;
        for(int i=0; i<right; i++){
            char m='A'-1+answer[i];
            osout<<m<<' ';
        }
        osout<<std::endl;
        osout<<std::endl;
        osout<<"now the right rate is:  ";
        if(exam){
            osout<<Test::staticTmpRightNum0*1.0/(Test::staticTmpWrongNum0+Test::staticTmpRightNum0 ==0 ? 1 : Test::staticTmpWrongNum0+Test::staticTmpRightNum0)*100.0<<"%"<<std::endl;
        }else{
            osout<<Test::staticRightNum0*1.0/(Test::staticWrongNum0+Test::staticRightNum0 ==0 ? 1 : Test::staticWrongNum0+Test::staticRightNum0)*100.0<<"%"<<std::endl;
        }
        osout<<"-------------------------------------------------------------"<<std::endl;
        osout<<std::endl;
        osout<<std::endl;
        for(int i=0; i<entryFirst.size(); i++){
            if(checkFirst[i]){
                entryFirst[i]->test->rightNum0++;
            }else{
                entryFirst[i]->test->wrongNum0++;
            }
            entryFirst[i]->test->QuanChange0();
        }
    }
    wordFirst->Quanchange0();
}