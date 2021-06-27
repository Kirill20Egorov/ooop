#pragma once
#include "CBody.h"
#include <iostream>
#include <vector>


using namespace std;

bool AddCyllinder(istream& input, vector<CBody*>& bodies);
bool AddSphere(istream& input, vector<CBody*>& bodies);
bool AddCone(istream& input, vector<CBody*>& bodies);
bool AddParallelepiped(istream& input, vector<CBody*>& bodies);
CBody* FindMostMassBody(const vector<CBody*>& bodies);
CBody* FindLessWaterWeightBody(const vector<CBody*>& bodies);
void PrintAllInfo(ostream& output, const vector<CBody*>& bodies);
bool AddCompoundBody(vector<CBody*>& compoundBody);