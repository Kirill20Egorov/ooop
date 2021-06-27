#include "Sphere.h"
#include "iostream"
#include <string>

CSphere::CSphere(double density, double radius)
	: CSolidBody("Сфера", density)
	, m_radius(radius)
{
}

double CSphere::GetRadius()const
{
	return m_radius;
}

double CSphere::GetVolume()const
{
	return (pow(m_radius, 3) * M_PI) * 4 / 3;
}

string CSphere::GetStringUniqParams()const
{
	ostringstream strm;
	strm << "\tradius = " << GetRadius() << endl;
	return  strm.str();
}