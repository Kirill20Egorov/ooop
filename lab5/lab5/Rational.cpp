#include "Rational.h"
#include <iostream>

using namespace std;

CRational::CRational(int numerator, int denominator)
{
	if (denominator == 0)
	{
		CRational();
	}
	else
	{
		m_numerator = (denominator * numerator >= 0) ? abs(numerator) : -(abs(numerator));
		m_denominator = abs(denominator);
	}
	Normalize();
}

CRational::CRational()
	: CRational(0, 1)
{
}

CRational::CRational(int value)
	: CRational(value, 1)
{
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

void CRational::Normalize() 
{
	int nod = NOD(m_denominator, m_numerator);
	m_denominator /= nod;
	m_numerator /= nod;
}

double CRational::ToDouble() const
{
	return static_cast<double>(m_numerator) / static_cast<double>(m_denominator);
}

CRational const CRational::operator-() const
{
	return CRational(-GetNumerator(), GetDenominator());
}

CRational const CRational::operator+() const
{
	return *this;
}

int CRational::NOD(int a, int b)
{
	a = abs(a);
	b = abs(b);
	if ((a != 0) && (b != 0))
	{
		if (a < b)
		{
			swap(a, b);
		}
		while (a % b != 0)
		{
			a = a % b;
			swap(a, b);
		}
		return b;
	}
	return 1;
}

CRational& CRational::operator+=(CRational const& rhs)
{
	m_numerator = GetNumerator() * rhs.GetDenominator() + GetDenominator() * rhs.GetNumerator();
	m_denominator = GetDenominator() * rhs.GetDenominator();
	Normalize();
	return *this;
}

CRational& CRational::operator-=(CRational const& rhs)
{
	m_numerator = GetNumerator() * rhs.GetDenominator() - GetDenominator() * rhs.GetNumerator();
	m_denominator = GetDenominator() * rhs.GetDenominator();
	Normalize();
	return *this;
}

CRational& CRational::operator*=(CRational const& rhs)
{
	m_numerator *= rhs.GetNumerator();
	m_denominator *= rhs.GetDenominator();
	Normalize();
	return *this;
}

CRational& CRational::operator/=(CRational const& rhs)
{
	m_numerator *= rhs.GetDenominator();
	m_denominator *= rhs.GetNumerator();
	Normalize();
	return *this;
}

const CRational operator+(const CRational& lhs, const CRational& rhs)
{
	return CRational(lhs.GetNumerator() * rhs.GetDenominator() + rhs.GetNumerator() * lhs.GetDenominator(),
		lhs.GetDenominator() * rhs.GetDenominator());
}

const CRational operator-(const CRational& lhs, const CRational& rhs)
{
	return CRational(lhs.GetNumerator() * rhs.GetDenominator() - rhs.GetNumerator() * lhs.GetDenominator(),
		lhs.GetDenominator() * rhs.GetDenominator());
}

const CRational operator*(const CRational& lhs, const CRational& rhs)
{
	return CRational(lhs.GetNumerator() * rhs.GetNumerator(),
		lhs.GetDenominator() * rhs.GetDenominator());
}

const CRational operator/(const CRational& lhs, const CRational& rhs)
{
	return CRational(lhs.GetNumerator() * rhs.GetDenominator(),
		lhs.GetDenominator() * rhs.GetNumerator());
}

bool operator==(const CRational& lhs, const CRational& rhs)
{
	return (lhs.GetNumerator() == rhs.GetNumerator()) && (lhs.GetDenominator() == rhs.GetDenominator());
}

bool operator!=(const CRational& lhs, const CRational& rhs)
{
	return !(lhs == rhs);
}

bool const operator<(const CRational& lhs, const CRational& rhs)
{
	return lhs.GetNumerator() * rhs.GetDenominator() < lhs.GetDenominator() * rhs.GetNumerator();
}

bool const operator<=(const CRational& lhs, const CRational& rhs)
{
	return lhs < rhs || lhs == rhs;
}

bool const operator>(const CRational& lhs, const CRational& rhs)
{
	return !(lhs <= rhs);
}

bool const operator>=(const CRational& lhs, const CRational& rhs)
{
	return !(lhs < rhs);
}

pair<int, CRational> CRational::ToCompoundFraction() const
{
	return { m_numerator / m_denominator, CRational(m_numerator % m_denominator, m_denominator) };
}

ostream& operator<<(ostream& stream, CRational const& rational)
{
	stream << rational.GetNumerator() << "/" << rational.GetDenominator() << " ";
	return stream;
}
istream& operator>>(istream& stream, CRational& rational)
{
	int numerator;
	int denominator;
	if ((stream >> numerator) && (stream.get() == '/') && (stream >> denominator))
	{
		rational = CRational(numerator, denominator);
	}
	return stream;
}