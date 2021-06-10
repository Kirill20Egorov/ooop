// WorkVector.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <vector>
#include <iostream>
#include <string>
#include "Vector.h"
#include <fstream>
using namespace std;

int main()
{
    // rename
    vector<float> nums;
    FillVectorFromInput(cin, nums);
    float average = FindAveragePositive(nums);
    AddAveragePositive(nums, average);
    SortVector(nums);
    PrintVector(nums, cout);
    return 0;
}