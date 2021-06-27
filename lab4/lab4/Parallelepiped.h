#pragma once

#include "SolidBody.h"


class CParallelepiped final :
	public CSolidBody
{
public:
	CParallelepiped(double density, double width, double height, double depth);
	double GetWidth() const;
	double GetHeight() const;
	double GetDepth() const;
	double GetVolume() const override;
	string GetStringUniqParams() const override;
private:
	double m_width;
	double m_height;
	double m_depth;
};