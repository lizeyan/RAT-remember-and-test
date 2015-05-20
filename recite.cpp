#include "recite.h"

bool cmp(Word* a, Word* b){
    return a->GetQuanSelect()>b->GetQuanSelect();
}

recite::recite(Set* m): set(m){
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
    sort(m->recited.begin(), m->recited.end(), cmp);
    for(int i=0; i<reviewToday; i++){
        reviewWord.push_back(m->recited[i]);
    }
}