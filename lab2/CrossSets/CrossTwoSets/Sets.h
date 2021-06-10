#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

set<int> CrossSet(set<int> const& firstSet, set<int> const& secondSet);
int SumOfDigits(int num);
void PrintSet(ostream& output, const set<int> const& set);
void FillSetDivisibleItsDigits(set<int>& firstSet, int n);
void FillSetOfEvenItsDigits(set<int>& secondSet, int n);
