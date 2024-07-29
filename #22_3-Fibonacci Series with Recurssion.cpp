#include<iostream>
using namespace std;

int PrintFibonacciUsingRecurssion(short Number, short Prev1, short Prev2)
{	
	int FebNumber = 0;

	if (Number > 0)
	{
		FebNumber = Prev2 + Prev1;
		Prev2 = Prev1;
		Prev1 = FebNumber;
		cout << FebNumber << "   ";

		return(PrintFibonacciUsingRecurssion(Number - 1, Prev1, Prev2));

	}

}

int main()
{
	PrintFibonacciUsingRecurssion(10, 0, 1);

	return 0;
	//system("pause>0");
}