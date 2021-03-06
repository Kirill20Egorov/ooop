#pragma once
#include "SolidBody.h"
#include <string>


class CCylinder final:
	public CSolidBody
{
public:
	CCylinder(double density, double radius, double height);
	double GetRadius() const;
	double GetHeight() const;
	double GetVolume() const override;
	string GetStringUniqParams() const override;
private:
	double m_radius;
	double m_height;
};