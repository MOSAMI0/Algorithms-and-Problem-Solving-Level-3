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

short CountWords(string Name)
{
	string delim = " "; // delimite
	short pos = 0;
	string sWord; // define a string variable 
	short Counter = 0;

	// use find() function to get the position of the delimiters  
	while ((pos = Name.find(delim)) != std::string::npos)
	{
		sWord = Name.substr(0, pos); // store the word   
		if (sWord !="")
		{
			Counter++;
		}
		
		Name.erase(0, pos + delim.length()); /* erase() until
		 positon and move to next word. */
	}

	if (Name != "")
	{
		Counter++;
	}

	return Counter;
}


int main()
{
	string S1 = ReadString();
	
	cout << "\nThe number of words in your string is: "; 
	cout << CountWords(S1);

	return 0;
	//system("pause>0");
}