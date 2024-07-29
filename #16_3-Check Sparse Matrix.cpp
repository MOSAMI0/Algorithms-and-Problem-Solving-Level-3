#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>

using namespace std;

void PrintMatrix(int arr[3][3], int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			//printf("%0*d ", 2, arr[i][j]);
			cout << setw(3) << arr[i][j] << "     ";

		}
		cout << endl;
	}

}

short CountNumberInMatrix(int Matrix[3][3], short Number, short Rows, short Cols)
{
	int Counter = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] == Number)
			{
				Counter++;
			}
		}
	}

	return Counter;
}

bool IsSparseMatrix(int Matrix[3][3], short Rows, short Cols)
{
	short MatrixSize = Rows * Cols;

	return(CountNumberInMatrix(Matrix, 0, 3, 3) >= ceil((float)MatrixSize / 2));
}

int main()
{
	int Matrix1[3][3] = { {0,0,12},{9,9,1},{0,0,9} };

	cout << "Matrix:\n";
	PrintMatrix(Matrix1, 3, 3);

	if (IsSparseMatrix(Matrix1, 3, 3))
		cout << "\nYes: It is Sparse\n";
	else   
		cout << "\nNo: It's NOT Sparse\n";  

	//system("pause>0");
	return 0;
}