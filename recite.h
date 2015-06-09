#ifndef _______recite__
#define _______recite__

#include "operation.h"
#include <ctime>
#include <stdlib.h>
#include <algorithm>

class recite{
    Set* set;//背诵的set
    bool Exit;
    bool done;//完成今日背诵任务了吗
    int reciteToday;//今日需要背得单词的数量
    int reviewToday;//今日需要复习的单词的数量
    std::vector<Word*> reciteWord;//所需背诵的单词
    std::vector<Word*> reviewWord;//所需复习的单词
    std::vector<Word*> reciteThis;//这个学习组需要背诵的临时变量
    std::vector<Word*> reviewThis;//这个学习组需要复习的临时变量
public:
    recite(Set* m);
    void DoRecite(Word* m, std::ostream& osout, std::istream& input);
    void DoReview(Word* m, std::ostream& osout, std::istream& input, int huihe);
    void ReciteControl(std::ostream& osout, std::istream& input);
    bool GetDone(){return done;}
    int ReciteNeedTime(Word* m){//返回一个单词需要连续背会几次才能够算是会了
        int lin = 0;
        time_t t = time(0);
        char tmp[5];
        strftime( tmp, sizeof(tmp), "%j",localtime(&t) );
        int today = atoi(tmp);
        lin = today - m->reviewDay;
        if(lin>10){
            return 1;
        }else if(lin>4){
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
    std::vector<int> SearchReview(std::vector<Word*> &m, int num){//选择需要复习的单词，按照权重
        std::vector<int> choose;
        std::vector<int> lin;
        lin.clear();
        choose.clear();
        for(int i=0; i<m.size(); i++){
            choose.push_back(m[i]->quanReview);
        }
        for(int i=0; i<(m.size()>num? num : m.size()); i++){
            int all=0;
            for(int k=0; k<choose.size(); k++){
                all+=choose[k];
            }
            if(all==0) all=1;
            int output=rand()%all+1;
            int number=0;
            int j;
            for(j=0; j<choose.size(); j++){
                number+=choose[j];
                if(number>=output){
                    break;
                }
            }
            lin.push_back(j);
            choose[j]=0;
        }
        return lin;
    }
    void ReviewQuanUpdate(Word* m){
        m->quanReview=10*m->wrong/(m->wrong+m->right+1) > 0? 10*m->wrong/(m->wrong+m->right+1) : 1;
        if(m->zu){
            m->quanReview-=10;
        }else{
            m->quanReview+=10;
        }
        m->quanReview=m->quanReview>0?m->quanReview:1;
    }
};

#endif /* defined(_______recite__) */
