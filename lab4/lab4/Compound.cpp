#include "Compound.h"
#include <algorithm>
#include <numeric>

CCompound::CCompound(const vector<CBody*> & compoundBody)
	: CBody("Составное")
{
	for (unsigned int i = 0; i < compoundBody.size(); i++)
	{
		m_bodies = compoundBody;
	}
}

void CCompound::AddBody(CBody& body)
{
	m_bodies.push_back(this); 
}

CCompound::~CCompound()
{
	m_bodies.clear();
}

double CCompound::GetDensity() const
{
	auto volume = GetVolume();
	return (volume > 0) ? (GetMass() / volume) : 0;
}

double CCompound::GetVolume() const
{
	if (m_bodies.size() > 0)
	{
		double volume = 0;
		for (unsigned int i = 0; i < m_bodies.size(); i++)
		{
			volume += m_bodies[i]->GetVolume();
		}
		return volume;
	}

}
	
double CCompound::GetMass() const
{
	if (m_bodies.size() > 0)
	{
		double mass = 0;
		for (unsigned int i = 0; i < m_bodies.size(); i++)
		{
			mass = m_bodies[i]->GetMass();
		}
		return mass;
	}

}

string CCompound::GetStringUniqParams() const
{
	ostringstream strm;

	for (unsigned int i = 0; i < m_bodies.size(); i++)
	{
		strm << "\t" << m_bodies[i]->GetType() << ":" << endl
			<< "\tdensity = " << m_bodies[i]->GetDensity() << endl
			<< "\tvolume = " << m_bodies[i]->GetVolume() << endl
			<< "\tmass = " << m_bodies[i]->GetMass() << endl
		    << m_bodies[i]->GetStringUniqParams() << endl
		    << "_________________________" << endl;
	}
	return  strm.str();
}