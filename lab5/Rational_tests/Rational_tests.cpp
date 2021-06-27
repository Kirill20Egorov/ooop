#define CATCH_CONFIG_MAIN
#include <iostream>
#include <vector>
#include "../../catch2/catch.hpp"
#include "../lab5/Rational.h"

using namespace std;

SCENARIO("Create rational nums")
{
	CRational zero;
	REQUIRE(zero.GetDenominator() == 1);
	REQUIRE(zero.GetNumerator() == 0);
	REQUIRE(zero.ToDouble() == 0);
	CRational whole(5);
	REQUIRE(whole.GetDenominator() == 1);
	REQUIRE(whole.GetNumerator() == 5);
	REQUIRE(whole.ToDouble() == 5);
	CRational rational(1, 2);
	REQUIRE(rational.GetDenominator() == 2);
	REQUIRE(rational.GetNumerator() == 1);
	REQUIRE(rational.ToDouble() == Approx(0.5));
	CRational rat(-1, 2);
	REQUIRE(rat.GetNumerator() == -1);
	REQUIRE(rat.GetDenominator() == 2);
	CRational rat2(2, -4);
	REQUIRE(rat2.GetNumerator() == -1);
	REQUIRE(rat2.GetDenominator() == 2);
	CRational whole2(-4);
	REQUIRE(whole2.GetNumerator() == -4);
	REQUIRE(whole2.GetDenominator() == 1);
	WHEN("Check normalize view")
	{
		CRational rational2(50, 100);
		REQUIRE(rational.GetDenominator() == 2);
		REQUIRE(rational.GetNumerator() == 1);
		REQUIRE(rational.ToDouble() == Approx(0.5));
	}
	WHEN("Check unary signs")
	{
		REQUIRE(-zero == 0);
		REQUIRE(+zero == zero);
		REQUIRE(-whole == -5);
		REQUIRE(+whole == whole);
		REQUIRE(-rational == rational*(-1));
		REQUIRE(+rational == rational);
	}
	WHEN("Check binary operations")
	{
		REQUIRE(zero + whole == whole);
		REQUIRE(whole - zero == whole);
		REQUIRE(whole + 1 == 6);
		REQUIRE(1 + whole == 6);
		REQUIRE(rational + rational == 1);
		REQUIRE((rational + 1).ToDouble() == 1.5);
		REQUIRE((1 + rational).ToDouble() == 1.5);
	}
	WHEN("Check += AND -=")
	{
		rational += 1;
		REQUIRE(rational.ToDouble() == 1.5);
		rational += rational;
		REQUIRE(rational == 3);
		rational -= rational;
		REQUIRE(rational == zero);
		rational -= 5;
		REQUIRE(rational == -5);
	}
	WHEN("Check* AND / ")
	{
		CRational first(3, 4);
		CRational second(10, 3);
		CRational third(3, 1);
		REQUIRE((first * second).ToDouble() == 2.5);
		REQUIRE((first * 3) == CRational(9, 4));
		REQUIRE((3 * first) == CRational(18, 8));
		REQUIRE((first / third).ToDouble() == 0.25);
		REQUIRE((first / 3).ToDouble() == 0.25);
		REQUIRE((3 / first) == 4);
	}
	WHEN("Check *= AND /=")
	{
		CRational first(3, 4);
		CRational second(10, 3);
		first *= second;
		REQUIRE(first.ToDouble() == 2.5);
		first *= 4;
		REQUIRE(first == 10);
		first /= 4;
		REQUIRE(first.ToDouble() == 2.5);
		first /= second;
		REQUIRE(first == CRational(3, 4));
	}
	WHEN("Check == AND !=")
	{
		CRational first(3, 4);
		CRational second(3, 3);
		CRational third(9, 12);
		REQUIRE(first == third);
		REQUIRE(first != second);
		REQUIRE(first.ToDouble() == 0.75);
		REQUIRE(first.ToDouble() != 0.6);
		REQUIRE(second == 1);
		REQUIRE(second == 3 / 3);
	}
	WHEN("Check comparsions")
	{
		CRational first(3, 4);
		CRational second(3, 3);
		CRational third(9, 12);
		REQUIRE((first >= third) == true);
		REQUIRE((first <= 1) == true);
		REQUIRE((first < second) == true);
		REQUIRE((1 >= second) == true);
		REQUIRE((1 < second) == false);
	}
}

SCENARIO("Check streaming operators")
{
	WHEN("Read and write")
	{
		istringstream someInput("6/4");
		CRational c;
		someInput >> c;
		ostringstream out;
		out << c;
		auto ct = c.ToCompoundFraction();
		REQUIRE(ct.first == 1);
		REQUIRE(ct.second.ToDouble() == 0.5);
	}
}