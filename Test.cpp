#include "Test.h"
#include <algorithm>
#include <cmath>

Test::Test(){
    rightNum0=0;
    rightNum1=0;
    rightNum2=0;
    wrongNum0=0;
    wrongNum1=0;
    wrongNum2=0;
    quan0=1;
    quan1=1;
    quan2=1;
}

void Test::RightRateChange0(){
    if(staticWrongNum0+staticRightNum0>=20){
        rightRate0=staticRightNum0*1.0/(staticWrongNum0*1.0);
    }
}

void Test::RightRateChange1(){
    if(staticWrongNum1+staticRightNum1>=20){
        rightRate1=staticRightNum1*1.0/(staticWrongNum1*1.0);
    }
}

void Test::RightRateChange2(){
    if(staticWrongNum2+staticRightNum2>=20){
        rightRate2=staticRightNum2*1.0/(staticWrongNum2*1.0);
    }
}

void Test::QuanChange0(){
    quan0=std::max(1, wrongNum0-(int)sqrt(wrongNum0+rightNum0));
}

void Test::QuanChange1(){
    quan1=std::max(1, wrongNum1-(int)sqrt(wrongNum1+rightNum1));
}

void Test::QuanChange2(){
    quan2=std::max(1, wrongNum2-(int)sqrt(wrongNum2+rightNum2));
}

int Test::staticRightNum0=0;
int Test::staticRightNum1=0;
int Test::staticRightNum2=0;
int Test::staticWrongNum0=0;
int Test::staticWrongNum1=0;
int Test::staticWrongNum2=0;
double Test::rightRate0=0.0;
double Test::rightRate1=0.0;
double Test::rightRate2=0.0;