//:Interface.h
#ifndef ___INTERFACE___
#define ___INTERFACE___
#include "Dictionary.h"
#include "operation.h"
#include "User.h"
#include <string>
#include <vector>
class Set;
class Interface
{
protected:
    User* user;
    std::vector <User*> users;
    Dictionary* dic;
    opera* op;
    int mode;
    int pos;
    int level;//测试的难度
    int testType;//选择第几种测试
    bool modified;
public:
    virtual void operation() = 0;
    virtual void ini() = 0;
    int kmp(std::string a, std::string b);
};
#endif