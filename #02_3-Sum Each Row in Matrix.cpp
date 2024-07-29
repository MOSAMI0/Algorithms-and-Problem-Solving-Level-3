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

void FillMatrixWithRandomNUmbers(int arr[3][3], int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNUmber(1, 100);

		}

	}

}

void PrintMatrix(int arr[3][3], int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "    ";
		}
		cout << endl;
	}
}

int RowSum(int arr[3][3], int RowNumber, int Cols)
{
	int Sum = 0;
	for (int j = 0; j <= Cols -1; j++)
	{
		Sum += arr[RowNumber][j];
	}

	return Sum;
}

void PrintMatrixEachRow(int arr[3][3], int Rows, int Cols)
{
	cout << "\nThe following are the sum of each row in the matrix:\n";

	for (short i = 0 ; i < Rows ; i++)
	{
		cout << "Row " << i + 1 << " Sum = " << RowSum(arr, i, Cols) << endl;
	}

}
	
int main()
{
	//Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	//int x[Rows][Cols];
	int arr[3][3];

	FillMatrixWithRandomNUmbers(arr, 3, 3);
	cout << " \n The following is a 3x3 random matrix : \n";
	PrintMatrix(arr, 3, 3);

	PrintMatrixEachRow(arr, 3, 3);

	return 0;
}