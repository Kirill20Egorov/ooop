#pragma once
#include <iostream>
#include <vector>

using namespace std; 

bool IsPositive(float num);
void FillVectorFromInput(istream& input, vector<float>& nums);
float FindAveragePositive(const vector<float>& nums);
void AddAveragePositive(vector<float>& nums, float averagePositive);
void SortVector(vector<float>& nums);
void PrintVector(const vector<float>& nums, ostream& output);
