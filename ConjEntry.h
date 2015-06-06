#ifndef _______ConjEntry__
#define _______ConjEntry__

#include "Entry.h"
#include <iostream>

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
    ~ConjEntry() {}
};

#endif /* defined(_______ConjEntry__) */
