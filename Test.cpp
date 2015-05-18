#include "Test.h"

Test::Test(){
    rightNum=0;
    wrongNum=0;
}

int Test::GetRightNum(){
    return rightNum;
}

int Test::GetWrongNum(){
    return wrongNum;
}

void Test::RightNumPlus(){
    rightNum++;
}

void Test::WrongNumPlus(){
    wrongNum++;
}