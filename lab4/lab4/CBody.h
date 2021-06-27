#pragma once
#include <string>
#include <sstream>
#define _USE_MATH_DEFINES 
#include <cmath>
#include <iostream>
#define M_PI
#include <math.h>

using namespace std;

class CBody
{
public:
	CBody(const string& type);
	virtual double GetDensity() const = 0;
	virtual double GetVolume() const = 0;
	virtual double GetMass() const = 0;
	virtual string GetStringUniqParams() const = 0;
	string GetType() const;
	string ToString() const;
	virtual ~CBody();
private:	
	string m_type;
};

