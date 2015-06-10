#include "recite.h"

bool cmp(Word* a, Word* b){
    if(a->GetQuanSelect()[0]==b->GetQuanSelect()[0]){
        return a->GetQuanSelect()[1]>b->GetQuanSelect()[1];
    }else{
        return a->GetQuanSelect()[0]>b->GetQuanSelect()[0];
    }
}

bool judge(int n){
    bool s=false;
    if( (n%100!=0 && n%4==0) || (n%400==0) ){
        s=true;
    }else{
        s=false;
    }
    return s;
}

recite::recite(Set* m): set(m){
    int today[2];
    Exit=false;
    done=false;
    time_t t = time(0);
    char tmp[5],tmp1[8];
    strftime( tmp1, sizeof(tmp), "%Y",localtime(&t) );
    today[0]=atoi(tmp1);
    strftime( tmp, sizeof(tmp), "%j",localtime(&t) );
    today[1]=atoi(tmp);
    int plus=0;//因为年数差异产生的天数差异
    for(int i=m->GetBeginDay()[0]; i<today[0]; i++){
        plus+=365;
        if(judge(i)){
            plus++;
        }
    }
    int dayleft=m->GetUseDay()-today[1]+m->GetBeginDay()[1]+plus;//还剩下多少天可以背单词
    
    if(dayleft<=0){
        std::cout<<"No Day Left!"<<std::endl;
        exit(-1);
    }
    int wordleft=m->GetSize()-m->GetRecitedSize();//还有多少单词没有背
    reciteToday=wordleft/dayleft-set->reciteToday;//今天需要背多少单词
    reviewToday=std::min(m->GetRecitedSize(), reciteToday)-set->reviewToday;//今天需要复习多少单词
    if(reviewToday<0) reviewToday=0;
    std::vector<Word*> lin;
    for(int i=0; i<m->GetSize(); i++){
        lin.push_back(m->GetWord(i));
    }
    
    int tmp2 = rand()%50 +1;
    
    for(int i=0; i<tmp2; i++){
        std::random_shuffle(lin.begin(), lin.begin()+m->GetSize());
    }
    
    int num=0;
    for(int i=0; i<lin.size(); i++){
        if(num>=reciteToday) break;
        if(lin[i]->haveRecited){
            continue;
        }else{
            reciteWord.push_back(lin[i]);//把今天要背的单词加进来
            num++;
        }
    }
    sort(m->recited.begin(), m->recited.end(), cmp);
    for(int i=0; i<reviewToday; i++){
        reviewWord.push_back(m->recited[i]);
    }
    m->lastRecite[0]=today[0];
    m->lastRecite[1]=today[1];
    std::cout<<"You have "<<dayleft<<" days left to recite word."<<std::endl;
    std::cout<<"You should recite "<<reciteToday<<" words today."<<std::endl;
    std::cout<<"You should review "<<reviewToday<<" words today."<<std::endl;
}

