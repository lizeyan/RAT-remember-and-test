//:Factory.h
#ifndef ___FACTORY___
#define ___FACTORY___
#include <vector>
#include <string>
//factory承担分析词典文件的工作
//每一行是一个string
class EntryFactory;
class WordFactory
{
protected:
    EntryFactory* typeChoose (std::string&);
public:
    Word* create (std::vector<std::string>&);//new 一个word*,传出去
};
class EntryFactory
{
public:
    virtual Entry* create (std::vector<std::string>&) = 0;//new一个entry*传出去
};
class NounEntryFactory:public EntryFactory
{
public:
    Entry* create (std::vector<std::string>&);
};
class VerbEntryFactory:public EntryFactory
{
public:
    Entry* create (std::vector<std::string>&);
};
class AdjEntryFactory:public EntryFactory
{
public:
    Entry* create (std::vector<std::string>&);
};
class AdvEntryFactory:public EntryFactory
{
public:
    Entry* create (std::vector<std::string>&);
};
class PronEntryFactory:public EntryFactory
{
public:
    Entry* create (std::vector<std::string>&);
};
class ConjEntryFactory:public EntryFactory
{
public:
    Entry* create (std::vector<std::string>&);
};
class PrepEntryFactory:public EntryFactory
{
public:
    Entry* create (std::vector<std::string>&);
};
#endif