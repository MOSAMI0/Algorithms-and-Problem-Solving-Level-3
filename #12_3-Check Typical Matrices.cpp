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

int SumOfMatrix(int arr[3][3], int Rows, int Cols)
{
	int Sum = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Sum += arr[i][j];
		}
	}
	return Sum;
}

bool CheckMatrixAreTypical(int Matrix1[3][3], int Matrix2[3][3], int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] != Matrix2[i][j])
			{
				return false;
			}
			
		}
	}
	return true;
}

int main()
{
	//Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	//int Matrix[Rows][Cols];
	int Matrix1[3][3], Matrix2[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "Matrix:\n";
	PrintMatrix(Matrix1, 3, 3);

	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	cout << "\nMatrix2:\n";
	PrintMatrix(Matrix2, 3, 3);

	if (CheckMatrixAreTypical(Matrix1, Matrix2, 3, 3))
		cout << "\nboth: martices are typical...\n";
	else
		cout << "\nNo: martices are not typical...\n";

	return 0;
}