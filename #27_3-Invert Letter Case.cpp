#include<iostream>
#include<string>
using namespace std;

char ReadChar()
{
	char Ch1;
	cout << "Please enter your Character? ";
	cin >> Ch1;

	return Ch1;
}

char InvertLetterCase(char Name)
{	
		/*if (Name  == tolower(Name))

			Name = toupper(Name);
		else

			Name = tolower(Name);*/

	return isupper(Name) ? tolower(Name) : toupper(Name);
}

int main()
{
	char S1 = ReadChar();
	cout << "\nChar after inverting case:\n"; 
	S1 = InvertLetterCase(S1);
	cout << S1 << endl;


	return 0;
	//system("pause>0");
}