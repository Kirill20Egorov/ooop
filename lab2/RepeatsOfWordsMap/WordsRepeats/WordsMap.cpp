#include <algorithm>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>
#include "WordsMap.h"


using namespace std;

void ToLower(string& word)
{
    transform(word.begin(), word.end(), word.begin(), tolower);
}

void InsertWordIntoMap(const string& word, map<string, int>& words)
{// nthyfhysq
    if (words[word])
    {
        words[word]++;
    }
    else
    {
        words[word] = 1;
    }
}

void PrintMap(ostream& output, const map<string, int>& words)
{
    for (const auto& word : words) 
    {
        output << word.first << " " << word.second << endl;
    }
}