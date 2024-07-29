#include<iostream>
#include<string>
using namespace std;

string ReadString()
{
	string S1;
	cout << "Please enter your string? ";
	getline(cin, S1);

	return S1;
}

char ReadChar()
{
	char Ch1;
	cout << "Please enter your Character? ";
	cin >> Ch1;

	return Ch1;
}

short CountLetters(string Name, char letter)
{
	int Counter = 0;
	for (int i = 0; i < Name.length(); i++)
	{
		if (Name[i] == letter)
		{
			Counter++;
		}
		
	}
	return Counter;
}

int main()
{
	
	string S1 = ReadString();
	char Ch1 = ReadChar();
	cout << S1 << endl;
	cout << "\nLetter \'" << Ch1 << "\' Count = " << CountLetters(S1, Ch1);

	return 0;
	//system("pause>0");
}