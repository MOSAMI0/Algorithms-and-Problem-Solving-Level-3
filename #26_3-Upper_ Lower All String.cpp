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

string UpperAllString(string Name)
{	

	for (int i = 0; i < Name.length(); i++)
	{
		if (Name[i] != ' ')
		{
			Name[i] = toupper(Name[i]);
		}
	}
	return Name;
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

int main()
{
	string S1 = ReadString();
	cout << "\nString after Upper : \n\n";
	S1 = UpperAllString(S1);
	cout << S1 << endl;

	cout << "\nString after Lower : \n\n";
	S1 = LowerAllString(S1);
	cout << S1 << endl;

	return 0;
	//system("pause>0");
}