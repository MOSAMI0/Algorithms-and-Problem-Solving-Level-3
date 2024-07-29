#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

void PrintMatrix(int arr[3][3], int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			//printf("%0*d ", 2, arr[i][j]);
			cout<< setw(3) << arr[i][j] << "     ";

		}
		cout << endl;
	}

}

bool IsIdentityMarix(int Matrix[3][3], short Rows, short Cols)
{
	//check Diagonal elements are 1 and rest elements are 0
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			//check for diagonals element
			if ( i == j and Matrix[i][j] !=1)
			{
				return false;
			}
			//check for rest elements
			else if( i != j and Matrix[i][j] !=0)
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	//int Matrix[Rows][Cols];
	int Matrix1[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

	cout << "Matrix:\n";
	PrintMatrix(Matrix1, 3, 3);

	if (IsIdentityMarix(Matrix1, 3, 3))
		cout << "\nYes: matrix is Identity...\n";
	else
		cout << "\nNo: matrix is Not Identity...\n";

	system("pause>0");
}