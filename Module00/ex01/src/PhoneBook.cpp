/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 08:31:40 by cofische          #+#    #+#             */
/*   Updated: 2025/01/16 16:17:20 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"
#include "../inc/Contact.hpp"

Phonebook::Phonebook() : currentIndex(0){};
Phonebook::~Phonebook() {};

void Phonebook::setIndex(int &i) { 
	currentIndex = i; 
};

int Phonebook::getIndex() { 
	return currentIndex; 
};

void Phonebook::printFields(std::string str)
{
	if (str.length() > 10)
	{
		for (int j = 0; j < 9; j++)
		{
			std::cout << str[j];
		}
		std::cout << "." << " | ";
	}
	else
	{
		int j;
		for (j = 0; str[j]; j++)
			std::cout << str[j];
		for (int i = j; i < 10; i++)
			std::cout << " ";
		std::cout << " | ";
	}
};

int Phonebook::printPhonebook() {
	if (contact[0].getName().empty())
		return 1;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "0" << i + 1 << " | ";
		printFields(contact[i].getName());
		printFields(contact[i].getLastName());
		printFields(contact[i].getNickName());
		std::cout << std::endl;
	}
	return 0;
};

void Phonebook::increaseIndex(int &index) {
	if (index < 7)
		index++;
	else
		index = index % 7;
	setIndex(index);
};

int Phonebook::addContact(std::string &name, std::string &lastName, std::string &nickName, std::string &darkestSecret, int &phoneNumber) {
	int index = getIndex();
	contact[index].setName(name);
	contact[index].setLastName(lastName);
	contact[index].setNickName(nickName);
	contact[index].setDarkestSecret(darkestSecret);
	contact[index].setPhoneNumber(phoneNumber);
	increaseIndex(index);
	return 0;
};

void Phonebook::displayContact(int &index)
{
	std::cout << BOLD GREEN << "Name: " << RESET << contact[index - 1].getName() << std::endl;
	std::cout << BOLD GREEN << "Last name: " << RESET << contact[index - 1].getLastName() << std::endl;
	std::cout << BOLD GREEN << "Nick name: " << RESET << contact[index - 1].getNickName() << std::endl;
	std::cout << BOLD GREEN << "Darkest secret: " << RESET << contact[index - 1].getDarkestSecret() << std::endl;
	std::cout << BOLD GREEN << "Phone number: " << RESET << contact[index - 1].getPhoneNumber() << "\n"
			  << std::endl;
};