#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool letter(char x)
{
	if (x <= 'z' && x >= 'a')
		return true;
	else if (x <= 'Z' && x >= 'A')
		return true;
	else
		return false;
}
int main ()
{
	string file = "";
	ifstream fin("lve2.txt");
	string word;
	ofstream fout("level2.txt");
	string tmp;
	while (getline(fin, tmp))
		file += tmp;
	int p = 0, q = 0;
	while (q < file.size())
	{
		while (!letter(file[p]) && p < file.size())
			p++;
		q = p;
		while (letter(file[q]) && q < file.size())
			q++;
		word = "";
		for (int i = p; i < q; ++i)
			word += file[i];
		fout << word << endl;
		p = q + 1;
	}
}