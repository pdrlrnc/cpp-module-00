#include "phonebook.hpp"

PhoneBook::PhoneBook() : _index(0), _full(false) {}
PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(const Contact& newContact)
{
	if (_index == MAX_CONTACTS)
	{
		_full = true;
		_index = 0;
	}
	_contacts[_index] = newContact;
	_index++;
	
}

/**
void PhoneBook::matchInput(std::string& input)
{
	std::string currContact;
	int matches;

	matches = 0;
	for (int i = 0; !_full ? i < _index : i < (MAX_CONTACTS - 1) ; i++)
	{
		if (isdigit(input[0]))
			currContact = _contacts[i].getPhoneNumber();
		else
			currContact = _contacts[i].getName();
		std::string::const_iterator input_it = input.begin();
		std::string::const_iterator contact_it = currContact.begin();
		while (input_it != input.end() && contact_it != currContact.end() && *input_it == *contact_it)
		{
			input_it++;
			contact_it++;
		}
		if (input_it == input.end())
		{
			std::cout << "Name: " + _contacts[i].getName() + "\t";
			std::cout << "Phone number: " + _contacts[i].getPhoneNumber() + "\t";
			std::cout << "Address: " + _contacts[i].getAddress() + "\n";
			matches++;
		}
	}
	std::cout << "Found " << matches << " matches!\n";
	std::cout << std::endl << std::endl;
}

int PhoneBook::find()
{
	std::string input;

	std::cout << std::endl << std::endl;
	std::cout << "Welcome to the find feature of your phonebook!\n";
	std::cout << "You can find by name or phone number!\n";
	std::cout << "Insert partial or full name or phone number:\n";
	std::cin >> input;
	if (std::cin.eof())
		return 4;
	if (!_full && !_index)
		return 0;
	matchInput(input);
	return 0;
}

void PhoneBook::displayContacts()
{
	if (!_full && !_index)
		std::cout << "Phonebook is empty! You should get some friends :/";
	else if (!_full)
	{
		for (int i = _index - 1; i >= 0; i--)
		{
			std::cout << "Name: " + _contacts[i].getName() + "\t";
			std::cout << "Phone number: " + _contacts[i].getPhoneNumber() + "\t";
			std::cout << "Address: " + _contacts[i].getAddress() + "\n";

		}
	}
	else 
	{
		for (int i = _index - 1; i >= 0; i--)
		{
			std::cout << "Name: " + _contacts[i].getName() + "\t";
			std::cout << "Phone number: " + _contacts[i].getPhoneNumber() + "\t";
			std::cout << "Address: " + _contacts[i].getAddress() + "\n";
		}
		for (int i = MAX_CONTACTS - 1; i >= _index; i--)
		{

			std::cout << "Name: " + _contacts[i].getName() + "\t";
			std::cout << "Phone number: " + _contacts[i].getPhoneNumber() + "\t";
			std::cout << "Address: " + _contacts[i].getAddress() + "\n";
		}
	}
	std::cout << std::endl;
}
**/
