#ifndef _______recite__
#define _______recite__

#include "Question.h"
#include <ctime>
#include <stdlib.h>
#include <algorithm>

class recite{
    Set* set;//背诵的set
    int reciteToday;//今日需要背得单词的数量
    int reviewToday;//今日需要复习的单词的数量
    std::vector<Word*> reciteWord;//所需背诵的单词
    std::vector<Word*> reviewWord;//所需复习的单词
public:
    recite(Set* m): set(m){
        int today;
        time_t t = time(0);
        char tmp[5];
        strftime( tmp, sizeof(tmp), "%j",localtime(&t) );
        today=atoi(tmp);
        int dayleft=m->GetUseDay()-today+m->GetBeginDay();
        if(dayleft==0){
            exit(-1);
        }
        int wordleft=m->GetSize()-m->GetRecitedSize();
        reciteToday=wordleft/dayleft;
        reviewToday=std::min(m->GetRecitedSize(), reciteToday);
        std::vector<Word*> lin;
        for(int i=0; i<m->GetSize(); i++){
            lin.push_back(m->GetWord(i));
        }
        std::random_shuffle(&lin, &lin+m->GetSize());
        int num=0;
        for(int i=0; i<lin.size(); i++){
            if(num>=reciteToday) break;
            if(lin[i]->haveRecited){
                continue;
            }else{
                reciteWord.push_back(lin[i]);
                num++;
            }
        }
    }
    
    void DoRecite(Word* m, std::ostream& osout, std::istream& input){
        osout<<"Recite Word..."<<std::endl<<std::endl;
        osout<<*m<<std::endl;
        osout<<"will you kill it? Y/N"<<std::endl;
        char s;
        input>>s;
        while(s!='N' && s!='Y'){
            osout<<"input error, please input again!"<<std::endl;
            input>>s;
        }
        if(s=='N'){
            m->kill=false;
        }else{
            m->kill=true;
        }
        m->haveRecited=true;
        int lin[4];
        time_t t = time(0);
        char tmp[5];
        strftime( tmp, sizeof(tmp), "%j",localtime(&t) );
        lin[0]=atoi(tmp);
        char ttp[12];
        strftime( ttp, sizeof(ttp), "%X",localtime(&t) );
        std::string ss;
        int i;
        for(i=0; i<12; i++){
            if(ttp[i]!=':'){
                ss+=ttp[i];
            }else{
                break;
            }
        }
        lin[1]=atoi(ss.c_str());
        ss="";
        int j;
        for(j=i+1; j<12; j++){
            if(ttp[j]!=':'){
                ss+=ttp[j];
            }else{
                break;
            }
        }
        lin[2]=atoi(ss.c_str());
        ss="";
        for(i=j+1; i<j+3; i++){
            ss+=ttp[i];
        }
        lin[3]=atoi(ss.c_str());
        m->reciteTime.push_back(lin);
    }
    
    void DoReview(Word* m, std::ostream& osout, std::istream& input){
        osout<<"Review Word..."<<std::endl;
        opera* op = new opera(m, 4, 0);
        op->ope(osout);
        std::string answer;
        getline(input, answer);
        op->first(answer, osout);
        if(op->ques->judge){
            m->right++;
            m->check.push_back(true);
        }else{
            m->wrong++;
            m->check.push_back(false);
        }
        int lin[4];
        time_t t = time(0);
        char tmp[5];
        strftime( tmp, sizeof(tmp), "%j",localtime(&t) );
        lin[0]=atoi(tmp);
        char ttp[12];
        strftime( ttp, sizeof(ttp), "%X",localtime(&t) );
        std::string ss;
        int i;
        for(i=0; i<12; i++){
            if(ttp[i]!=':'){
                ss+=ttp[i];
            }else{
                break;
            }
        }
        lin[1]=atoi(ss.c_str());
        ss="";
        int j;
        for(j=i+1; j<12; j++){
            if(ttp[j]!=':'){
                ss+=ttp[j];
            }else{
                break;
            }
        }
        lin[2]=atoi(ss.c_str());
        ss="";
        for(i=j+1; i<j+3; i++){
            ss+=ttp[i];
        }
        lin[3]=atoi(ss.c_str());
        m->reviewTime.push_back(lin);
    }
};

#endif /* defined(_______recite__) */
