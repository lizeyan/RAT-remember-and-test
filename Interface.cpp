#include "Interface.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
consoleInterface* consoleInterface::instance = 0;
consoleInterface* consoleInterface::GetInstance()
{
    if (instance == 0)
        instance = new consoleInterface;
    return instance;
}
consoleInterface::consoleInterface()
{
    dic = Dictionary::GetInstance();
    mode = 0;
    user = NULL;
    op = NULL;
    pos = -1;
    level=0;
    testType=0;
    modified = false;
}
int Interface::kmp(string a, string b)
{
    return (Dictionary::GetInstance())->kmp(a, b);
}
void consoleInterface::ini()
{
    srand((unsigned int)time(NULL));
    int beginTime = clock();
    cout << "loading......" << endl;
    ifstream fin("StandardSource.txt");
    dic->Read (fin);
    fin.close();
    fin.open("RAT.ini");
    string tmp1;
    string tmp2;
    string tmp3;
    while(fin >> tmp1 >> tmp2 >> tmp3)
    {
        users.push_back(new User(tmp1, tmp2, tmp3));
    }
    fin.close();
    cout << "succefullly load." << endl
    << "time expend: "
    << (double)(clock() - beginTime) / CLOCKS_PER_SEC
    << "seconds" << endl;
    User* cuser = NULL;
    do
    {
        cout << "user name: ";
        string userName;
        cin >> userName;
        for (int i = 0; i < users.size(); ++i)
        {
            if (users[i]->GetName() == userName)
            {
                cuser = users[i];
                break;
            }
        }
    }
    while (!Login(cuser));
}
void consoleInterface::operation()
{
    string command;
    while (getline (cin, command))
    {
        while(command == "") getline (cin, command);
        if (mode == 1)
        {
            quiryModeAnalyse(command);
        }
        else
        {
            normalAnalyse(command);
        }
    }
}
void consoleInterface::FindWordExact(string command)
{
    int begin = 1;
    string targetWord;
    while (command[++begin] == 32);
    for (int i = begin; i < command.size(); ++i)
    {
        targetWord += command[i];
    }
    int pos = dic->FindWord(targetWord);
    if (pos < 0 || pos >= dic->GetSize() || !dic->WordExist(targetWord))
    {
        cout << targetWord << " not found" << endl;
    }
    else
    {
        cout << (*dic)[pos];
    }
}
void consoleInterface::FindSimilarWord(string command)
{
    int begin = 1;
    string targetWord;
    while (command[++begin] == 32 || command[begin] == '-' || command[begin] == 'i');
    for (int i = begin; i < command.size(); ++i)
    {
        targetWord += command[i];
    }
    vector<Word*> result;
    dic->FindWordFuzzy(targetWord, result);
    int idioms = kmp ("-i", command);
    if (idioms < 0 || idioms >= result.size())
    {
        for (int i = 0; i < result.size(); ++i)
        {
            int isIdiom = kmp (" ", result[i]->GetSpell());
            if (isIdiom >= 0 && isIdiom < result[i]->GetSpell().size())
            {
                result.erase(result.begin() + i);
                --i;
            }
        }
    }
    if (result.size() == 0)
    {
        cout << "no similar word in current dictionary found" << endl;
    }
    else
    {
        cout << "similar words:" << endl;
        for (int i = 0 ; i < result.size(); ++i)
        {
            cout << "\t" << i << ": " << result[i]->GetSpell() << endl;
        }
    }
}
void consoleInterface::FindWordFuzzy(string command)
{
    int begin = 1;
    string targetWord;
    while (command[++begin] == 32 || command[begin] == '-' || command[begin] == 'i');
    for (int i = begin; i < command.size(); ++i)
    {
        targetWord += command[i];
    }
    vector<Word*> result;
    dic->FindWordFuzzy(targetWord, result);
    int idioms = kmp ("-i", command);
    if (idioms < 0 || idioms >= result.size())
    {
        for (int i = 0; i < result.size(); ++i)
        {
            int isIdiom = kmp (" ", result[i]->GetSpell());
            if (isIdiom >= 0 && isIdiom < result[i]->GetSpell().size())
            {
                result.erase(result.begin() + i);
                --i;
            }
        }
    }
    if (result.size() == 0)
    {
        cout << "no matched word in current dictionary found" << endl;
    }
    else
    {
        for (int i = 0 ; i < result.size(); ++i)
        {
            cout << i << ": " << endl << *(result[i]);
        }
    }
}
void consoleInterface::quiryModeAnalyse(string command)
{
    if (kmp("-e", command) == 0)
    {
        FindWordExact(command);
    }
    else if (kmp("-s", command) == 0)
    {
        FindSimilarWord(command);
    }
    else if (kmp("-f", command) == 0)
    {
        FindWordFuzzy(command);
    }
    else if (command == "mode 0")
    {
        mode = 0;
    }
    else if (command == "mode 1")
    {
        mode = 1;
    }
    else
    {
        FindWordExact(string ("-e") + command);
    }
}
bool consoleInterface::Pass(int testType)
{
    if (testType == 0)
    {
        if (Test::rightRate0 >= 0.95)
            return true;
        return false;
    }
    else if (testType == 1)
    {
        if (Test::rightRate1 >= 0.80)
            return true;
        return false;
    }
    else if (testType == 2)
    {
        if (Test::rightRate2 >= 0.75)
            return true;
        return false;
    }
    else
    {
        cout << "wrong testType:" << testType;
        return false;
    }
}
void consoleInterface::Exam()
{
    if (user->GetLevel() == 3)
    {
        cout << "You are the highest level now. "
        << "Maybe we will open more level in the furure" << endl;
        return;
    }
    cout << "You will pass the exam if you test at least 20 times and keep you rate:\n"
    << "type0: 0.95\ttype1: 0.80\ttype2: 0.75" << endl
    << "The type of exam is random. The level of type 0 or type 1 is 4.\nQuit anytime with \"mode 0\"" << endl;
    string examFileName[4] = {"", "level1.txt", "level2.txt", "level3.txt"};
    Set* examSet = new Set;
    ifstream fin(examFileName[user->GetLevel() + 1].c_str());
    examSet->Read(fin);
    fin.close();
    int level = 4;
    int testType = rand() % 3;
    TestDo(examSet, level, testType);
    if (Pass(testType))
    {
        modified = 1;
        user->LevelUp();
        cout << "Good! You pass the exam. Now your level is " << user->GetLevel() << "." << endl;
    }
    else
    {
        cout << "Maybe you need to learn more." << endl;
    }
    delete examSet;
}
void consoleInterface::Save()
{
    ofstream fout;
    if (!modified)
        return;
    string command;
    cout << "save the modification? Y or N" <<endl;
    while (cin >> command)
    {
        if (command == "Y")
        {
            cout << "saving...." << endl;
            //rewrite user
            fout.open("RAT.ini");
            for (int i = 0; i < users.size(); ++i)
            {
                fout << users[i]->GetName() << endl << users[i]->GetPassword()
                << endl << users[i]->GetLevel() << endl;
                if (!i == users.size() - 1)
                    fout << endl;
            }
            fout.close();
            //rewrite .set
            fout.open((user->GetName() + ".set").c_str());
            for (int i = 0; i < user->GetSize(); ++i)
            {
                fout << user->GetSet(i)->GetName();
                if (!i == user->GetSize() - 1)
                    fout << endl;
            }
            fout.close();
            //rewrite set
            for (int i = 0; i < user->GetSize(); ++i)
            {
                fout.open((user->GetSet(i)->GetName() + ".txt").c_str());
                for (int j = 0; j < user->GetSet(i)->GetSize(); ++j)
                {
                    fout << (*(user->GetSet(i)))[j].GetSpell();
                    if (j != user->GetSet(i)->GetSize() - 1)
                        fout << endl;
                }
                fout.close();
            }
            cout << "saved" << endl;
            break;
        }
        else if (command == "N")
        {
            break;
        }
    }
    modified = false;
}
void consoleInterface::Info()
{
    cout << "level: " << user->GetLevel() << endl;
    cout << "set information:" << endl;
    if (user != NULL)
        for (int i = 0; i < user->GetSize(); ++i)
        {
            cout << "\t" << i + 1 << ": " << user->GetSet(i)->GetName()
            << " size:" << user->GetSet(i)->GetSize() << endl;
        }
}
void consoleInterface::Exit()
{
    Save();
    exit(0);
}
void consoleInterface::normalAnalyse(string command)
{
    if (command == "help")
    {
        outHelp();
    }
    else if (command == "version")
    {
        outVersion();
    }
    else if (command == "exit")
    {
        Exit();
    }
    else if (command == "mode 0")
    {
        mode = 0;
    }
    else if (command == "mode 1")
    {
        mode = 1;
    }
    else if (command == "info")
    {
        Info();
    }
    else if (kmp("test", command) == 0)
    {
        Test(command);
    }
    else if (kmp("add", command) == 0)
    {
        int file = kmp ("-f", command);
        if (file >= 0 && file < command.size())
            AddFile (command);
        else
            AddWord (command);
    }
    else if (kmp("touch", command) == 0)
    {
        int a = kmp ("-t", command);
        int b = kmp ("-u", command);
        if (b < 0 || b >= command.size())
            TouchSet(command);
        else if (a < 0 || a >= command.size())
            TouchUser(command);
        else if (a < b)
            TouchSet (command);
        else
            TouchUser (command);
    }
    else if (kmp ("switch", command) == 0)
    {
        Switch(command);
    }
    else if (kmp("exam", command) == 0)
    {
        Exam();
    }
    else if (command == "");
    else
    {
        cout << "no command of " << command << ". Try \"help\"" << endl;
    }
}

