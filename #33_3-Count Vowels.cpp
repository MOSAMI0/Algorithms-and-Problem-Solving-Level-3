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

bool IsVowel(char Ch1)
{
	Ch1 = tolower(Ch1);
	return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'u') || (Ch1 == 'o') || (Ch1 == 'i'));
}

short CountVowels(string Name)
{
	short Counter = 0;
	for (int i = 0; i < Name.length(); i++)
	{
		if (IsVowel(Name[i]))
		{
			Counter++;
		}
	}

	return Counter;
}

int main()
{
	string S1 = ReadString();

	cout << "\nNumber of vowels is: " << CountVowels(S1) << endl;
	
	return 0;
	//system("pause>0");
}