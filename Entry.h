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
};
class NounEntry:public Entry
{
private:
    friend class NounFactory;
    int countable;
    int aOrAn;
    int proper;
    int single;
    std::string completeForm;
    std::string abbrForm;
    std::string pluralForm;
protected:
    void Output(std::ostream&) const;
public:
    NounEntry ();
    NounEntry (std::string&, std::string&, std::string&, std::string&,
               std::vector<std::string>&,
               int, int, int, int, std::string&, std::string&, std::string&);
    int GetCountable() const {return countable;}
    int getAOrAn()	const {return aOrAn;}
    int GetProper()	const {return proper;}
    int GetSingle()	const{return single;}
    std::string GetCompleteForm()	const {return completeForm;}
    std::string GetAbbrForm()	const {return abbrForm;}
    std::string GetPluralForm() const {return pluralForm;}
    
};
class VerbEntry:public Entry
{
private:
    int viOrVt;
    std::string tpsForm;
    std::vector<std::string> presentForm;
    std::vector<std::string> pastTense;
    std::vector<std::string> pastParticle;
    std::vector<std::string> phrase;
protected:
    void Output(std::ostream&) const;
public:
    VerbEntry ();
    VerbEntry (std::string&, std::string&, std::string&, std::string&, std::vector<std::string>&,
               int, std::string&, std::vector<std::string>&, std::vector<std::string>&,
               std::vector<std::string>&, std::vector<std::string>&);
    int GetViOrVt()	{return viOrVt;}
    std::string GetPhrase(int)const;
    std::string GetTpsForm()	const {return tpsForm;}
    std::string GetPresentFoem(int)const;
    std::string GetPastForm(int)const;
    std::string GetPastParticle(int)const;
};
class AdjEntry:public Entry
{
private:
    int predOrAttr;
    std::vector<std::string> comparative;
    std::vector<std::string> highest;
protected:
    void Output(std::ostream&) const;
public:
    AdjEntry();
    AdjEntry(std::string&, std::string&, std::string&, std::string&, std::vector<std::string>&,
             int, std::vector<std::string>&, std::vector<std::string>&);
    int GetPredOrAttr ()	const {return predOrAttr;}
    std::string GetComparative(int)const;
    std::string GetHighest(int)const;
};
class AdvEntry:public Entry
{
private:
    std::vector<std::string> comparative;
    std::vector<std::string> highest;
protected:
    void Output(std::ostream&) const;
public:
    AdvEntry();
    AdvEntry (std::string&, std::string&, std::string&, std::string&, std::vector<std::string>&,
              std::vector<std::string>&, std::vector<std::string>&);
    std::string GetComparative(int)const;
    std::string GetHighest(int)const;
};
class PronEntry:public Entry
{
private:
    int person;
    int single;
protected:
    void Output(std::ostream&) const;
public:
    PronEntry();
    PronEntry (std::string&, std::string&, std::string&, std::string&, std::vector<std::string>&,
               int ,int);
    int GetPerson()	const{return person;}
    int GetSingle() const{return single;}
};
class ConjEntry:public Entry
{
private:
    std::string category;
protected:
    void Output(std::ostream&) const;
public:
    ConjEntry();
    ConjEntry (std::string&, std::string&, std::string&, std::string&, std::vector<std::string>&, std::string&);
    std::string GetCategory()	const {return category;}
};

class PrepEntry:public Entry
{
protected:
    void Output (std::ostream&) const;
public:
    PrepEntry ();
    PrepEntry (std::string&, std::string&, std::string&, std::string&, std::vector<std::string>&);
};
#endif