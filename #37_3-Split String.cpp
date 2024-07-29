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
		if (sWord !="")
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


int main()
{
	vector<string>Vstring;
	Vstring = SplitString(ReadString(), " ");

	cout << "\nTokens = " << Vstring.size() << endl;
	for (string &st : Vstring)
	{
		cout << st << endl;
	}

	return 0;
	//system("pause>0");
}