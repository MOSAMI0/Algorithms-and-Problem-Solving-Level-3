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

void PrintFirstLetterOfEachWord(string Name)
{	
	bool IsFirstLetter = true;
	cout << "\nThe First Letter in each String: \n";

	for (int i = 0; i < Name.length(); i++)
	{
		if (Name[i] != ' ' && IsFirstLetter)
		{
			cout << Name[i] << endl;
		}
		IsFirstLetter = (Name[i] == ' ' ? true : false);

	}
	
}

int main()
{
	PrintFirstLetterOfEachWord(ReadString());
	return 0;
	//system("pause>0");
}