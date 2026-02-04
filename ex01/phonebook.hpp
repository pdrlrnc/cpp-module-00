#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "contact.hpp"
#include <iostream>

#define MAX_CONTACTS 4

class PhoneBook 
{
	private:
		Contact _contacts[MAX_CONTACTS];
		int _index;
		bool _full;
//		void matchInput(std::string& input);
	public:
		//no args constructor
		PhoneBook();
		//destructor
		~PhoneBook();

		void addContact(const Contact& newContact);
//		void displayContacts();
//		int find();

};

#endif
