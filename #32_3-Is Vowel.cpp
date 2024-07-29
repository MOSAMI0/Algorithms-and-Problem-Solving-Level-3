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

bool IsVowel(char Ch1)
{
	Ch1 = tolower(Ch1);
	return (Ch1 == 'a' || Ch1 == 'e' || Ch1 == 'u' || Ch1 == 'o' || Ch1 == 'i');
}

int main()
{
	char Ch1 = ReadChar();

	if (IsVowel(Ch1))       
		cout << "\nYES Letter \'" << Ch1 << "\' is vowel"; 
	else       
		cout << "\nNO Letter \'" << Ch1 << "\' is NOT vowel";

	return 0;
	//system("pause>0");
}