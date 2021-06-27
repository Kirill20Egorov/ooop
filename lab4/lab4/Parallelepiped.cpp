#include "Parallelepiped.h"


CParallelepiped::CParallelepiped(double density, double width, double height, double depth)
	: CSolidBody("Параллелепипед", density)
	, m_width(width)
	, m_height(height)
	, m_depth(depth)
{
}

double CParallelepiped::GetWidth() const
{
	return m_width;
}

double CParallelepiped::GetHeight() const
{
	return m_height;
}

double CParallelepiped::GetDepth() const
{
	return m_depth;
}

double CParallelepiped::GetVolume() const
{
	return GetWidth() * GetHeight() * GetDepth();
}

string CParallelepiped::GetStringUniqParams()const
{
	ostringstream strm;
	strm << "\tdepth = " << GetDepth() << endl
	     << "\twidth = " << GetWidth() << endl 
		 << "\theight = " << GetHeight() << endl;
	return  strm.str();
}