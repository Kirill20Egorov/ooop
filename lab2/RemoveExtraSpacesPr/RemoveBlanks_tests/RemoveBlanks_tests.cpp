#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../RemoveExtraBlanks/Remove.h"

using namespace std;

SCENARIO("Remove blanks from empty string gives empty string") 
{
	REQUIRE(RemoveExtraSpaces("").empty());
}

SCENARIO("RemoveExtraBlanks")
{
	WHEN("input stream contains 1 line")
	{
		istringstream input("1     line");
		ostringstream output;
		THEN("output stream is contains line without extra blanks")
		{
			RemoveSpacesLines(input, output);
			CHECK(output.str() == "1 line\n");
			CHECK(input.eof());
		}
	}
	WHEN("input stream contains several lines")
	{
		istringstream input("   Hello   it's     first    line\n  It's    a     second     line");
		ostringstream output;
		THEN("output stream is contains lines without extra blanks")
		{
			RemoveSpacesLines(input, output);
			CHECK(output.str() == "Hello it's first line\nIt's a second line\n");
			CHECK(input.eof());
		}
	}
	WHEN("input stream contains several lines and contains spaces in the end")
	{
		istringstream input("   Hello   it's     first    line\n  It's    a     second     line      with spaces  in the  end   ");
		ostringstream output;
		THEN("output stream is contains lines without extra blanks")
		{
			RemoveSpacesLines(input, output);
			CHECK(output.str() == "Hello it's first line\nIt's a second line with spaces in the end\n");
			CHECK(input.eof());
		}
	}
}