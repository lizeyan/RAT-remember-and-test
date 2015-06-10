//:Factory.h
#ifndef ___FACTORY___
#define ___FACTORY___
#include "Entry.h"
#include <vector>
#include <string>
//factory承担分析词典文件的工作
//每一行是一个string
class EntryFactory
{
public:
    virtual Entry* create (std::vector<std::string>&) = 0;//new一个entry*传出去
};
#endif