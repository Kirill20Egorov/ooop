#include <iostream>
#include "stdlib.h"
#include "math.h"
using namespace std;

class CRational
{
public:
	// ������������ ������������ �����, ������ ���� (0/1)
	CRational();

	// ������������ ������������ �����, ������ value (value/1)
	CRational(int value);

	// ������������ ������������ �����, ������ numerator/denominator
	// ������������ ����� ������ ��������� � ��������������� ����:
	//	����������� ������������� (��������� ����� ���� �������������)
	//	��������� � ����������� �� ����� ����� ��������� (6/8 => 3/4 � �.�.)
	// ���� ����������� ����� ����, ������ ����������������� ������������ �����, ������ ����,
	// ���� ������ ���� ��������� ���������� std::invalid_argument.
	CRational(int numerator, int denominator);

	// ���������� ���������
	int GetNumerator()const;

	// ���������� ����������� (����������� �����)
	int GetDenominator()const;

	// ���������� ��������� ��������� � ����������� � ���� ����� double
	double ToDouble()const;
	// ������ ��������� �������� �������
	void Normalize();
	CRational const operator-() const;
	CRational const operator+() const;
	CRational& operator+=(CRational const& rhs);
	CRational& operator-=(CRational const& rhs);
	CRational& operator*=(CRational const& rhs);
	CRational& operator/=(CRational const& rhs);
	pair<int, CRational> ToCompoundFraction() const;
private:
	int m_numerator;
	int m_denominator;
	int NOD(int a, int b);
};

const CRational operator+(const CRational& lrational, const CRational& rrational);
const CRational operator-(const CRational& lrational, const CRational& rrational);
const CRational operator*(const CRational& lhs, const CRational& rhs);
const CRational operator/(const CRational& lhs, const CRational& rhs);
bool operator==(const CRational& lhs, const CRational& rhs);
bool operator!=(const CRational& lhs, const CRational& rhs);
bool const operator<(const CRational& lhs, const CRational& rhs);
bool const operator<=(const CRational& lhs, const CRational& rhs);
bool const operator>(const CRational& lhs, const CRational& rhs);
bool const operator>=(const CRational& lhs, const CRational& rhs);
ostream& operator<<(ostream& stream, CRational const& rational);
istream& operator >> (std::istream& stream, CRational& rational);
