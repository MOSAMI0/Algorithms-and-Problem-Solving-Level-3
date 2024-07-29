#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

const string ClientsFileName = "Clients.txt";

struct stClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

stClient ReadNewClient()
{
	stClient Client;
	cout << "Enter Account Number: ";

	//Usage of std::ws will extract allthe whitespace character
	getline(cin >> ws, Client.AccountNumber);
	cout << "\nEnter PinCode: ";
	getline(cin, Client.PinCode);
	cout << "\nEnter Name: ";
	getline(cin, Client.Name);
	cout << "\nEnter Phone: ";
	getline(cin, Client.Phone);
	cout << "\nEnter Account Balance: ";
	cin >> Client.AccountBalance;

	return Client;
}

string ConvertRecordToLine(stClient Client, string Seperator = "/##/")
{
	string stClientRecord = "";
	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.Name + Seperator;
	stClientRecord += Client.Phone + Seperator;
	stClientRecord += to_string(Client.AccountBalance);

	return stClientRecord;
}

void AddDataLineToFile(string FileName, string sDataLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{
		MyFile << sDataLine << endl;

		MyFile.close();
	}

}

void AddNewClient()
{
	stClient Client;
	Client = ReadNewClient();
	AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}

void AddClients()
{
	system("cls");
	char AddMore = 'Y';
	do
	{
		system("cls");
		cout << "Add Client: \n";
		AddNewClient();
		cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
		cin >> AddMore;

	} while (toupper(AddMore) == 'Y');

}

int main()
{
	AddClients();

	return 0;
}