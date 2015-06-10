//:consoleInterface.h
//:Interface.h
#ifndef ___CONSOLEINTERFACE___
#define ___CONSOLEINTERFACE___
#include "Interface.h"
#include "Dictionary.h"
#include "operation.h"
#include "User.h"
#include "Word.h"
#include <string>
#include <vector>
class Set;
class consoleInterface: public Interface
{
    static consoleInterface* instance;
    consoleInterface();
protected:
    void Write (std::ostream&, const Word*);
    void convert(std::string);
    void List(std::string);
    void RemoveSet (std::string);
    void RemoveUser();
    void RemoveWord(std::string command);
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
    void Change(std::string);
    void Plus(std::string);
    void Look(Set*);
    void output();
    void Remind(Set*);
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