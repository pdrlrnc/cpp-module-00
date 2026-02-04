#include "phonebook.hpp"
#include <cctype>
#include <limits>

void showOptions()
{
	std::cout << "(1) - Add contact\n(2) - Display contacts\n(3) - Find\n(4) - Leave\n";
}

bool validPhoneNumber(const std::string& phoneNumber)
{
	std::string::const_iterator it = phoneNumber.begin();
	while (it != phoneNumber.end() && std::isdigit(*it))
		it++;
	return !phoneNumber.empty() && it == phoneNumber.end();

}

bool validName(const std:: string& name)
{
	std::string::const_iterator it = name.begin();
	while (it != name.end() && !std::isdigit(*it))
		it++;
	return !name.empty() && it == name.end();
}

void addContact(PhoneBook& phoneBook)
{
	std::string name;
	std::string phoneNumber;
	std::string address;

	std::cout << std::endl << std::endl;
	std::cout << "Creating a new contact on your phone book! Please insert the following identifiers:\n";
	std::cout << std::endl;
	std::cout << "Name:\n";
	std::cin >> name;
	while (!validName(name))
	{
		std::cout << "Invalid name, please try again.\n";
		std::cout << "Name:\n";
		std::cin >> name;
	}
	std::cout << std::endl;
	std::cout << "Phone number:\n";
	std::cin >> phoneNumber;
	while (!validPhoneNumber(phoneNumber))
	{
		std::cout << "Invalid phone number, please try again.\n";
		std::cout << "Phone number:\n";
		std::cin >> phoneNumber;	
	}
	std::cout << std::endl;
	std::cout << "Address:\n";
	std::cin >> address;
	phoneBook.addContact(Contact(name, phoneNumber, address));
	std::cout << std::endl << std::endl;
	std::cout << name + " added to the phone book!";
	std::cout << std::endl << std::endl;
}

int main()
{
	PhoneBook phoneBook;
	int input;

	std::cout << "\t\tWELCOME TO YOUR PHONE BOOK\t\t\n";
	std::cout <<"\t\t__________________________\t\t\n";

	input = 0;
	while (input != 4)
	{
		showOptions();
		//if the user is dumb and types a char, the input stream enters a fail state
		if (!(std::cin >> input))
		{
			if (std::cin.eof())
			{
				std::cout << "Bye!\n";
				return (0);
			}
			//fix the broken stream
			std::cin.clear();
			//delete everything thats in the input buffer until you find a new line (enter)
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			input = 0;
		}
		switch(input)
		{
			case 1:
				addContact(phoneBook);
				break;
			case 2:
				std::cout << std::endl << std::endl;
				std::cout << "\nYour contacts:\n";
				std::cout <<"_____________\n";
				phoneBook.displayContacts();
				std::cout << std::endl << std::endl;
				break;
			case 3:
				input = phoneBook.find();
				if (input == 4)
					std::cout << "Bye!\n";
				break;
			case 4:
				std::cout << "Bye!\n";
				break;
			default:
				std::cout << "Wrong input, try again!\n";
				break;
				
		}
	}

}
