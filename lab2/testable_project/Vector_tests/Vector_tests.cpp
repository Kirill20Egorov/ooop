
#include <iostream>
#include <vector>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../WorkVector/Vector.h"

using namespace std; 



SCENARIO("Some tests")
{
	WHEN("2 positive nums")
	{
		istringstream input("5 5");
		vector<float> nums;
		ostringstream output;
		{
			FillVectorFromInput(input, nums);
			AddAveragePositive(nums, FindAveragePositive(nums));
			SortVector(nums);
			PrintVector(nums, output);
			CHECK(output.str() == "10.000 10.000 ");

		}
	}
	WHEN("2 positive and 1 negative nums")
	{
		istringstream input("5 5 -2");
		vector<float> nums;
		ostringstream output;
		{
			FillVectorFromInput(input, nums);
			AddAveragePositive(nums, FindAveragePositive(nums));
			SortVector(nums);
			PrintVector(nums, output);
			CHECK(output.str() == "3.000 10.000 10.000 ");
		}
	}
	WHEN("1 positive, 1 zero and 1 negative nums")
	{
		istringstream input("5 0 -2");
		vector<float> nums;
		ostringstream output;
		{
			FillVectorFromInput(input, nums);
			AddAveragePositive(nums, FindAveragePositive(nums));
			SortVector(nums);
			PrintVector(nums, output);
			CHECK(output.str() == "3.000 5.000 10.000 ");

		}
	}
}