#pragma once
#include <iostream>
#include <string>
#include <map>

using namespace std;

void ToLower(string& word);
void InsertWordIntoMap(const string& word, map<string, int>& words);
void PrintMap(ostream& output, const map<string, int>& words);	