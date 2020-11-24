// This program using the Vigenere Cyphere model to encrypt and decript text entered by the user.
// Alphabetic characters are encrypted/decrypted while numbers retain numberic value throughout
// Key used for encryption/decryption must be of equal length to the message



#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;



//global variables
string referenceTable = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ."; // baseline for available characters in message and key
string referenceTable1 = "abcdefghijklmnopqrstuvwxyz"; // used for actual encryption/decryption algorithms
string referenceTable2 = "0123456789 ."; // used to filter out numbers, spaces, and periods from algorithms
int choice; // user entered: determines if user wants to encrypt or decrypt
bool validChoiceBool; //used for choice validation
int loopCounter; // used for debugging indexing



// function declarations
string generateKey(int messageLength, string keyWord);
string validMessageEntry();
string validKeyEntry();
string encrypt(string message, string key);
string decrypt(string message, string key);
void validChoice();
string capitalConverter(string message);



int main()
{
	//local variables
	string message; //user entered: message to be either encrypted or decrypted
	string keyWord; //user entered: private keyword used to encrypt/decrypt message
	string key; //determined by program: sets length of keyword equal to message
	string cipher; //encrypted message
	string decipher; //decrypted message
	bool repeatProgram; //used for repeating entire program

	cout << "Use only letters, numbers, periods, or spaces for the message.\n";
	cout << "Do not use any other symbols or forms of punctuation.\n";
	cout << "Keys must use ONLY letters. No spaces, numbers, symbols, or punctuation.\n\n";
	do
	{
		cout << "Do you wish to encrypt or decrypt? (Type '1' for encrypt and '2' for decrypt)\n";
		validChoice();

		// Encryption condition
		if (choice == 1)
		{
			cout << "First, type a message to encrypt.\n";
			// checks if user entered message is valid
			message = validMessageEntry();
			message = capitalConverter(message);

			cout << "Next, choose a keyword. Your keyword must have no spaces, no numbers, no punctuation, and be lowercase.\n";
			//checks for valid keyword input
			keyWord = validKeyEntry();
			keyWord = capitalConverter(keyWord);

			//generates valid key from user-given keyword
			key = generateKey(message.size(), keyWord);

			//generates cypher text from message and key
			cipher = encrypt(message, key);

			cout << "Your enrypted message is:\n";
			cout << cipher << "\n";
		}
		// Decryption condition
		else if (choice == 2)
		{
			cout << "First, type a message to decrypt.\n";
			//checks for valid message input
			cipher = validMessageEntry();

			cout << "Next, provide the keyword.\n";
			//checks for valid keyword input
			keyWord = validKeyEntry();

			//generates valid key from user-given keyword
			key = generateKey(cipher.size(), keyWord);

			//generates cypher text from message and key
			decipher = decrypt(cipher, key);

			cout << "Your derypted message is:\n";
			cout << decipher << "\n";
		}

		// Asks user if they wish to encrypt/decrypt something else
		cout << "Do you wish to do something else? (Type '1' for yes and '2' for no)\n";
		validChoice();

		if (choice == 1)
		{
			repeatProgram = true;
		}
		else if (choice == 2)
		{
			repeatProgram = false;
		}
	} while (repeatProgram == true);
}



void validChoice()
{
	// Checks choice of user
	// If valid choice, continues program normally
	// If invalid choice, repeats until valid choice is entered
	do
	{
		validChoiceBool = true;
		cin >> choice;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Invalid. Choose only '1' or '2'\n";
			cin >> choice;
			validChoiceBool = false;
		}
		if (choice == 1 || choice == 2)
		{
			validChoiceBool = true;
		}
		else
		{
			cout << "Invalid. Choose only '1' or '2'\n";
			validChoiceBool = false;
		}
	} while (validChoiceBool == false);
}



string validMessageEntry()
{
	string input;
	bool validInput;
	do
	{
		cout << "Enter text here:\n";
		cin.ignore();
		getline(cin, input);
		for (int i = 0; i < input.size(); i++)
		{
			validInput = false;
			for (int j = 0; j < referenceTable.size(); j++)
			{
				if (input[i] == referenceTable[j])
				{
					validInput = true;
					break;
				}
			}
			if (validInput == false)
			{
				cout << "Invalid input. Use only letters or numbers.\n";
				break;
			}
		}
	} while (validInput == false);

	return input;
}



string validKeyEntry()
{
	string input;
	bool validInput;
	do
	{
		cout << "Enter text here:\n";
		cin.ignore();
		getline(cin, input);
		for (int i = 0; i < input.size(); i++)
		{
			validInput = false;
			for (int j = 0; j < 26; j++)
			{
				if (input[i] == referenceTable1[j])
				{
					validInput = true;
					break;
				}
			}
			if (validInput == false)
			{
				cout << "Invalid input. Use only letters or numbers.\n";
				break;
			}
		}
	} while (validInput == false);

	return input;
}



