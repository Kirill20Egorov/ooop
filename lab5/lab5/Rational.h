#include <iostream>
#include "stdlib.h"
#include "math.h"
using namespace std;

class CRational
{
public:
	//  онструирует рациональное число, равное нулю (0/1)
	CRational();

	//  онструирует рациональное число, равное value (value/1)
	CRational(int value);

	//  онструирует рациональное число, равное numerator/denominator
	// –ациональное число должно хранитьс€ в нормализованном виде:
	//	знаменатель положительный (числитель может быть отрицательным)
	//	числитель и знаменатель не имеют общиз делителей (6/8 => 3/4 и т.п.)
	// ≈сли знаменатель равен нулю, должно сконструироватьс€ рациональное число, равное нулю,
	// либо должно быть выброшено исключение std::invalid_argument.
	CRational(int numerator, int denominator);

	// ¬озвращает числитель
	int GetNumerator()const;

	// ¬озвращает знаменатель (натуральное число)
	int GetDenominator()const;

	// ¬озвращает отношение числител€ и знаменател€ в виде числа double
	double ToDouble()const;
	// ѕрочие операторы согласно заданию
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
