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

void PhoneBook::displayContacts()
{
	if (!_full && !_index)
		std::cout << "Phonebook is empty! You should get some friends :/\n";
}

