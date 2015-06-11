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
    if(staticTmpWrongNum0+staticTmpRightNum0>=20){
        rightRate0=staticTmpRightNum0*1.0/(staticTmpWrongNum0*1.0+staticTmpRightNum0*1.0);
    }
}

void Test::RightRateChange1(){
    if(staticTmpWrongNum1+staticTmpRightNum1>=20){
        rightRate1=staticTmpRightNum1*1.0/(staticTmpWrongNum1*1.0+staticTmpRightNum1*1.0);
    }
}

void Test::RightRateChange2(){
    if(staticTmpWrongNum2+staticTmpRightNum2>=20){
        rightRate2=staticTmpRightNum2*1.0/(staticTmpWrongNum2*1.0+staticTmpRightNum2*1.0);
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

void  Test::Clear(){
    staticTmpRightNum0=0;
    staticTmpRightNum1=0;
    staticTmpRightNum2=0;
    staticTmpWrongNum0=0;
    staticTmpWrongNum1=0;
    staticTmpWrongNum2=0;
    rightRate0=0.0;
    rightRate1=0.0;
    rightRate2=0.0;
}

int Test::staticRightNum0=0;
int Test::staticRightNum1=0;
int Test::staticRightNum2=0;
int Test::staticWrongNum0=0;
int Test::staticWrongNum1=0;
int Test::staticWrongNum2=0;
int Test::staticTmpRightNum0=0;
int Test::staticTmpRightNum1=0;
int Test::staticTmpRightNum2=0;
int Test::staticTmpWrongNum0=0;
int Test::staticTmpWrongNum1=0;
int Test::staticTmpWrongNum2=0;
double Test::rightRate0=0.0;
double Test::rightRate1=0.0;
double Test::rightRate2=0.0;