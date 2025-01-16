/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:21:12 by cofische          #+#    #+#             */
/*   Updated: 2025/01/16 16:09:12 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"

Contact::Contact() : name(""), lastName(""), nickName(""), darkestSecret(""), phoneNumber(0) {};
Contact::~Contact() {};

void Contact::setName(std::string &userName) {
	name = userName;
};

void Contact::setLastName(std::string &userLastName) {
	lastName = userLastName;
};

void Contact::setNickName(std::string &userNickName) {
	nickName = userNickName;
};

void Contact::setDarkestSecret(std::string &userDarkestSecret) { 
	darkestSecret = userDarkestSecret; 
};

void Contact::setPhoneNumber(int &userPhoneNumber) { 
	phoneNumber = userPhoneNumber; 
};

std::string Contact::getName() { 
	return name; 
};

std::string Contact::getLastName() { 
	return lastName; 
};

std::string Contact::getNickName() { 
	return nickName; 
};

std::string Contact::getDarkestSecret() { 
	return darkestSecret; 
};

int Contact::getPhoneNumber() { 
	return phoneNumber; 
};
