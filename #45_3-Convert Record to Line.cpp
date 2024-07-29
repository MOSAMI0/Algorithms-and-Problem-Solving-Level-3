#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct stClient 
{
	string AccountNum;
	string PinCode;
	string FullName;
	string Phone;
	double AccountBalance;
};

stClient ReadData()
{
	stClient Client;
	cout << "Enter Account Number: ";
	getline(cin, Client.AccountNum);
	cout << "\nEnter PinCode: ";
	getline(cin, Client.PinCode);
	cout << "\nEnter Name: ";
	getline(cin, Client.FullName);
	cout << "\nEnter Phone: ";
	getline(cin, Client.Phone);
	cout << "\nEnter Account Balance: ";
	cin >> Client.AccountBalance;

	return Client;
}

string ConvertRecordToLine(stClient Client, string Seperator = "/##/")
{
	string stClientRecord = "";
	stClientRecord += Client.AccountNum + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.FullName + Seperator;
	stClientRecord += Client.Phone + Seperator;
	stClientRecord += to_string(Client.AccountBalance);

	return stClientRecord;
}

int main()
{
	cout << "\nPlease Enter Client Data: \n\n";
	stClient Clint;
	Clint = ReadData();

	cout << "\n\nClient Record for Saving is: \n";
	cout << ConvertRecordToLine(Clint);

	return 0;
	//system("pause>0");
}