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