void recite::DoRecite(Word* m, std::ostream& osout, std::istream& input){
    osout<<"Recite Word..."<<std::endl<<std::endl;
    osout<<*m<<std::endl;
    std::string s;
    getline(input, s);
    if(s=="Y"||s=="y"){
        m->kill=true;
    }else if(s=="q" || s == "quit"){
        Exit=true;
        return;
    }
    m->haveRecited=true;
    int lin[5];
    time_t t = time(0);
    char tmp[5];
    strftime( tmp, sizeof(tmp), "%Y",localtime(&t) );
    lin[0]=atoi(tmp);
    char tmp1[5];
    strftime( tmp1, sizeof(tmp1), "%j",localtime(&t) );
    lin[1]=atoi(tmp1);
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
    lin[2]=atoi(ss.c_str());
    ss="";
    int j;
    for(j=i+1; j<12; j++){
        if(ttp[j]!=':'){
            ss+=ttp[j];
        }else{
            break;
        }
    }
    lin[3]=atoi(ss.c_str());
    ss="";
    for(i=j+1; i<j+3; i++){
        ss+=ttp[i];
    }
    lin[4]=atoi(ss.c_str());
    std::vector<int> linshi;
    for(int k=0; k<5; k++) linshi.push_back(lin[k]);
    m->reciteTime.push_back(linshi);
    set->reciteToday++;
}
void recite::DoReview(Word* m, std::ostream& osout, std::istream& input, int huihe){
    m->huiHe=huihe;
    ReviewQuanUpdate(m);
    m->zu=true;
    osout<<"Test Word..."<<std::endl;
    opera* op = new opera(m, 4, 0, set);
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
    std::string s;
    getline(input, s);
    if(s=="q"){
        Exit=true;
    }
    if(op->ques->judge){
        m->right++;//正确次数+1
        m->check.push_back(true);//这次测试正确
    }else{
        m->wrong++;
        m->check.push_back(false);
    }
    int lin[5];
    time_t t = time(0);
    char tmp[5];
    strftime( tmp, sizeof(tmp), "%Y",localtime(&t) );
    lin[0]=atoi(tmp);
    char tmp1[5];
    strftime( tmp1, sizeof(tmp1), "%j",localtime(&t) );
    lin[1]=atoi(tmp1);
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
    lin[2]=atoi(ss.c_str());
    ss="";
    int j;
    for(j=i+1; j<12; j++){
        if(ttp[j]!=':'){
            ss+=ttp[j];
        }else{
            break;
        }
    }
    lin[3]=atoi(ss.c_str());
    ss="";
    for(i=j+1; i<j+3; i++){
        ss+=ttp[i];
    }
    lin[4]=atoi(ss.c_str());
    std::vector<int> linshi;
    for(int k=0; k<5; k++) linshi.push_back(lin[k]);
    m->reviewTime.push_back(linshi);
    m->reviewDay=lin[1];
}
void recite::ReciteControl(std::ostream& osout, std::istream& input){
    int huihe=0;
    while(reviewWord.size()!=0||reciteWord.size()!=0){
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
            if(Exit) break;
            if(reciteThis[i]->kill){//如果已经被斩了，就不用在复习了
                reciteThis.erase(reciteThis.begin()+i);//从这次需要背的列表中删去已经被斩的
                i--;
                continue;
            }
            reviewThis.push_back(reciteThis[i]);
        }
        if(Exit) break;
        std::vector<int> choose=SearchReview(reviewWord, ReviewThisTime()-reciteThis.size());//按照权重选择需要背诵的单词
        for(int i=0; i<choose.size(); i++){
            reviewThis.push_back(reviewWord[choose[i]]);
        }
        for(int i=0; i<reciteThis.size(); i++){//刚学过的单词在这这一轮中一定要进行复习，所以在录入之后在push到reviewWord中
            reviewWord.push_back(reciteThis[i]);
        }
        int tmp2 = rand()%50 +1;
        for(int i=0; i<tmp2; i++){
            std::random_shuffle(reviewThis.begin(), reviewThis.end());
        }
        for(int i=0; i<reviewThis.size(); i++){
            DoReview(reviewThis[i], osout, input, huihe);
            if(Exit) return;
        }
        for(int i=0; i<reviewWord.size(); i++){
            if((huihe-reviewWord[i]->huiHe)*15>reviewWord.size()){
                reviewWord[i]->zu=false;
            }
            int lin=true;
            int stupid=(reviewWord[i]->check.size()>=ReciteNeedTime(reviewWord[i]))?
            (reviewWord[i]->check.size()-ReciteNeedTime(reviewWord[i])): 0;
            for(int j=(int)reviewWord[i]->check.size()-1; j>=stupid; j--){
                if(!reviewWord[i]->check[j]){
                    lin=false;
                    break;
                }
            }
            if(reviewWord[i]->check.size()<ReciteNeedTime(reviewWord[i])){
                lin=false;
            }
            if(lin){
                time_t t = time(0);
                char tmp[5];
                strftime( tmp, sizeof(tmp), "%j",localtime(&t) );
                reviewWord[i]->reviewDay=atoi(tmp);
                reviewWord.erase(reviewWord.begin()+i);
                set->reviewToday++;
                i--;
            }
        }
        huihe++;
    }
    if(reviewWord.size()==0 && reciteWord.size()==0){
        done = true;
    }
}
int recite::ReciteNeedTime(Word* m){//返回一个单词需要连续背会几次才能够算是会了
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
int recite::ReciteThisTime(){//返回以现有还剩的所需背诵的单词数量为参量，得到一组需要背几个单词
    return reciteWord.size()/10+1;
}
int recite::ReviewThisTime(){
    if(ReciteThisTime()>4){
        return 20-ReciteThisTime();
    }else{
        return 16-ReciteThisTime();
    }
}
std::vector<int> recite::SearchReview(std::vector<Word*> &m, int num){//选择需要复习的单词，按照权重
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
void recite::recite::ReviewQuanUpdate(Word* m){
    m->quanReview=10*m->wrong/(m->wrong+m->right+1) > 0? 10*m->wrong/(m->wrong+m->right+1) : 1;
    if(m->zu){
        m->quanReview-=10;
    }else{
        m->quanReview+=10;
    }
    m->quanReview=m->quanReview>0?m->quanReview:1;
}