#include "contact.hpp"
#include <string>

Contact::Contact()
	: _name(""), _phoneNumber(""), _address("") {}

Contact::Contact(const std::string& name, const std::string& phoneNumber, const std::string& address)
	: _name(name), _phoneNumber(phoneNumber), _address(address) {}

Contact::~Contact() {}



std::string Contact::getName() const
{
	return _name;
}

std::string Contact::getPhoneNumber() const
{
	return _phoneNumber;
}

std::string Contact::getAddress() const
{
	return _address;
}
