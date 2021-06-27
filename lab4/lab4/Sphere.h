
#pragma once

#include "SolidBody.h"

class CSphere final :
	public CSolidBody
{
public:
	CSphere(double density, double radius);
	double GetRadius() const;
	double GetVolume() const override;
	string GetStringUniqParams() const override;
private:
	double m_radius;
};