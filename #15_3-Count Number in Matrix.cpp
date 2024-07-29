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

short CountNumberInMatrix(int Matrix[3][3], short Number, short Rows, short Cols)
{
	short Counter = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] == Number)
				Counter++;
			
		}
	}

	return Counter;
}

int main()
{
	int Matrix1[3][3] = { {9,1,12},{0,9,1},{0,9,9} };

	cout << "Matrix:\n";
	PrintMatrix(Matrix1, 3, 3);

	int Number; 
	cout << "\nEnter the number to count in matrix? "; 
	cin >> Number;

	cout << "\nNumber " << Number << " count in matrix is "
		<< CountNumberInMatrix(Matrix1, Number, 3, 3);

	return 0;
}