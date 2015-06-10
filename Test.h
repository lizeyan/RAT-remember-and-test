#ifndef _______Test__
#define _______Test__

#include <iostream>
#include <vector>
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
    static int staticTmpRightNum0;
    static int staticTmpRightNum1;
    static int staticTmpRightNum2;
    static int staticTmpWrongNum0;
    static int staticTmpWrongNum1;
    static int staticTmpWrongNum2;
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
    void Clear();
    static void RightRateChange0();
    static void RightRateChange1();
    static void RightRateChange2();
    friend class QuestionChoose;
    friend class QuestionFirst;
    friend class QuestionSecondChoose;
    friend class QuestionSecondFillBlank;
    friend class Word;
    friend class Interface;
    friend class consoleInterface;
};

#endif /* defined(_______Test__) */
