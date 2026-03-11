#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "contact.hpp"
#include <ostream>
#include <iostream>
#include <cctype>
#include <limits>

class PhoneBook 
{
	private:
		static const int MAX_CONTACTS = 8;
		Contact _contacts[MAX_CONTACTS];
		int _index;
		bool _full;
		void formatField(const std::string& field);
	public:
		//no args constructor
		PhoneBook();
		//destructor
		~PhoneBook();

		void addContact(const Contact& newContact);
		void displayContacts();
		void displaySingleContact(int index);
};

#endif
