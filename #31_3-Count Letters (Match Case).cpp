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
	cout << "\nPlease enter your Character? ";
	cin >> Ch1;

	return Ch1;
}

char InvertLetterCase(char Name)
{
	return isupper(Name) ? tolower(Name) : toupper(Name);
}

short CountLetters(string Name, char letter, bool MatchCase = true)
{
	int Counter = 0;
	for (int i = 0; i < Name.length(); i++)
	{
		if (MatchCase)
		{
			if (Name[i] == letter)
			{
				Counter++;
			}
		}
		else
		{
			if (tolower(Name[i]) == tolower(letter))
			{
				Counter++;
			}

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

	cout << "\nLetter \'" << Ch1 << "\' ";     
	cout << "Or \'" << InvertLetterCase(Ch1) << "\' ";    
	cout << " Count = " << CountLetters(S1, Ch1, false);

	return 0;
	//system("pause>0");
}