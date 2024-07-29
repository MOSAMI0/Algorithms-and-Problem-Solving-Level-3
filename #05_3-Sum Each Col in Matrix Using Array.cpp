#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int RandomNUmber(int From, int To)
{
	// Function to generate randon numbers 
	int randNum = rand() % (To - From + 1) + From;

	return randNum;

}

void FillMatrixWithRandomNUmbers(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNUmber(1, 100);

		}

	}

}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "    ";
		}
		cout << endl;
	}
}

int ColumnSum(int arr[3][3], short Rows, short ColNumber)
{
	int Sum = 0;
	for (short j = 0; j <= Rows - 1; j++)
	{
		Sum += arr[j][ColNumber];
	}

	return Sum;
}

void SumMatrixColumnInArray(int arr[3][3], int ColumnRow[3], short Rows, short Cols)
{

	for (short i = 0; i < Cols; i++)
	{
		ColumnRow[i] = ColumnSum(arr, Rows, i);
	}

}

void PrintMatrixSumInArray(int arr[3], short Columns)
{
	cout << "\nThe following are the sum of each column in the matrix:\n";
	for (short i = 0; i < Columns; i++)
	{
		cout << "Column " << i + 1 << " Sum = " << arr[i] << endl;
	}

}

int main()
{
	//Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	//int x[Rows][Cols];
	int arr[3][3];
	int arrSum[3];

	FillMatrixWithRandomNUmbers(arr, 3, 3);
	cout << " \n The following is a 3x3 random matrix : \n";
	PrintMatrix(arr, 3, 3);

	SumMatrixColumnInArray(arr, arrSum, 3, 3);
	PrintMatrixSumInArray(arrSum, 3);

	return 0;
}