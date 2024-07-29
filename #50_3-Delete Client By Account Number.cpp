#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;

const string ClientsFileName = "Clients.txt";

struct stClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};

vector<string> SplitString(string Name, string Delim)
{
	vector<string>Vstring;

	short pos = 0;
	string sWord; // define a string variable 

	// use find() function to get the position of the delimiters  
	while ((pos = Name.find(Delim)) != std::string::npos)
	{
		sWord = Name.substr(0, pos); // store the word   
		if (sWord != "")
		{
			Vstring.push_back(sWord);
		}

		Name.erase(0, pos + Delim.length()); /* erase() until
		 positon and move to next word. */
	}

	if (Name != "")
	{
		Vstring.push_back(Name);
	}

	return Vstring;
}

stClient ConvertLinetoRecord(string Line, string Seperator = "/##/")
{
	stClient Client;
	vector<string> vClientData;

	vClientData = SplitString(Line, Seperator);

	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]); //cast string to double

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

vector<stClient> LoadCleintsDataFromFile(string FileName)
{
	vector<stClient> vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in); // read mode

	if (MyFile.is_open())
	{
		string Line;
		stClient Client;

		while (getline(MyFile, Line))
		{
			Client = ConvertLinetoRecord(Line);
			vClients.push_back(Client);
		}

		MyFile.close();
	} 

	return vClients;
}

void PrintClientRecord(stClient Client)
{
	cout << "\nThe following are the client details:\n";
	cout << "\nAccout Number  : " << Client.AccountNumber;  
	cout << "\nPin Code       : " << Client.PinCode; 
	cout << "\nName           : " << Client.Name;   
	cout << "\nPhone          : " << Client.Phone; 
	cout << "\nAccount Balance: " << Client.AccountBalance;

}

bool FindClientByAccountNumber(string AccountNumber,vector <stClient> vClients, stClient& Client)
{

	for (stClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
		
	}

	return false;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <stClient> &vClients)
{

	for (stClient &C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkForDelete = true;
			return true;

		}
		
	}

	return false;
}

vector<stClient> SaveCleintsDataToFile(string FileName, vector<stClient> vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out); //overwritr
	string DataLine;
	if (MyFile.is_open())
	{
		for (stClient &C : vClients)
		{
			if (C.MarkForDelete == false)
			{
				//we only write records that are not marked for delete.
				DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}

	return vClients;
}

bool DeleteClientByAccountNumber(string AccountNumber, vector<stClient>& vClients)
{
	stClient Client;
	char Answer = 'Y';
	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientRecord(Client);
		cout << "\n\nAre you sure you want delete this client? y/n ? ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
			SaveCleintsDataToFile(ClientsFileName, vClients);

			//Refresh Clients 
			vClients = LoadCleintsDataFromFile(ClientsFileName);

			cout << "\n\nClient Deleted Successfully.";
			return true;
		}
	}
	else
	{
		cout << "\nClient with Account Number ("
			<< AccountNumber << ") is Not Found!"; 
		return false;
	}

}

string ReadAccountNumber()
{
	string AccountNumber = "";
	cout << "Please enter Account Number? ";
	cin >> AccountNumber;
	return AccountNumber;
}

int main()
{
	vector<stClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
	string AccountNumber = ReadAccountNumber();

	DeleteClientByAccountNumber(AccountNumber, vClients);

	return 0;
}