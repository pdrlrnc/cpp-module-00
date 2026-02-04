#ifndef CONTACT_H
#define CONTACT_H

#include <string>
class Contact
{
	private:
		std::string _name;
		std::string _phoneNumber;
		std::string _address;
	public:
		//no args constructor -  i need it because phoneBook has a array of contacts and since c++
		//is weird, whenever i call phonebook's constructor it will basically go thru all the members
		//of the array and also call their constructor
		Contact();
		//all args constructor - every field should be const because there won't be a feature to
		//edit a contact field and i am using std::string& so they are passed as reference thus avaoiding
		//copying the original string - less overhead
		Contact(const std::string& name, const std::string& phoneNumber, const std::string& address); 
		//destructor
		~Contact();

		//getters. no setters because fields are const
		std::string getName() const;
		std::string getPhoneNumber() const;
		std::string getAddress() const;

};

#endif
