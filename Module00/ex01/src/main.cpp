/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:25:37 by cofische          #+#    #+#             */
/*   Updated: 2025/01/16 12:22:11 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

int	main() {
	std::string userName, userLastName, userNickName, userDarkestSecret, input = "";
	int userPhoneNumber = 1, userIndex;
	Phonebook phoneBook;
	
	std::cout << BOLD << "****************************\nWELCOME TO MINI_PHONEBOOK\n****************************\n" << RESET << std::endl;
	std::cout << "Please use one of these command " << BOLD RED << "ADD " << "SEARCH " << "EXIT" << RESET << std::endl;
	std::cout	<< BOLD RED << "ADD: " << RESET << "to add contact to your phonebook\n" 
			<< BOLD RED << "SEARCH: " << RESET << "to look for a contact's phone number\n"
			<< BOLD RED << "EXIT: " << RESET << "to quit the Phonebook. " 
			<< BOLD << "! WARNING ! " << RESET << "your contacts will be lost and the program will close\n" << std::endl;

	while (1)
	{
		std::cin >> input;
		if (!input.compare("ADD")) {
			while (1) {
				std::cout << "Please enter the following information: " << std::endl << BOLD GREEN << "name: " << RESET;
				std::cin.ignore();
				std::getline(std::cin, userName);
				std::cout << BOLD GREEN << "last_name: " << RESET;
				std::cin.ignore();
				std::getline(std::cin, userLastName);
				std::cout << BOLD GREEN << "nick_name: " << RESET;
				std::cin.ignore();
				std::getline(std::cin, userNickName);
				std::cout << BOLD GREEN << "darkest_secret " << RESET << "(please use " << BOLD << "\"\"): " << RESET;;
				std::cin.ignore();
				std::getline(std::cin, userDarkestSecret);
				std::cout << BOLD GREEN << "phone Number " << RESET << "(for extension, please use this format: " << BOLD << "00XX): " << RESET;
				std::cin >> userPhoneNumber;
				std::cout << "\n";
			    if (phoneBook.addContact(userName, userLastName, userNickName, userDarkestSecret, userPhoneNumber) == 0) {
					break;
				} else {
					std::cout << "Please check your input and try again.\n" << std::endl;
				}
			}
		}
		else if (!input.compare("SEARCH")) {
			if (phoneBook.printPhonebook() == 0) {
				while (1) {
					std::cout << "\nPlease enter the index of the contact: ";
					std::cin >> userIndex; 
					if (userIndex < 1 || userIndex > 8)
						std::cout << "Contact not found. Please enter a valid index number (between 1 and 8)" << std::endl;
					else {
						phoneBook.displayContact(userIndex);
						break ;
					}
				}
			}
			else
				std::cout << "Sorry your mini_phonebook is currently empty. Please add contact to use this command\n" << std::endl;
		}
		else if (!input.compare("EXIT")) {
			std::cout << "\nThank you for using " << BOLD << "MINI_PHONEBOOK\n"
				<< "*********\nGOODBYE\n*********" << RESET << std::endl; 
			return (0);
		}
		input.clear();
	}

	return (0);
}