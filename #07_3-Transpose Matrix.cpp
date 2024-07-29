#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

void FillMatrixWithOrderdNumbers(int arr[3][3], int Rows, int Cols)
{
	short Counter = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Counter++;

			arr[i][j] = Counter ;

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

void TransposeMatrix(int arr[3][3], int Transposed[3][3], int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{

			Transposed[i][j] = arr[j][i];

		}

	}
}

int main()
{
	//int x[Rows][Cols];
	int arr[3][3];
	int Transposed[3][3];

	FillMatrixWithOrderdNumbers(arr, 3, 3);
	cout << " \n The following is a 3x3 ordered matrix : \n";
	PrintMatrix(arr, 3, 3);

	TransposeMatrix(arr, Transposed, 3, 3);
	cout << "\n\nThe following is the transposed matrix:\n";
	PrintMatrix(Transposed, 3, 3);


	return 0;
}