#include "phonebook.hpp"
#include <ostream>

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

void PhoneBook::displaySingleContact(int index)
{
	if ((!_full && ((_index - 1) < index))
		|| (_full && index > (MAX_CONTACTS - 1)))
	{
		std::cout << "You entered a invalid index\n";
		return ;
	}
	std::cout << "First name: " << _contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << _contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " << _contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << _contacts[index].getDarkestSecret() << std::endl;
	
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
**/

void PhoneBook::formatField(const std::string& field)
{
	int i;
	int spaces;

	if (field.length() > 10)
	{
		i = 0;
		while (i < 9)
			std::cout << field[i++];
		std::cout << ".";
	}
	else 
	{
		spaces = 10 - field.length();
		while (spaces-- > 0)
			std::cout << " ";
		std::cout << field ;
	}
	std::cout << "|";
}


void PhoneBook::displayContacts()
{
	if (!_full && !_index)
		return ;
	for (int i = 0; !_full ? i < _index : i < MAX_CONTACTS ; i++)
	{
		std::cout << "|         " << i << "|";
		formatField(_contacts[i].getFirstName());
		formatField(_contacts[i].getLastName());
		formatField(_contacts[i].getNickname());
		std::cout << std::endl;
	}
}



