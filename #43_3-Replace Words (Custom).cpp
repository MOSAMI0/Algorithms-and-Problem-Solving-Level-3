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

vector <string> SplitString(string Name, string Delim)
{
	vector<string>Vstring;

	short pos = 0;
	string sWord; // define a string variable 

	// use find() function to get the position of the delimiters  
	while ((pos = Name.find(Delim)) != std::string::npos)
	{
		sWord = Name.substr(0, pos); // store the word   
		if (sWord != "")
		{
			Vstring.push_back(sWord);
		}

		Name.erase(0, pos + Delim.length()); /* erase() until
		 positon and move to next word. */
	}

	if (Name != "")
	{
		Vstring.push_back(Name);

	}

	return Vstring;
}

string JoinString(vector<string> vString, string Delim)
{
	string S1 = "";
	for (string& s : vString)
	{
		S1 = S1 + s + Delim;
	}

	return S1.substr(0, S1.length() - Delim.length());
}

string LowerAllString(string Name)
{

	for (int i = 0; i < Name.length(); i++)
	{
		if (Name[i] != ' ')
		{
			Name[i] = tolower(Name[i]);
		}
	}
	return Name;
}

string ReplaceWordInStringUsingSplit(string S1, string StringToReplace, string sReplaceTo, bool MarchCase = true)
{
	vector<string> Vstring = SplitString(S1, " ");

	for (string &s : Vstring )
	{
		if (MarchCase)
		{
			if (s == StringToReplace)
			{
				s = sReplaceTo;
			}
		}
		else
		{
			if (LowerAllString(s) == LowerAllString(StringToReplace))
			{
				s = sReplaceTo;
			}
			
		}
	}

	return JoinString(Vstring, " ");
}


int main()
{
	string S1 = "Welcome to Jordan , Jordan is a nice country";
	string StringToReplace = "jordan";
	string ReplaceTo = "USA"; 
	cout << "\nOrigial String\n" << S1; 

	cout << "\n\nReplace with match case: ";
	cout << "\n" << ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo);
	cout << "\n\nReplace with dont match case: ";
	cout << "\n" << ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo, false) << endl;


	return 0;
	//system("pause>0");
}