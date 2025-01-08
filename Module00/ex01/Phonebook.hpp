/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:25:32 by cofische          #+#    #+#             */
/*   Updated: 2025/01/08 17:50:04 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "../Colors.hpp"

class Contact{
	private:
		std::string	name;
		std::string	lastName;
		std::string	nickName;
		std::string	darkestSecret;
		int		phoneNumber;
	
	public:
	
		Contact() : name(""), lastName(""), nickName(""), darkestSecret(""), phoneNumber(0) {}; //Constructor to initiate Contact objects
	
		void setName(std::string &userName) {name = userName;}; //Using setter and getter to assign variable from private and readonly variable when used ++ using reference to avoid unecessary copying of variable and overload stack memory
		void setLastName(std::string &userLastName) {lastName = userLastName;};
		void setNickName(std::string &userNickName) {nickName = userNickName;};
		void setDarkestSecret(std::string &userDarkestSecret) {darkestSecret = userDarkestSecret;};
		void setPhoneNumber(int &userPhoneNumber) {phoneNumber = userPhoneNumber;};
		std::string getName() {return name;};
		std::string getLastName() {return lastName;};
		std::string getNickName() {return nickName;};
		std::string getDarkestSecret() {return darkestSecret;};
		int getPhoneNumber() {return phoneNumber;};
};

class Phonebook{
	private:
		Contact contact[8];
		int currentIndex;
		
	public:
		Phonebook(): currentIndex(0) {}; 
		void setIndex(int &i) { currentIndex = i;};
		int getIndex() { return currentIndex;};
		
	void	printFields(std::string str) {
		if (str.length() > 10) {
			for (int j = 0; j < 9; j++) {
				std::cout << str[j];
			}
			std::cout << "." << " | ";
		}
		else {
			int j;
			for (j = 0; str[j]; j++)
				std::cout << str[j];
			for (int i = j; i < 10; i++)
				std::cout << " ";
			std::cout << " | ";
		}
	};
	
	int	printPhonebook() { //print all Phonebook
		if (contact[0].getName().empty())
				return 1;
		for (int i = 0; i < 8; i++) {
			std::cout << "0" << i + 1 << " | ";
			printFields(contact[i].getName());
			printFields(contact[i].getLastName());
			printFields(contact[i].getNickName());
			std::cout << std::endl;
		}
		return 0;
	};
	
	void	increaseIndex(int &index) { //increasing index so the new contact is always between 1 and 8 -- 0 and 7 in array count
		if (index < 7)
			index++;
		else
			index = index % 7;
		setIndex(index);
	};
	
	int	addContact(std::string &name, std::string &lastName, std::string &nickName, std::string &darkestSecret, int &phoneNumber) {
		if (name.empty() || lastName.empty() || nickName.empty() || darkestSecret.empty() || !phoneNumber) {
			std::cout << "Error. Contact can't have empty fields" << std::endl;
			return 1;
		}
		else
		{
			int index = getIndex();
			contact[index].setName(name);
			contact[index].setLastName(lastName);
			contact[index].setNickName(nickName);
			contact[index].setDarkestSecret(darkestSecret);
			contact[index].setPhoneNumber(phoneNumber);
			increaseIndex(index);
		}
		return 0;
	};
	
	void	displayContact(int &index) {
		std::cout << BOLD GREEN << "Name: " << RESET << contact[index - 1].getName() << std::endl;
		std::cout << BOLD GREEN << "Last name: " << RESET << contact[index - 1].getLastName() << std::endl;
		std::cout << BOLD GREEN << "Nick name: " << RESET << contact[index - 1].getNickName() << std::endl;
		std::cout << BOLD GREEN << "Darkest secret: " << RESET << contact[index - 1].getDarkestSecret() << std::endl;
		std::cout << BOLD GREEN << "Phone number: " << RESET << contact[index - 1].getPhoneNumber() << "\n" << std::endl;
	};
	
};

#endif