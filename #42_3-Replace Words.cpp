#include<iostream>
#include<string>
#include<vector>

using namespace std;

string ReadString()
{
	string S1;
	cout << "Please enter your string? ";
	getline(cin, S1);

	return S1;
}

string ReplaceWordInStringUsingBuiltInFunction(string S1, string StringToReplace, string sReplaceTo)
{
	short pos = S1.find(StringToReplace);
	while (pos != std::string::npos)
	{
		S1 = S1.replace(pos, StringToReplace.length(), sReplaceTo);
		pos = S1.find(StringToReplace); //find next

	}

	return S1;
}

int main()
{
	string S1 = "Welcome to Jordan , Jordan is a nice country";
	string StringToReplace = "Jordan";
	string ReplaceTo = "USA"; 
	cout << "\nOrigial String\n" << S1; 
	cout << "\n\nString After Replace:";   
	cout << "\n" << ReplaceWordInStringUsingBuiltInFunction(S1, StringToReplace, ReplaceTo);

	return 0;
	//system("pause>0");
}