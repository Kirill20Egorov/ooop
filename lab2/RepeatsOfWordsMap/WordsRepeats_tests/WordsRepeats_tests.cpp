
#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../WordsRepeats/WordsMap.h"

using namespace std;


SCENARIO("Some tests")
{
	WHEN("Some words")
	{
		istringstream input("mother father brother sister mother mother father \n^Z");
		map <string, int> words;
		string word;
		ostringstream output;
		{
			while ((input >> word) && (!input.eof()))
			{
				ToLower(word);
				InsertWordIntoMap(word, words);
			}
			PrintMap(output, words);
			CHECK(output.str() == "brother 1\nfather 2\nmother 3\nsister 1\n");

		}
	}
	WHEN("Empty input")
	{
		istringstream input("^Z");
		map <string, int> words;
		string word;
		ostringstream output;
		{
			while ((input >> word) && (!input.eof()))
			{
				ToLower(word);
				InsertWordIntoMap(word, words);
			}
			PrintMap(output, words);
			CHECK(output.str() == "");

		}
	}
	WHEN("Every word meets once")
	{
		istringstream input("mother father brother sister\n^Z");
		map <string, int> words;
		string word;
		ostringstream output;
		{
			while ((input >> word) && (!input.eof()))
			{
				ToLower(word);
				InsertWordIntoMap(word, words);
			}
			PrintMap(output, words);
			CHECK(output.str() == "brother 1\nfather 1\nmother 1\nsister 1\n");

		}
	}
	WHEN("Words in different registr")
	{
		istringstream input("mother father faTHer brother brOther sister\n^Z");
		map <string, int> words;
		string word;
		ostringstream output;
		{
			while ((input >> word) && (!input.eof()))
			{
				ToLower(word);
				InsertWordIntoMap(word, words);
			}
			PrintMap(output, words);
			CHECK(output.str() == "brother 2\nfather 2\nmother 1\nsister 1\n");

		}
	}
}