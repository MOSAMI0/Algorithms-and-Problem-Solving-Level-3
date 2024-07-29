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

bool FindClientByAccountNumber(string AccountNumber, stClient& Client)
{
	vector <stClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

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

string ReadAccountNumber()
{
	string AccountNumber = "";
	cout << "Please enter Account Number? ";
	cin >> AccountNumber;
	return AccountNumber;
}

int main()
{
	stClient Client;
	string AccountNumber = ReadAccountNumber();

	if (FindClientByAccountNumber(AccountNumber, Client))
	{
		PrintClientRecord(Client);
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
	}
	return 0;
}