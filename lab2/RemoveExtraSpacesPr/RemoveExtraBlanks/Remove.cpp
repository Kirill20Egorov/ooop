#include "Remove.h"
#include <string>
#include <iostream>

using namespace std;
//варнинги, пробелы в конце, арг
string RemoveExtraSpaces(const string& line)
{
    string processedString;
    bool isFoundWord = false;
    for (unsigned int i = 0; i < line.size(); i++)
    {
        if (line[i] != ' ')
        {
            if ((!isFoundWord) && (processedString.size() > 0))
            {
                processedString += ' ';
            }
            processedString += line[i];
            isFoundWord = true;
        }
        else
        {
            isFoundWord = false;
        }
    }
    return processedString;
}

void RemoveSpacesLines(istream& input, ostream& output)
{    
    string line;
    while (getline(input, line))
    {
        output << RemoveExtraSpaces(line) << endl;
    }
}
