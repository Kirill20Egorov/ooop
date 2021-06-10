#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <array> 

using namespace std;

void FillMatrix(ifstream& matrixFile, float matrix[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrixFile >> matrix[i][j];
		}
	}
}

void MultiplyMatrix(float matrix1[3][3], float matrix2[3][3], float result[3][3])
{
	for (int row = 0; row < 3; row++) 
	{
		for (int col = 0; col < 3; col++) 
		{
			result[row][col] = 0;
			for (int current = 0; current < 3; current++) 
			{
				result[row][col] += matrix1[row][current] * matrix2[current][col];
			}
		}
	}
	return result[3][3];
}
int main(int argc, char* argv[])
{
	const int NUM_OF_PARAMS = 3;
	float matrix1[3][3], matrix2[3][3];
	float result[3][3];
	if (argc != NUM_OF_PARAMS)
	{
		cout << "Error: Uncorrect number of arguments" <<
			"Use: multmatrix.exe <matrixFile1 file> <matrixFile2 file>" << endl;
		return 1;
	}

	ifstream matrixFile1;
	matrixFile1.open(argv[1]);
	if (!matrixFile1.is_open())
	{
		cout << "Error: Couldn't open " << argv[1] << " for reading";
		return 1;
	}
	FillMatrix(matrixFile1, matrix1);
	ifstream matrixFile2;
	matrixFile2.open(argv[2]);
	if (!matrixFile2.is_open())
	{
		cout << "Error: Couldn't open " << argv[2] << " for reading";
		return 1;
	}
	FillMatrix(matrixFile2, matrix2);
	MultiplyMatrix(matrix1, matrix2, result);
	return 0;
}
