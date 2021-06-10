// bin2dec.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

bool IsBinNumber(const string& stringBin)
{
	int i = 0;
	while (i < stringBin.size())
	{
		if ((stringBin[i] != '0') && (stringBin[i] != '1'))
		{
			return false;
		}
		i++;
	}
	return true;
}

int AddBit(int num, const string& stringBin, int i)
{
	if (stringBin[i] == '1')
	{
	    num |= 1;
	}
	return num;
}

int BinToDec(const string& stringBin)
{
	int num = 0;
	for (int i = 0; i < stringBin.size(); i++)
	{
		if (i != 0)
		{
			num = num << 1;
		}
		num = AddBit(num, stringBin, i);
	}
	return num;
}

int main(int argc, char* argv[])
{
	const int NUM_OF_PARAMS = 2;
	if (argc != NUM_OF_PARAMS)
	{
		cout << "Error: Uncorrect number of arguments" <<
			"Use: findtext.exe <bim num>" << endl;
		return 1;
	}
	string stringBin = argv[1];
	if (IsBinNumber(stringBin))
	{
		cout << BinToDec(stringBin);
	}
	else
	{
		cout << "It doesn't bin num";
	}
}

