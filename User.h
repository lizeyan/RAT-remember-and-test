//:User.h
#ifndef ___USER___
#define ___USER___
#include "Set.h"
#include <string>
class User
{
    std::string name;
    std::string password;
    std::vector<Set*> wordSets;
    int level;//1 2 3
public:
    int FindSet(std::string targetSet) const;
    std::string GetName() {return name;}
    std::string GetPassword () {return password;}
    User (std::string n, std::string p,std::string);
    Set* GetSet(int rank) {return wordSets[rank];}
    int GetSize() {return wordSets.size();}
    int InsertSet (Set&);
};
#endif