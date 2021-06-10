#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

bool FoundLine(const string& currString, const string& searchString)
{
	int position = currString.find(searchString);
	if (position != -1)
	{
		return true;
	}
	return false;
}

int main(int argc, char* argv[])
{
	const int NUM_OF_PARAMS = 3;

	if (argc != NUM_OF_PARAMS)
	{
		cout << "Error: Uncorrect number of arguments" <<
			"Use: findtext.exe <input file> <searching text" << endl;
		return 1;
	}
	ifstream input;
	input.open(argv[1]);
	if (!input.is_open())
	{
		cout << "Error: Couldn't open " << argv[1] << " for reading";
		return 1;
	}
	string searchString = argv[2];
	string currString;
	bool notFound = true;
	for (int numLine = 1; getline(input, currString); numLine++)
	{
		// TODO: Метод который возыращает Bool
		if (FoundLine(currString, searchString))
		{
			cout << numLine << endl;
			notFound = false;
		}
	}

	if (notFound)
	{
		cout << "Text not found";
		return 1;
	}

	return 0;
}
