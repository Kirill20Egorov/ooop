#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
// nthyfhysv 
bool IsPositive(float num)
{
    return num > 0;
}

// renmae
void FillVectorFromInput(istream& input, vector<float>& nums)
{
    float num;
    while (input >> num)
    {
        nums.push_back(num);
    }
}

float FindAveragePositive(const vector<float>& nums)
{
    int i = 0;
    float sumNums = 0;
    for (unsigned int i = 0; i < nums.size(); i++)
    {
        if (IsPositive(nums[i]))
        {
            sumNums += nums[i];
        }
    }
    float averagePositive = 0;
    int countPositive = count_if(nums.begin(), nums.end(), IsPositive);
    if (countPositive != 0)
    {
        averagePositive = (sumNums / countPositive);
    }
    return averagePositive;
}   

void AddAveragePositive(vector<float>& nums, float averagePositive)
{
    for (unsigned int i = 0; i < nums.size(); i++)
    {
        nums[i] += averagePositive;
    }
}

void SortVector(vector<float>& nums)
{
    sort(nums.begin(), nums.end());
}

void PrintVector(vector<float>& nums, ostream& output)
{
    for (unsigned int i = 0; i < nums.size(); i++)
    {
        output << fixed << setprecision(3) << nums[i] << ' ';
    }
}