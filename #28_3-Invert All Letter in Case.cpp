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

char InvertLetterCase(char Name)
{
	return isupper(Name) ? tolower(Name) : toupper(Name);
}

string InvertAllStringLettersCase(string Name)
{
    /*
    	for (int i = 0; i < Name.length(); i++)

           { 
           if (Name[i] == toupper(Name[i]))
        			Name[i] = tolower(Name[i]);
        	else
        			Name[i] = toupper(Name[i]);
               
           }
	*/

	for (int i = 0; i < Name.length(); i++)
	{
		Name[i] = InvertLetterCase(Name[i]);
	}
	return Name;
}

int main()
{
	string S1 = ReadString();
	cout << "\nString after Inverting All Letters Case:\n";
	S1 = InvertAllStringLettersCase(S1);
	cout << S1 << endl;

	return 0;
	//system("pause>0");
}