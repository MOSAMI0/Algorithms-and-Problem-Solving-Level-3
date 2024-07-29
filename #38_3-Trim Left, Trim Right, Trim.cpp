#include<iostream>
#include<string>

using namespace std;

string TrimLeft(string Name)
{
	for (short i = 0; i < Name.length(); i++)
	{
		if (Name[i] != ' ')
		{
			return Name.substr(i, Name.length() - 1);
		}
	}
	return "";
}

string TrimRight(string Name)
{
	for (short i = Name.length() - 1; i >= 0; i--)
	{
		if (Name[i] != ' ')
		{
			return Name.substr(0, i + 1);
		}
	}
	return "";
}

string Trim(string Name)
{
	return TrimLeft(TrimRight(Name));
}

int main()
{
	string S1 = "      Mohammed Al-Ghoraibi      ";
	cout << "\nString     = " << S1; 
	cout << "\n\nTrim Left  = " << TrimLeft(S1);
	cout << "\n\nTrim Right = " << TrimRight(S1);
	cout << "\n\nTrim       = " << Trim(S1);



	return 0;
	//system("pause>0");
}