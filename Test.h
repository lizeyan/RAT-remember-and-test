#ifndef _______Test__
#define _______Test__

#include <iostream>
#include <vector>

class QuestionChoose;
class QuestionFirst;
class QuestionSecondChoose;
class QuestionSecondFillBlank;
class Word;

class Test{
    int rightNum0;
    int rightNum1;
    int rightNum2;
    int wrongNum0;
    int wrongNum1;
    int wrongNum2;
    int quan0;
    int quan1;
    int quan2;
    static int staticRightNum0;
    static int staticRightNum1;
    static int staticRightNum2;
    static int staticWrongNum0;
    static int staticWrongNum1;
    static int staticWrongNum2;
    static double rightRate0;
    static double rightRate1;
    static double rightRate2;
public:
    Test();
    void QuanChange0();
    void QuanChange1();
    void QuanChange2();
    static void RightRateChange0();
    static void RightRateChange1();
    static void RightRateChange2();
    friend QuestionChoose;
    friend QuestionFirst;
    friend QuestionSecondChoose;
    friend QuestionSecondFillBlank;
    friend Word;
};

#endif /* defined(_______Test__) */
