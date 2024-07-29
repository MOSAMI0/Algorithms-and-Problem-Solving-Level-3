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
int main()
{
	//int x[Rows][Cols];
	int x[3][3];

	FillMatrixWithOrderdNumbers(x, 3, 3);
	cout << " \n The following is a 3x3 ordered matrix : \n";
	PrintMatrix(x, 3, 3);

	return 0;
}