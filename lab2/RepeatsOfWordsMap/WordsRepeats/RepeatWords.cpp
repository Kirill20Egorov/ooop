#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>
#include "WordsMap.h"

using namespace std;

int main()
{
	map <string, int> words;
	string word;
	while((cin >> word) && (!cin.eof()))
	{
		ToLower(word);
		InsertWordIntoMap(word, words);
	}
	PrintMap(cout, words);
	return 0;
}