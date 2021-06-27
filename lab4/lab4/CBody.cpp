#include "CBody.h"
#include <string>
#include <iostream>

using namespace std;

CBody::CBody(const string& type)
	: m_type(type)
{
}

CBody::~CBody()
{
}

string CBody::ToString()const
{
	ostringstream strm;
	strm << m_type << ":" << endl
		<< "\tdensity = " << GetDensity() << endl
		<< "\tvolume = " << GetVolume() << endl
		<< "\tmass = " << GetMass() << endl
		<< GetStringUniqParams();
	return  strm.str();
}

string CBody::GetType() const
{
	return m_type;
}