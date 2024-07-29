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

void PrintEachWordInString(string Name)
{
	string delim = " "; // delimite
	cout << "\nYour string wrords are: \n\n";
	short pos = 0;
	string sWord; // define a string variable  

	// use find() function to get the position of the delimiters  
	while ((pos = Name.find(delim)) != std::string::npos)
	{
		sWord = Name.substr(0, pos); // store the word   
		if (sWord !="")
		{
			cout << sWord << endl;
		}
		
		Name.erase(0, pos + delim.length()); /* erase() until
		 positon and move to next word. */
	}

	if (Name !="")
	{
		cout << Name << endl;// it print last word of the string.
	}

	
}

int main()
{
	PrintEachWordInString(ReadString());
	
	return 0;
	//system("pause>0");
}