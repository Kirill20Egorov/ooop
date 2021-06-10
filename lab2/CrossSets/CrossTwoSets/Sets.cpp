#include <iostream>
#include <set>
#include <algorithm>
#include "Sets.h"

using namespace std;

set<int> CrossSet(set<int> const& firstSet, set<int> const& secondSet)
{
    set<int> newSet;
    set_intersection(firstSet.begin(), firstSet.end(), secondSet.begin(), secondSet.end(), inserter(newSet, newSet.begin()));
    return newSet;
}

void PrintSet(ostream& output, const set<int> const& set)
{
    for (int i : set)
    {
        output << i << ' ';
    }
}

int SumOfDigits(int num)
{
    int sum = 0;
    while (num != 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

void FillSetDivisibleItsDigits(set<int>& firstSet, int n)
{
    for (unsigned int i = 1; i <= n; i++)
    {
        if (i % SumOfDigits(i) == 0)
        {
            firstSet.insert(i);
        }
    }
}

void FillSetOfEvenItsDigits(set<int>& secondSet, int n)
{
    for (unsigned int i = 1; i <= n; i++)
    {
        if (SumOfDigits(i) % 2 == 0)
        {
            secondSet.insert(i);
        }
    }
}