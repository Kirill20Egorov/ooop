#pragma once
#include "CBody.h"

using namespace std;

class CSolidBody:
	public CBody
{
public:
	CSolidBody(const string& type, double density);
	double GetDensity() const final;
	double GetMass() const final;
	virtual ~CSolidBody() override;
private:
	double m_density;
};