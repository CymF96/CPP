/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:25:32 by cofische          #+#    #+#             */
/*   Updated: 2025/01/03 13:25:59 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>

// Define macros for text styles and colors
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define ITALIC  "\033[3m"
#define UNDERLINE "\033[4m"

// Define macros for text colors
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

using std::string;
using std::cout;
using std::endl;
using std::cin;


class Contact{
	private:
		string	name;
		string	lastName;
		string	nickName;
		string	darkestSecret;
		int		phoneNumber;
	
	public:
	
		Contact() : name(""), lastName(""), nickName(""), darkestSecret(""), phoneNumber(0) {}; //Constructor to initiate Contact objects
	
		void setName(string &userName) {name = userName;}; //Using setter and getter to assign variable from private and readonly variable when used ++ using reference to avoid unecessary copying of variable and overload stack memory
		void setLastName(string &userLastName) {lastName = userLastName;};
		void setNickName(string &userNickName) {nickName = userNickName;};
		void setDarkestSecret(string &userDarkestSecret) {darkestSecret = userDarkestSecret;};
		void setPhoneNumber(int &userPhoneNumber) {phoneNumber = userPhoneNumber;};
		string getName() {return name;};
		string getLastName() {return lastName;};
		string getNickName() {return nickName;};
		string getDarkestSecret() {return darkestSecret;};
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
		
	void	printFields(string str) {
		if (str.length() > 10) {
			for (int j = 0; j < 9; j++) {
				cout << str[j];
			}
			cout << "." << " | ";
		}
		else {
			int j;
			for (j = 0; str[j]; j++)
				cout << str[j];
			for (int i = j; i < 10; i++)
				cout << " ";
			cout << " | ";
		}
	};
	
	int	printPhonebook() { //print all Phonebook
		if (contact[0].getName().empty())
				return 1;
		for (int i = 0; i < 8; i++) {
			cout << "0" << i + 1 << " | ";
			printFields(contact[i].getName());
			printFields(contact[i].getLastName());
			printFields(contact[i].getNickName());
			cout << endl;
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
	
	int	addContact(string &name, string &lastName, string &nickName, string &darkestSecret, int &phoneNumber) {
		if (name.empty() || lastName.empty() || nickName.empty() || darkestSecret.empty() || !phoneNumber) {
			cout << "Error. Contact can't have empty fields" << endl;
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
		cout << BOLD GREEN << "Name: " << RESET << contact[index - 1].getName() << endl;
		cout << BOLD GREEN << "Last name: " << RESET << contact[index - 1].getLastName() << endl;
		cout << BOLD GREEN << "Nick name: " << RESET << contact[index - 1].getNickName() << endl;
		cout << BOLD GREEN << "Darkest secret: " << RESET << contact[index - 1].getDarkestSecret() << endl;
		cout << BOLD GREEN << "Phone number: " << RESET << contact[index - 1].getPhoneNumber() << "\n" << endl;
	};
	
};

#endif