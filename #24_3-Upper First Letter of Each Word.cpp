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

string UpperFirstLetterOfEachWord(string Name)
{	
	bool IsFirstLetter = true;

	for (int i = 0; i < Name.length(); i++)
	{
		if (Name[i] != ' ' && IsFirstLetter)
		{
			Name[i] = toupper(Name[i]);
		}
		IsFirstLetter = (Name[i] == ' ' ? true : false);

	}
	return Name;
}

int main()
{
	string S1 = ReadString();
	cout << "\nString After conversion: \n";

	S1 = UpperFirstLetterOfEachWord(S1);
	cout << S1 << endl;

	return 0;
	//system("pause>0");
}