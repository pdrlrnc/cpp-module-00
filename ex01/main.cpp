#include "phonebook.hpp"
#include <cctype>
#include <limits>

void showOptions()
{
	std::cout << "(ADD) - Add contact\n(SEARCH) - Search contacts\n(EXIT) - Exit and lose your contacts FOREVER\n";
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
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	std::cout << std::endl << std::endl;
	std::cout << "Creating a new contact on your phone book! Please insert the following identifiers:\n";
	std::cout << std::endl;

	std::cout << "First name:\n";
	std::cin >> firstName;
	while (!validName(firstName))
	{
		std::cout << "Invalid name, please try again.\n";
		std::cout << "First name:\n";
		std::cin >> firstName;
	}
	std::cout << std::endl;

	std::cout << "Last name:\n";
	std::cin >> lastName;
	while (!validName(lastName))
	{
		std::cout << "Invalid name, please try again.\n";
		std::cout << "Last name:\n";
		std::cin >> lastName;
	}
	std::cout << std::endl;

	std::cout << "Nickname:\n";
	std::cin >> nickname;
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

	std::cout << "Darkest secret:\n";
	std::cin >> darkestSecret;
	phoneBook.addContact(Contact(firstName, lastName, nickname, phoneNumber, darkestSecret));
	std::cout << std::endl << std::endl;
	std::cout << firstName << " " << lastName << " added to the phone book!";
	std::cout << std::endl << std::endl;
}

int main()
{
	PhoneBook phoneBook;
	std::string input;

	std::cout << "\t\tWELCOME TO YOUR PHONE BOOK\t\t\n";
	std::cout <<"\t\t__________________________\t\t\n";

	input = "";
	while (input != "EXIT")
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
		}
		if (input == "ADD")
			addContact(phoneBook);
		else if (input == "SEARCH")
			return 1;
		else if (input == "EXIT")
			std::cout << "Say goodbye to me and to all your contacts!\n";
		else
			std::cout << "Wrong input, try again!\n";	
	}
}
