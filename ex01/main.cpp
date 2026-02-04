#include "phonebook.hpp"
#include <cctype>
#include <limits>

int handleWeirdInput()
{
	//if its a ctrl + D just get out
	if (std::cin.eof())
	{
		std::cout << "Bye!\n";
		return (0);
	}
	//fix the broken stream
	std::cin.clear();
	//delete everything thats in the input buffer until you find a new line (enter)
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return (1);
}

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

int displayContacts(PhoneBook &phoneBook)
{
	int	index;

	std::cout << std::endl;
	std::cout << "|   Index  |First name| Last name| Nickname |\n";
	std::cout << "_____________________________________________\n";
	phoneBook.displayContacts();
	std::cout << std::endl << "Choose the index of the contact you want to display:" << std::endl;
	while (!(std::cin >> index))
	{
		if (!handleWeirdInput())
			return (0);
		std::cout << "The index must be numeric, please try again: \n";
	}
	phoneBook.displaySingleContact(index);
	return 1;
}

int addContact(PhoneBook& phoneBook)
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
	if (!(std::cin >> firstName) && !handleWeirdInput())
		return (0);
	while (!validName(firstName))
	{
		std::cout << "Invalid name, please try again.\n";
		std::cout << "First name:\n";
		if (!(std::cin >> firstName) && handleWeirdInput())
			return (0);
	}
	std::cout << std::endl;

	std::cout << "Last name:\n";
	if (!(std::cin >> lastName) && !handleWeirdInput())
		return (0);
	while (!validName(lastName))
	{
		std::cout << "Invalid name, please try again.\n";
		std::cout << "Last name:\n";
		if (!(std::cin >> lastName) && !handleWeirdInput())
			return (0);
	}
	std::cout << std::endl;

	std::cout << "Nickname:\n";
	if (!(std::cin >> nickname) && !handleWeirdInput())
		return (0);
	std::cout << std::endl;

	std::cout << "Phone number:\n";
	if (!(std::cin >> phoneNumber) && !handleWeirdInput())
		return (0);
	while (!validPhoneNumber(phoneNumber))
	{
		std::cout << "Invalid phone number, please try again.\n";
		std::cout << "Phone number:\n";
		if (!(std::cin >> phoneNumber) && !handleWeirdInput())
			return (0);
	}
	std::cout << std::endl;

	std::cout << "Darkest secret:\n";
	if (!(std::cin >> darkestSecret) && !handleWeirdInput())
		return (0);
	phoneBook.addContact(Contact(firstName, lastName, nickname, phoneNumber, darkestSecret));
	std::cout << std::endl << std::endl;
	std::cout << firstName << " " << lastName << " added to the phone book!";
	std::cout << std::endl << std::endl;

	return (1);
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
		if (!(std::cin >> input) && !handleWeirdInput())
			return (1);
		if (input == "ADD" && !addContact(phoneBook))
			return 1;
		else if (input == "SEARCH" && !displayContacts(phoneBook))
			return 1;
		else if (input == "EXIT")
			std::cout << "Say goodbye to me and to all your contacts!\n";
		else if (input != "ADD" && input != "SEARCH")
			std::cout << "Wrong input, try again!\n";	
	}
}
