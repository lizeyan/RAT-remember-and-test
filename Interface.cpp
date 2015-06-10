#include "Interface.h"
#include "recite.h"
#include "Dictionary.h"
#include <string>
using namespace std;
int Interface::kmp(string a, string b)
{
    return (Dictionary::GetInstance())->kmp(a, b);
}
bool Interface::Pass(int testType)
{
    if (testType == 0)
    {
        if (Test::rightRate0 >= 0.95)
            return true;
        return false;
    }
    else if (testType == 1)
    {
        if (Test::rightRate1 >= 0.80)
            return true;
        return false;
    }
    else if (testType == 2)
    {
        if (Test::rightRate2 >= 0.75)
            return true;
        return false;
    }
    else
    {
        cout << "wrong testType:" << testType;
        return false;
    }
}
bool Interface::IsLetter (char x)
{
    if (x <= 'z' && x >= 'a')
        return true;
    else if (x <= 'Z' && x >= 'A')
        return true;
    else
        return false;
}