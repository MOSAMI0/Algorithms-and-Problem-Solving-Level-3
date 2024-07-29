#include<iostream>
#include<string>
#include<vector>

using namespace std;

string JoinString(vector<string> vString, string Delim)
{
	string S1 = "";
	for (string &s : vString)
	{
		S1 = S1 + s + Delim;
	}

	return S1.substr(0, S1.length()-Delim.length());
}

string JoinString(string arrS[], short length, string Delim)
{
	string S1 = "";
	for (short i = 0; i < length; i++)
	{
		S1 = S1 + arrS[i] + Delim;
	}

	return S1.substr(0, S1.length() - Delim.length());
}

int main()
{
	string arrS[4] = { "Mohammed","Faid","Ali","Maher" };
	vector<string> vString = { "Mohammed","Faid","Ali","Maher" };   

	cout << "\nVector after join: \n";  
	cout << JoinString(vString, " ");  

	cout << "\n\nArray after join: \n";
	cout << JoinString(arrS,4, " ");

	return 0;
	//system("pause>0");
}