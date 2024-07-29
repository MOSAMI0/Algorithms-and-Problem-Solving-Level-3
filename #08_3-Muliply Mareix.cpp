#include<iostream>
using namespace std;

int RandomNUmber(int From, int To)
{
	// Function to generate randon numbers 
	int randNum = rand() % (To - From + 1) + From;

	return randNum;

}

void FillMatrixWithRandomNumbers(int arr1[3][3], int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			arr1[i][j] = RandomNUmber(1, 10);
		}

	}

}

void PrintMatrix(int arr[3][3], int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			printf("%0*d ", 2, arr[i][j]);

		}
		cout << endl;
	}

}

void MuliplyMatrix(int arr1[3][3], int arr2[3][3], int Result[3][3], int Rows, int Cols)
{
	
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Result[i][j] = arr1[i][j] * arr2[i][j];
		}
		
	}
}

int main()
{
	//Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	//int Matrix[Rows][Cols];
	int Matrix1[3][3], Matrix2[3][3], MatrixResult[3][3];
	

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "Matrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	cout << "\nMatrix2:\n";
	PrintMatrix(Matrix2, 3, 3);

	MuliplyMatrix(Matrix1, Matrix2, MatrixResult, 3, 3);
	cout << "\nResult:\n";
	PrintMatrix(MatrixResult, 3, 3);

	return 0;
}