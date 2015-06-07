#include "Interface.h"
#include "recite.h"
#include "Dictionary.h"
#include <string>
using namespace std;
int Interface::kmp(string a, string b)
{
    return (Dictionary::GetInstance())->kmp(a, b);
}