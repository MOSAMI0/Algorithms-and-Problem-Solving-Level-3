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

int main()
{
	int Matrix1[3][3] = { {77,5,12},{22,20,1},{1,0,9} };

	cout << "Matrix:\n";
	PrintMatrix(Matrix1, 3, 3);

	int Number; 
	cout << "\nPlease Enter the number to look for in matrix? ";  
	cin >> Number;

	//Using Count is a slower method 
	if (IsNumberInMatrix(Matrix1, Number, 3, 3) >0)
		cout << "\nYes it is there.\n";
	else
		cout << "\nNo: It's NOT there.\n";

	//This is faster mthod
	if (IsNumberInMatrix(Matrix1, Number, 3, 3))  
		cout << "\nYes it is there.\n";
	else         
		cout << "\nNo: It's NOT there.\n";



	return 0;
	//system("pause>0");
}