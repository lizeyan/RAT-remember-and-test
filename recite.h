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
    std::vector<Word*> reciteThis;//这个学习组需要背诵的临时变量
    std::vector<Word*> reviewThis;//这个学习组需要复习的临时变量
public:
    recite(Set* m);
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
    void DoReview(Word* m, std::ostream& osout, std::istream& input, int huihe){
        m->huiHe=huihe;
        ReviewQuanUpdate(m);
        m->zu=true;
        osout<<"Test Word..."<<std::endl;
        opera* op = new opera(m, 4, 0);
        op->ope(osout);
        std::string answer;
        getline(input, answer);
        while(answer==""){
            getline(input, answer);
        }
        op->first(answer, osout);
        osout<<std::endl<<std::endl;
        osout<<"Review Word..."<<std::endl<<std::endl;
        osout<<*m<<std::endl<<std::endl;
        osout<<"press Enter to go on reviewing"<<std::endl;
        std::string s;
        getline(input, s);
        if(op->ques->judge){
            m->right++;//正确次数+1
            m->check.push_back(true);//这次测试正确
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
    void ReciteControl(std::ostream& osout, std::istream& input){
        int huihe=0;
        while(reviewWord.size()!=0){
            int upper=ReciteThisTime();
            reciteThis.clear();
            reviewThis.clear();
            for(int i=0; i<upper; i++){
                if(reciteWord.size()==0) break;
                reciteThis.push_back(reciteWord[0]);
                reciteWord.erase(reciteWord.begin());//从总的需要背诵的单词表中删去
            }
            for(int i=0; i<reciteThis.size(); i++){
                DoRecite(reciteThis[i], osout, input);
                if(reciteThis[i]->kill){//如果已经被斩了，就不用在复习了
                    reciteThis.erase(reciteThis.begin()+i);//从这次需要背的列表中删去已经被斩的
                    i--;
                    continue;
                }
                reviewThis.push_back(reciteThis[i]);
            }
            int* choose=SearchReview(reviewWord, ReviewThisTime()-reciteThis.size());//按照权重选择需要背诵的单词
            for(int i=0; i<ReviewThisTime()-reciteThis.size(); i++){
                reviewThis.push_back(reviewWord[choose[i]]);
            }
            for(int i=0; i<reciteThis.size(); i++){//刚学过的单词在这这一轮中一定要进行复习，所以在录入之后在push到reviewWord中
                reviewWord.push_back(reciteThis[i]);
            }
            std::random_shuffle(reviewThis.begin(), reviewThis.end());
            for(int i=0; i<reviewThis.size(); i++){
                DoReview(reviewThis[i], osout, input, huihe);
            }
            for(int i=0; i<reviewWord.size(); i++){
                int lin=true;
                for(int j=reviewWord[i]->check.size()-1; j>=reviewWord[i]->check.size()-ReciteNeedTime(reviewWord[i])>=0?
                    reviewWord[i]->check.size()-ReciteNeedTime(reviewWord[i]): 0; j--){
                    if(!reviewWord[i]->check[i]){
                        lin=false;
                        break;
                    }
                }
                if(lin){
                    time_t t = time(0);
                    char tmp[5];
                    strftime( tmp, sizeof(tmp), "%j",localtime(&t) );
                    reviewWord[i]->reviewDay=atoi(tmp);
                    reviewWord.erase(reviewWord.begin()+i);
                    i--;
                }
                if((huihe-reviewWord[i]->huiHe)*15>reviewWord.size()){
                    reviewWord[i]->zu=false;
                }
            }
            huihe++;
        }
    }
    int ReciteNeedTime(Word* m){//返回一个单词需要连续背会几次才能够算是会了
        if(m->reviewDay>10){
            return 1;
        }else if(m->reviewDay>4){
            return 2;
        }else{
            return 3;
        }
    }
    int ReciteThisTime(){//返回以现有还剩的所需背诵的单词数量为参量，得到一组需要背几个单词
        return reciteWord.size()/10+1;
    }
    int ReviewThisTime(){
        if(ReciteThisTime()>4){
            return 20-ReciteThisTime();
        }else{
            return 16-ReciteThisTime();
        }
    }
    int* SearchReview(std::vector<Word*> m, int num){//选择需要复习的单词，按照权重
        std::vector<int> choose;
        int* lin =new int[num+1];
        for(int i=0; i<m.size(); i++){
            choose.push_back(m[i]->quanReview);
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
    void ReviewQuanUpdate(Word* m){
        m->quanReview=10*m->wrong/(m->wrong+m->right);
        if(m->zu){
            m->quanReview-=10;
        }else{
            m->quanReview+=10;
        }
    }
};

#endif /* defined(_______recite__) */
