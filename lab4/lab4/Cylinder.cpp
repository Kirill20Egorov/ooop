#include "Cylinder.h"

CCylinder::CCylinder(double density, double radius, double height)
	: CSolidBody("Цилиндр", density)
	, m_radius(radius)
	, m_height(height)
{
}

double CCylinder::GetRadius() const
{
	return m_radius;
}

double CCylinder::GetHeight() const 
{
	return m_height;
}

double CCylinder::GetVolume() const
{
	return GetHeight() * pow(GetRadius(), 2) * M_PI;
}

string CCylinder::GetStringUniqParams()const
{
	ostringstream strm;
	strm << "\tradius = " << GetRadius() << endl
		<< "\theight = " << GetHeight() << endl;
	return  strm.str();
}