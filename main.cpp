//:main.cpp
#include "Dictionary.h"
#include "Set.h"
#include "Word.h"
#include "Entry.h"
#include "Factory.h"
#include "Interface.h"
#include <ctime>
#include <cstdio>
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
    /*
    Dictionary* dic = Dictionary::GetInstance();
    ifstream fin("get.txt");
    ofstream fout("StandardSourc.txt");
    string line;
    string word;
    string ph;

    while (getline(fin, line))
    {
        word = "";
        ph = "";
        int firstph;
        int i = 0;
        for (i = 0; i < line.size(); ++i)
        {
            if (!(line[i] >= 'a' && line[i] <= 'z') && !(line[i] >= 'A' && line[i] <= 'Z'))
                break;
            word += line[i];
        }
        for (; i < line.size(); ++i)
        {
            if (line[i] == '/')
            {
                firstph = i;
                break;
            }
        }
        for (int j = firstph + 1; i < line.size(); ++j)
        {
            if (line[j] == '/')
                break;
            ph += line[j];
        }
        if (dic->WordExist(word))
        {
            Word* current = &(*dic)[dic->FindWord(word)];
            for (int i = 0; i < current->EntrySize(); ++i)
            {
                current->entries[i]->phonogram = ph;
            }
        }
    }
    for (int i = 0; i < dic->GetSize(); ++i)
    {
        Word* c = &(*dic)[i];
        cout << c->spell << endl;
        fout << c->spell << endl;
        for (int j = 0; j < c->entries.size(); ++j)
        {
            fout << c->entries[j]->phonogram << endl;
            fout << c->entries[j]->wordClass << endl;
            fout << c->entries[j]->meaningC << endl;
            fout << c->entries[j]->meaningE << endl;
            fout << "." << endl;
            if (c->entries[j]->wordClass == "noun")
            {
                fout << "-1" << endl
                        << "-1" << endl
                        << "-1" << endl
                        << "-1" << endl
                        << endl << endl << endl; 
            }
            else if (c->entries[j]->wordClass == "verb")
            {
                fout << "-1" << endl << endl;
                fout << "." << endl
                        << "." << endl
                        << "." << endl
                        << "." << endl;
            }
            else if (c->entries[j]->wordClass == "adj")
            {
                fout << "-1" << endl << "." << endl << "." << endl;
            }
            else if (c->entries[j]->wordClass == "adv")
            {
                fout << "." << endl<< "." << endl;
            }
            else if (c->entries[j]->wordClass == "pron")
            {
                fout << "-1" << endl << "-1" << endl;
            }
            else if (c->entries[j]->wordClass == "conj")
            {
                fout << endl;
            }
            else if (c->entries[j]->wordClass == "prep")
            {
                fout <<endl;
            }
            fout << "#" << endl;
        }
        fout << "*" << endl;
    }
    fin.close();
    fout.close();
    */
    delete ui;
    return 0; 
}