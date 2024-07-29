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

void PrintMiddleRowOfMatrix(int arr[3][3], int Rows, int Cols)
{
	short MiddleRows = Rows / 2;
	for (short j = 0; j < Cols; j++)
	{
		printf("%0*d ", 2, arr[MiddleRows][j]);
	}
	cout << endl;
}

void PrintMiddleColOfMatrix(int arr[3][3], int Rows, int Cols)
{
	short MiddleCols = Cols / 2;
	for (short i = 0; i < Rows; i++)
	{
		printf("%0*d ", 2, arr[i][MiddleCols]);
	}
	cout << endl;
}

int main()
{
	//Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	//int Matrix[Rows][Cols];
	int Matrix[3][3];	

	FillMatrixWithRandomNumbers(Matrix, 3, 3);
	cout << "Matrix1:\n";
	PrintMatrix(Matrix, 3, 3);

	cout << "\nMiddle Row of Matrix1 is:\n";
	PrintMiddleRowOfMatrix(Matrix, 3, 3);

	cout << "\nMiddle Col of Matrix1 is:\n";
	PrintMiddleColOfMatrix(Matrix, 3, 3);

	return 0;
}