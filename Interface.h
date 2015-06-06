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
public:
    virtual void operation() = 0;
    virtual void ini() = 0;
    int kmp(std::string a, std::string b);
};
class consoleInterface: public Interface
{
    static consoleInterface* instance;
    Dictionary* dic;
    std::vector<User*> users;
    User* user;
    opera* op;
    int mode;
    int pos;
    int level;//测试的难度
    int testType;//选择第几种测试
    bool modified;
    consoleInterface();
protected:
    void List(std::string);
    void RemoveSet (std::string);
    void RemoveUser();
    bool IsLetter(char);
    bool Pass(int);
    void load();
    bool FamiliarWord(std::string, Set*);
    void AnalyseFile(std::ifstream&, Set*);
    void Exam();
    void Save();
    bool Login(User*);
    void Switch(std::string);
    void Exit();
    void Info();
    void TouchSet(std::string);
    void TouchUser (std::string);
    void FindWordExact(std::string);
    void FindSimilarWord(std::string);
    void FindWordFuzzy(std::string);
    void Test(std::string);
    void TestDo();
    void TestDo(Set*, int, int);
    void AddWord (std::string);
    void AddFile (std::string);
    void outHelp();
    void outVersion();
    void quiryModeAnalyse(std::string command);
    void normalAnalyse(std::string command);
    void Recite(std::string);
    void output();
public:
    static consoleInterface* GetInstance();
    void operation();
    void ini();
};
struct operate
{
    std::string type;
    std::string object;
};
#endif