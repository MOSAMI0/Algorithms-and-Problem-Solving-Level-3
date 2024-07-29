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
			cout << setw(3) << arr[i][j] << "     ";

		}
		cout << endl;
	}

}

bool IsNumberInMatrix(int Matrix[3][3], int Number, short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] == Number)
			{
				return true;
			}
			
		}
	}

	return false;
}

void PrintIntersectedNumbers(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	int Number;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Number = Matrix1[i][j];
			if (IsNumberInMatrix(Matrix2, Number, 3, 3))
			{
				cout << setw(3) << Number << "     ";
			}
		}
	}
}

int main()
{
	int Matrix1[3][3] = { {77,5,12},{22,20,1},{1,0,9} }; 
	int Matrix2[3][3] = { {5,80,90},{22,77,1},{10,8,33} };

	cout << "Matrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "Matrix2:\n";
	PrintMatrix(Matrix2, 3, 3);

	cout << "\nIntersected Numbers are: \n\n";   
	PrintIntersectedNumbers(Matrix1, Matrix2, 3, 3);

	return 0;
	//system("pause>0");
}