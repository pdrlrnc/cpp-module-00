/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 10:40:06 by pedde-so          #+#    #+#             */
/*   Updated: 2026/03/07 10:40:08 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include <string>

Contact::Contact()
	: _firstName(""), _lastName(""), _nickname(""), _phoneNumber(""), _darkestSecret("") { std::cout << "Calling Contact no args constructor" << std::endl; }

Contact::Contact(const std::string& firstName,
		 const std::string& lastName, 
		 const std::string& nickname, 
		 const std::string& phoneNumber, 
		 const std::string& darkestSecret)
	: 
		_firstName(firstName), 
		_lastName(lastName), 
		_nickname(nickname), 
		_phoneNumber(phoneNumber), 
		_darkestSecret(darkestSecret) { std::cout << "Calling Contact full args constructor" << std::endl;}

Contact::~Contact() { std::cout << "Calling Contact destructor" << std::endl; }

std::string Contact::getFirstName() const
{
	return _firstName;
}

std::string Contact::getLastName() const
{
	return _lastName;
}

std::string Contact::getNickname() const
{
	return _nickname;
}

std::string Contact::getPhoneNumber() const
{
	return _phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
	return _darkestSecret;
}

