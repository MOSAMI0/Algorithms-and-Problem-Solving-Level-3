#include<iostream>
#include<string>
using namespace std;

enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 2 };

string ReadString()
{
	string S1;
	cout << "Please enter your string? ";
	getline(cin, S1);

	return S1;
}

short CountLetters(string Name, enWhatToCount WhatToCount = enWhatToCount::All)
{
	if (WhatToCount == enWhatToCount::All)
	{
		return Name.length();
	}

	int Counter = 0;

	for (int i = 0; i < Name.length(); i++)
	{
		if (WhatToCount == enWhatToCount::CapitalLetters && isupper(Name[i]))
		{
			Counter++;
		}
		else if(WhatToCount == enWhatToCount::SmallLetters && islower(Name[i]))
		{
			Counter++;
		}
		
	}
	return Counter;

}

short CountCapitalLetters(string Name)
{
	int Counter = 0;
	for (int i = 0; i < Name.length(); i++)
	{
		if (isupper(Name[i]))
		{
			Counter++;
		}
		
		
	}
	return Counter;
}

short CountSmallLetters(string Name)
{
	int Counter = 0;
	for (int i = 0; i < Name.length(); i++)
	{
		if (islower(Name[i]))
		{
			Counter++;
		}
		
	}
	return Counter;
}

int main()
{
	string S1 = ReadString();
	cout << "\nMethod 1\n";
	cout << "\nString Length: " << S1.length() << endl;

	cout << "Capital Letters Count= " 
		<< CountCapitalLetters(S1);

	cout << "\nSmall Letters Count= "
		<< CountSmallLetters(S1);

	cout << "\n\nMethod 2\n";  
	cout << "\nString Length = " << CountLetters(S1);
	cout << "\nCapital Letters Count= "
		<< CountLetters(S1, enWhatToCount::CapitalLetters);
	cout << "\nSmall Letters Count= "
		<< CountLetters(S1, enWhatToCount::SmallLetters);

	return 0;
	//system("pause>0");
}