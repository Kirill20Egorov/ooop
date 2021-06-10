// CrossTwoSets.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <set>
#include <algorithm>
#include "Sets.h"

using namespace std;

int main()
{
    set<int> firstSet;
    set<int> secondSet;
    int n;
    cin >> n;
    FillSetDivisibleItsDigits(firstSet, n);
    FillSetOfEvenItsDigits(secondSet, n);
    set<int> resultSet = CrossSet(firstSet, secondSet);
    PrintSet(cout, resultSet);
    return 0;
}
