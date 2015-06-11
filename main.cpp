//:main.cpp
#include "Dictionary.h"
#include "Set.h"
#include "Word.h"
#include "Entry.h"
#include "consoleInterface.h"
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
    delete ui;
    return 0;
    
}