void consoleInterface::Test(string command)
{
    if (user == NULL)
    {
        cout << "please login" << endl;
        return;
    }
    int begin = kmp("-t", command) + 1;
    if(begin<3 || begin>=command.size()){
        cout<<"please type in set"<<endl;
        return;
    }
    while (command[++begin] == 32);
    string setName;
    int lin=0;
    for (int i = begin; ; ++i)
    {
        lin=i;
        if(i>=command.size()){
            cout<<"input error"<<endl;
            return;
        }
        if(command[i]==' ') break;
        setName += command[i];
    }
    lin++;
    char testtype=command[lin];
    testType=testtype-'0';
    if(testType>2){
        cout<<"no this testType, please input again!"<<endl;
        return;
    }
    pos = user->FindSet(setName);
    if (pos < 0 || pos >= user->GetSize())
    {
        cout << "no such set. Try \"toch\"" << endl;
    }
    else
    {
        if(testType!=2){
            cout<<"plesae choose level (2~8)"<<endl;
            cin>>level;
            while(level>8||level<2){
                cout<<"the level is illegal, please input again!"<<endl;
                cin>>level;
            }
            string s;
            getline (cin, s);
            cout<<endl;
        }
        else{
            level=-1;
        }
        TestDo();
    }
}
void consoleInterface::TestDo()
{
    while(1)
    {
        op=new opera(user->GetSet(pos), level, testType);
        op->ope(cout);
        string answer;
        getline(cin,answer);
        while(answer==""){
            getline(cin,answer);
        }
        if(answer=="mode 0")
            return;
        op->first(answer, cout);
    }
}
void consoleInterface::TestDo(Set* s, int le, int ttype)
{
    if (ttype == 2)
        le = -1;
    while(1)
    {
        op=new opera(s, le, ttype);
        op->ope(cout);
        string answer;
        getline(cin,answer);
        if(answer=="mode 0")
            return;
        op->first(answer, cout);
    }
}
void consoleInterface::AddWord(string command)
{
    if (user == NULL)
    {
        cout << "please login" << endl;
        return;
    }
    int begin = kmp("-t", command) + 1;
    while (command[++begin] == 32);
    string setName;
    for (int i = begin; i < command.size() && command[i] != 32; ++i)
    {
        setName += command[i];
    }
    int pos = user->FindSet(setName);
    if (pos < 0 || pos >= user->GetSize())
    {
        cout << "no such set: " << setName << endl;
        return;
    }
    vector<string> words;
    begin = kmp("-w", command) + 1;
    while (command[++begin] == 32);
    while (begin < command.size())
    {
        int end = begin - 1;
        while (++end < command.size() && command[end] != '.');
        if (end < command.size())
        {
            string tmp;
            for (int i = begin; i < end; ++i)
                tmp += command[i];
            words.push_back(tmp);
        }
        begin = end;
        while (++begin < command.size() && command[begin] == 32);
    }
    for (int i = 0; i < words.size(); ++i)
    {
        int p = dic->FindWord(words[i]);
        if (p < 0 || p >= dic->GetSize())
            continue;
        user->GetSet(pos)->Insert ((*dic)[p]);
        modified = true;
    }
    cout << "successfully add" << endl;
}
void consoleInterface::AddFile(string command)
{
    if (user == NULL)
    {
        cout << "please login" << endl;
        return;
    }
    int begin = kmp("-t", command) + 1;
    while (command[++begin] == 32);
    string setName;
    for (int i = begin; i < command.size() && command[i] != 32; ++i)
    {
        setName += command[i];
    }
    int pos = user->FindSet(setName);
    if (pos < 0 || pos >= user->GetSize())
    {
        cout << "no such set: " << setName << endl;
        return;
    }
    begin = kmp ("-f", command) + 3;
    string fileName;
    for (int i = begin; i < command.size(); ++i)
    {
        fileName += command[i];
    }
    ifstream fin(fileName.c_str());
    if (!fin)
    {
        cout << "fail to open the file" << endl;
        return;
    }
    AnalyseFile(fin, user->GetSet(pos));
    fin.close();
    cout << "Finished" << endl;
}
bool consoleInterface::IsLetter (char x)
{
    if (x <= 'z' && x >= 'a')
        return true;
    else if (x <= 'Z' && x >= 'A')
        return true;
    else
        return false;
}
bool consoleInterface::FamiliarWord(string word, Set* levelSet)
{
    int pos = dic->FindWord(word);
    if (pos < 0 || pos >= dic->GetSize())
        return false;
    if (levelSet != NULL && levelSet->WordExist(word))
    {
        return true;
    }
    return false;
}
void consoleInterface::AnalyseFile(ifstream& fin, Set* s)
{
    string examFileName[4] = {"", "level1.txt", "level2.txt", "level3.txt"};
    Set* examSet = new Set;
    examSet = NULL;
    if (user->GetLevel() > 0)
    {
        ifstream finSet(examFileName[user->GetLevel()].c_str());
        examSet->Read(finSet);
        finSet.close();
    }
    string file;
    string tmp;
    while (fin >> tmp)
    {
            file += tmp;
    }
    int p = 0, q = 0;
    while (q < file.size() && p < file.size())
    {
        while (!IsLetter(file[p]) && p < file.size())
            p++;
        q = p;
        while (IsLetter(file[q]) && q < file.size())
            q++;
        string tmpWord;
        for (int i = p; i < q; ++i)
        {
            tmpWord += file[i];
        }
        if (!FamiliarWord(tmpWord, examSet))
        {
            if (!s->WordExist(tmpWord) && dic->WordExist(tmpWord))
            {
                modified = 1;
                s->Insert((*dic)[dic->FindWord(tmpWord)]);
            }
        }
        p = q + 1;
    }
    delete examSet;
}
void consoleInterface::TouchSet(string command)
{
    if (user == NULL)
    {
        cout << "please login" << endl;
        return;
    }
    int begin = kmp("-t", command) + 1;
    while (command[++begin] == 32);
    string setName;
    for (int i = begin; i < command.size(); ++i)
    {
        if (command[i] == 10 || command[i] == 13 || command[i] == 32 || command[i] == 9)
            break;
        setName += command[i];
    }
    int pos = user->FindSet(setName);
    if (pos < 0 || pos >= user->GetSize() || setName != user->GetSet(pos)->GetName())
    {
        Set* set = new Set(setName);
        user->InsertSet (*set);
        modified = true;
        cout << "successfully touch" << endl;
    }
    else
    {
        cout << "this set exist." << endl;
    }
}
void consoleInterface::TouchUser(string command)
{
    int begin = kmp("-u", command) + 1;
    while (command[++begin] == 32);
    string userName;
    for (int i = begin; i < command.size() && command[i] != 32; ++i)
    {
        userName += command[i];
    }
    for (int i = 0; i < users.size(); ++i)
    {
        if (userName == users[i]->GetName())
        {
            cout << userName << ": exist" << endl;
            return;
        }
    }
    begin = kmp ("-p", command) + 1;
    while (command[++begin] == 32);
    string password;
    for (int i = begin; i < command.size() && command[i] != 32; ++i)
    {
        password += command[i];
    }
    users.push_back(new User(userName, password, "0"));
    modified = true;
    cout << "successfully touch user:" << userName << endl;
}
void consoleInterface::Switch(string command)
{
    int begin = kmp("-u", command) + 1;
    while (command[++begin] == 32);
    string userName;
    for (int i = begin; i < command.size() && command[i] != 32; ++i)
    {
        userName += command[i];
    }
    for (int i = 0; i < users.size(); ++i)
    {
        if (userName == users[i]->GetName())
        {
            if (Login (users[i]))
            {
                Save();
            }
            return;
        }
    }
    cout << "wrong userName:" << userName << " not found" << endl;
}
bool consoleInterface::Login(User* u)
{
    if (u == NULL)
    {
        cout << "wrong user name" << endl;
        return false;
    }
    string tmp;
    char p;
    cout << "password:";
    cin >>tmp;
    //cout << tmp << u->GetPassword() << endl;
    cout << endl;
    if (tmp == u->GetPassword())
    {
        user = u;
        cout << "successfully login: " << u->GetName() << endl;
        return true;
    }
    else
    {
        cout << "wrong password" << endl;
        return false;
    }
}
void consoleInterface::outHelp()
{
    cout << "List of commands" << endl << endl
    << "mode 1 --step into quiry mode" << endl
    << "mode 0 --step into normal mode" << endl
    << "in mode 1:" << endl
    << "\t[-e] wordname --list all about this word,type -i to include all idioms" << endl
    << "\t-s [-i] wordname --list similar word" << endl
    << "\t-f [-i] string -- list all words details contain this string,type -i to include all idioms" << endl
    << "info --info about the current user" << endl
    << "test -t setname testType --test words in this set" << endl
    << "in test:"<<endl
    << "\ttestType can only be 0,1 or 2"<<endl
    << "\tinput mode0 to return normal mode"<<endl
    << "add -t setname -w word -- add word to a set, and you can add many word to one\n\t set in one command." << endl
    << "add -t setname -f filename --add new words from a text file, \n\tRAT will recognize your unfamiliar word" << endl
    << "\tIn order to do this, end each word with \'.\'" << endl
    << "exam --exam for one higher level" << endl
    << "touch -t setname --new set, the name must be a constant string." << endl
    << "touch -u userName -p password-- new user" << endl
    << "switch -u userName --switch user" << endl
    << "exit --exit this program" << endl
    << "help --view help document" << endl
    << "version --view information about this program" << endl;
}
void consoleInterface::outVersion()
{
    cout << "RAT remember and test 0.1" << endl
    << "Author: Li Zeyan	Lv Xin" << endl;
}