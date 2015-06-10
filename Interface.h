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
protected:
    bool IsLetter(char);
    bool Pass(int);
public:
    virtual void operation() = 0;
    virtual void ini() = 0;
    int kmp(std::string a, std::string b);
    virtual void Write (std::ostream&, const Word*)= 0;
    virtual void convert(std::string, std::string)= 0;
    virtual void List(std::string, bool)= 0;
    virtual void RemoveSet (std::string)= 0;
    virtual void RemoveUser()= 0;
    virtual void RemoveWord(std::string command, std::vector<std::string>&)= 0;
    virtual void load()= 0;
    virtual bool FamiliarWord(std::string, Set*)= 0;
    virtual void AnalyseFile(std::ifstream&, Set*)= 0;
    virtual void Exam()= 0;
    virtual void Save()= 0;
    virtual bool Login(User*)= 0;
    virtual void Switch(std::string)= 0;
    virtual void Exit()= 0;
    virtual void Info()= 0;
    virtual void TouchSet(std::string)= 0;
    virtual void TouchUser (std::string, std::string)= 0;
    virtual void FindWordExact(std::string)= 0;
    virtual void FindSimilarWord(std::string)= 0;
    virtual void FindWordFuzzy(std::string)= 0;
    virtual void Test(std::string,std::string)= 0;
    virtual void AddWord (std::string,std::vector<std::string>&)= 0;
    virtual void AddFile (std::string,std::string)= 0;
    virtual void outHelp()= 0;
    virtual void outVersion()= 0;
    virtual void Recite(std::string)= 0;
    virtual void Change(std::string,std::string)= 0;
    virtual void Plus(std::string, std::string)= 0;
    virtual void Look(Set*)= 0;
    virtual void output()= 0;
    virtual void Remind(Set*)= 0;
};
#endif