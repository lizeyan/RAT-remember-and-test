//:main.cpp
#include "Dictionary.h"
#include "Interface.h"
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
//template of update
    /*
    Dictionary* dic = Dictionary::GetInstance();
    ifstream fin("ex.txt");
    ofstream fout("StandardSource.txt");
    string line;
    string word;
    string ex;
    while (getline (fin, line))
    {
        int i = 0;
        word = "";
        ex = "";
        for (; i < line.size(); ++i)
        {
            if (!(line[i] <= 'z' && line[i] >= 'a') && !(line[i] <= 'Z' && line[i] >= 'A'))
                break;
            word += line[i];
        }
        for (i++; i < line.size(); ++i)
        {
            ex += line[i];
        }
        if (dic->WordExist(word))
        {
            Word* c = &(*dic)[dic->FindWord(word)];
            for (int i = 0; i < c->EntrySize(); ++i)
             {
                c->GetEntry(i)->example.push_back(ex);
             }
        }
    }
    fin.close();
    for (int i = 0; i < dic->GetSize(); ++i)
    {
        Word* c = &(*dic)[i];
        fout << c->GetSpell() << endl;
        for (int j = 0; j < c->EntrySize(); ++j)
        {
            fout << c->GetEntry(j)->phonogram << endl;
            fout << c->GetEntry(j)->wordClass << endl;
            fout << c->GetEntry(j)->meaningC << endl;
            fout << c->GetEntry(j)->meaningE << endl;
            for (int k = 0; k < c->GetEntry(j)->example.size(); ++k)
            {
                fout << c->GetEntry(j)->example[k] << endl;
            }
            fout << "." << endl;
            if (c->GetEntry(j)->wordClass == "noun")
            {
                fout << "-1" << endl << "-1" << endl << "-1" << endl
                        << "-1" << endl << endl << endl
                        << endl;
            }
            else if (c->GetEntry(j)->wordClass == "verb")
            {
                fout << "-1" << endl <<endl  << "." << endl  << "." << endl
                 << "." << endl  << "." << endl;
            } 
            else if (c->GetEntry(j)->wordClass == "adj")
            {
                fout << "-1" << endl << "." << endl << "." << endl;
            }
            else if (c->GetEntry(j)->wordClass == "adv")
            {
                fout << "." << endl << "." << endl;
            }
            else if (c->GetEntry(j)->wordClass == "pron")
            {
                fout << "-1" << endl << "-1" << endl;
            }
            else if (c->GetEntry(j)->wordClass == "conj")
             {
                fout << endl;
             }
            else if (c->GetEntry(j)->wordClass == "")
            {
                fout << endl;
            }
                fout << "#" << endl;
        }
    fout << "*" << endl;
    }
    */