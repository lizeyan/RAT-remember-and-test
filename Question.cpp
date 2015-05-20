#include "Question.h"

int search(Set* m, int type){
    int* lin = new int[m->GetSize()];
    int num=0;
    for(int i=0; i<m->GetSize(); i++){
        if(type==0){
            lin[i]=m->GetWord(i)->quan0;
        }else if(type==1){
            lin[i]=m->GetWord(i)->quan1;
        }else if(type==2){
            lin[i]=m->GetWord(i)->quan2;
        }
        num+=lin[i];
    }
    int out=rand()%num+1;
    int number=0;
    int i;
    for(i=0; i<m->GetSize(); i++){
        number+=lin[i];
        if(number>=out){
            break;
        }
    }
    return i;
}

int* searchEntry(Word* m, int num, int type){
    std::vector<int> choose;
    int* lin =new int[10];
    for(int i=0; i<m->EntrySize(); i++){
        if(type==0){
            choose.push_back(m->quan0);
        }else if(type==1){
            choose.push_back(m->quan1);
        }
    }
    for(int i=0; i<num; i++){
        int all=0;
        for(int k=0; k<choose.size(); k++){
            all+=choose[k];
        }
        int out=rand()%all+1;
        int number=0;
        int j;
        for(j=0; j<choose.size(); j++){
            number+=choose[j];
            if(number>=out){
                break;
            }
        }
        lin[i]=j;
        choose[j]=0;
    }
    return lin;
}


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

void QuestionFirst::DisorganizeQuestion(){
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

opera::opera(Word* m, int k, int Type, bool exam): level(k), type(Type){
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