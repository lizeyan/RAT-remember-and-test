//:main.cpp
#include "Dictionary.h"
#include "Set.h"
#include "Word.h"
#include "Entry.h"
#include "Factory.h"
#include "Interface.h"
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main ()
{
    srand(time(0));
    Interface* ui = consoleInterface::GetInstance();
    ui->ini();
    ui->operation();
    
    ////Dictionary* dic = Dictionary::GetInstance();
    //for (int i = 0; i < dic->GetSize(); ++i)
    //	dic->kmp("make", (*dic)[i].GetSpell());
    //cout << *dic << endl;
    delete ui;
    return 0;
    
}