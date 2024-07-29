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

string ReverseWordsInString(string S1)
{
	vector<string> Vstring;
	string S2 = "";

	Vstring = SplitString(S1, " ");

	//declare iterator
	vector<string>::iterator itr = Vstring.end();
	while (itr != Vstring.begin())
	{
		itr--;

		S2 += *itr + " ";
	}
	S2 = S2.substr(0, S2.length() - 1); //remove last space.

	return S2;
}

int main()
{
	string S1 = ReadString();
	cout << S1 << endl;
	cout << ReverseWordsInString(S1);
	
	return 0;
	//system("pause>0");
}