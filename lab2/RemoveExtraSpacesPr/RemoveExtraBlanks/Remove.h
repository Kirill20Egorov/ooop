#pragma once
#include <string>
#include <iosfwd>

using namespace std;

string RemoveExtraSpaces(const string& arg);

void RemoveSpacesLines(istream& input, ostream& output);