string capitalConverter(string message)
{
	// Converts capital letters into lowercase letters
	for (int i = 0; i < message.size(); i++)
	{
		if (message[i] == 'A')
		{
			message[i] = 'a';
		}
		else if (message[i] == 'B')
		{
			message[i] = 'b';
		}
		else if (message[i] == 'C')
		{
			message[i] = 'c';
		}
		else if (message[i] == 'D')
		{
			message[i] = 'd';
		}
		else if (message[i] == 'E')
		{
			message[i] = 'e';
		}
		else if (message[i] == 'F')
		{
			message[i] = 'f';
		}
		else if (message[i] == 'G')
		{
			message[i] = 'g';
		}
		else if (message[i] == 'H')
		{
			message[i] = 'h';
		}
		else if (message[i] == 'I')
		{
			message[i] = 'i';
		}
		else if (message[i] == 'J')
		{
			message[i] = 'j';
		}
		else if (message[i] == 'K')
		{
			message[i] = 'k';
		}
		else if (message[i] == 'L')
		{
			message[i] = 'l';
		}
		else if (message[i] == 'M')
		{
			message[i] = 'm';
		}
		else if (message[i] == 'N')
		{
			message[i] = 'n';
		}
		else if (message[i] == 'O')
		{
			message[i] = 'o';
		}
		else if (message[i] == 'P')
		{
			message[i] = 'p';
		}
		else if (message[i] == 'Q')
		{
			message[i] = 'q';
		}
		else if (message[i] == 'R')
		{
			message[i] = 'r';
		}
		else if (message[i] == 'S')
		{
			message[i] = 's';
		}
		else if (message[i] == 'T')
		{
			message[i] = 't';
		}
		else if (message[i] == 'U')
		{
			message[i] = 'u';
		}
		else if (message[i] == 'V')
		{
			message[i] = 'v';
		}
		else if (message[i] == 'W')
		{
			message[i] = 'w';
		}
		else if (message[i] == 'X')
		{
			message[i] = 'x';
		}
		else if (message[i] == 'Y')
		{
			message[i] = 'y';
		}
		else if (message[i] == 'Z')
		{
			message[i] = 'z';
		}
	}
	return message;
}



string generateKey(int messageLength, string keyWord)
{
	string key;

	//checks if keyWord is same length as message
	//if it is, returns key as is
	if (keyWord.size() == messageLength)
	{
		return keyWord;
	}

	//checks if keyWord is longer than message
	//if it is, drops extra letters to ensure key is same length as message
	if (keyWord.size() > messageLength)
	{
		for (int i = 0; i < messageLength; i++)
		{
			key.push_back(keyWord[i]);
		}
		return key;
	}

	key = keyWord;
	//if keyWord is shorter than message, repeats keyWord until they're the same length
	for (int i = 0; key.size() < messageLength; i++)
	{
		//takes into account short keywords (not recommended)
		//causes index to reset to beginning of keyWord
		if (i == keyWord.size())
		{
			i = 0;
		}
		key.push_back(keyWord[i]);
	}

	return key;
}



string encrypt(string message, string key)
{
	string cipher;
	int messageIndex;
	int keyIndex;
	int cipherIndex;

	for (int i = 0; i < message.size(); i++)
	{
		if (message[i] == '0' || message[i] == '1' || message[i] == '2' || message[i] == '3' || message[i] == '4' ||
			message[i] == '5' || message[i] == '6' || message[i] == '7' || message[i] == '8' || message[i] == '9' ||
			message[i] == ' ' || message[i] == '.')
		{
			cipher.push_back(message[i]);
		}
		else
		{
			//saves index position in reference table of current letter in message
			for (int j = 0; j < 26; j++)
			{
				if (message[i] == referenceTable1[j])
				{
					messageIndex = j;
					break;
				}
			}
			//save index position in reference table of current letter in key
			for (int j = 0; j < 26; j++)
			{
				if (key[i] == referenceTable1[j])
				{
					keyIndex = j;
					break;
				}
			}
			cipherIndex = ((messageIndex + keyIndex) % 26);
			cipher.push_back(referenceTable1[cipherIndex]);
		}
	}

	return cipher;
}



string decrypt(string cipher, string key)
{
	string message;
	int messageIndex;
	int keyIndex;
	int cipherIndex;

	for (int i = 0; i < cipher.size(); i++)
	{
		if (cipher[i] == '0' || cipher[i] == '1' || cipher[i] == '2' || cipher[i] == '3' || cipher[i] == '4' || 
			cipher[i] == '5' || cipher[i] == '6' || cipher[i] == '7' || cipher[i] == '8' || cipher[i] == '9' || 
			cipher[i] == ' ' || cipher[i] == '.')
		{
			message.push_back(cipher[i]);
		}
		else
		{
			//saves index position in reference table of current letter in cypher
			for (int j = 0; j < 26; j++)
			{
				if (cipher[i] == referenceTable1[j])
				{
					cipherIndex = j;
					break;
				}
			}
			//save index position in reference table of current letter in key
			for (int j = 0; j < 26; j++)
			{
				if (key[i] == referenceTable1[j])
				{
					keyIndex = j;
					break;
				}
			}
			messageIndex = ((cipherIndex - keyIndex + 26) % 26);
			message.push_back(referenceTable1[messageIndex]);
		}
	}

	return message;
}
