//:Entry.h
#ifndef ___ENTRY___
#define ___ENTRY___
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Test.h"
class Test;
class Entry
{
private:
    std::string phonogram;
    std::string wordClass;
    std::string meaningC;
    std::string meaningE;
    std::vector <std::string> example;
protected:
    virtual void Output(std::ostream&) const = 0;
    void OutputEle(std::ostream&) const;
    
public:
    Entry (std::string&, std::string&, std::string&, std::string&, std::vector<std::string>&);
    Entry ();
    friend std::ostream& operator << (std::ostream&, const Entry&);
    Test* test;
    std::string GetPhonogram()	const	{return phonogram;}
    std::string GetWordClass()	const	{return wordClass;}
    std::string GetMeaningC()	const	{return meaningC;}
    std::string GetMeaningE()	const	{return meaningE;}
    std::string GetExample(int) const;
    virtual ~Entry() {}
};
#endif