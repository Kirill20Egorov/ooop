#pragma once
#include "SolidBody.h"

class CCone final :
	public CSolidBody
{
public:
	CCone(double density, double radius, double height);
	double GetRadius() const;
	double GetHeight() const;
	double GetVolume() const override;
	string GetStringUniqParams() const override;
private:
	double m_radius;
	double m_height;
};