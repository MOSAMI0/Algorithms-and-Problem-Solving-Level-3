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

bool IsScalarMarix(int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			int FirstDiagElemement = Matrix[0][0];

			//check for diagonals element
			if ( i == j and Matrix[i][j] != FirstDiagElemement)
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
	int Matrix1[3][3] = {{9, 0, 0}, {0, 9, 0}, {0, 0, 9}};

	cout << "Matrix:\n";
	PrintMatrix(Matrix1, 3, 3);

	if (IsScalarMarix(Matrix1, 3, 3))
		cout << "\nYes: matrix is scalar...\n";
	else
		cout << "\nNo: matrix is Not scalar...\n";

	system("pause>0");
}