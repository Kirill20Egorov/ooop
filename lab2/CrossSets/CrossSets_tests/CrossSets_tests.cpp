
#include <iostream>
#include <set>
#include <algorithm>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../CrossTwoSets/Sets.h"

using namespace std;

SCENARIO("Some tests")
{
	WHEN("N=15")
	{
		istringstream input("15");
		set<int> firstSet;
		set<int> secondSet;
		ostringstream output;
		{
			int n;
			input >> n;
			FillSetDivisibleItsDigits(firstSet, n);
			FillSetOfEvenItsDigits(secondSet, n);
			set<int> resultSet = CrossSet(firstSet, secondSet);
			PrintSet(output, resultSet);
			CHECK(output.str() == "2 4 6 8 ");
		}
	}
	WHEN("N=2")
	{
		istringstream input("2");
		set<int> firstSet;
		set<int> secondSet;
		ostringstream output;
		{
			int n;
			input >> n;
			FillSetDivisibleItsDigits(firstSet, n);
			FillSetOfEvenItsDigits(secondSet, n);
			set<int> resultSet = CrossSet(firstSet, secondSet);
			PrintSet(output, resultSet);
			CHECK(output.str() == "2 ");
		}
	}
	WHEN("N=100")
	{
		istringstream input("100");
		set<int> firstSet;
		set<int> secondSet;
		ostringstream output;
		{
			int n;
			input >> n;
			FillSetDivisibleItsDigits(firstSet, n);
			FillSetOfEvenItsDigits(secondSet, n);
			set<int> resultSet = CrossSet(firstSet, secondSet);
			PrintSet(output, resultSet);
			CHECK(output.str() == "2 4 6 8 20 24 40 42 48 60 80 84 ");

		}
	}
}