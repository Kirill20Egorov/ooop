#include "Remove.h"
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cout << "Uncorrect count of params";
        return 1;
    }
    ifstream input;
    input.open(argv[1]);
    RemoveSpacesLines(input, cout);
    return 0;
}
