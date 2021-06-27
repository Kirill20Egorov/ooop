#include "Cone.h"
#include <iomanip>

CCone::CCone(double density, double radius, double height)
	: CSolidBody("Конус", density)
	, m_radius(radius)
	, m_height(height)
{
}

double CCone::GetRadius() const
{
	return m_radius;
}

double CCone::GetHeight() const
{
	return m_height;
}

double CCone::GetVolume() const
{
	return (GetHeight() * pow(GetRadius(), 2) * M_PI) / 3;
}

string CCone::GetStringUniqParams()const
{
	ostringstream strm;
	strm << "\tradius = " << GetRadius() << endl
		<< "\theight = " << GetHeight() << endl;
	return  strm.str();
}