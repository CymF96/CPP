/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:25:37 by cofische          #+#    #+#             */
/*   Updated: 2025/01/16 16:23:13 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

/*
if (std::cin.fail()) { --> check if anything fail from input user like not an interger type
	std::cin.clear(); --> Clear error flag
	std::cin.ignore(1000, '\n'); --> Clear invalid input from buffer up to 1000 char until meating newline (when user pressed enter)
	std::cout << "Invalid input. Please enter a valid number.\n"; --> print error message
	continue; --> restart the while loop true as contact wasn't added
}
*/

void handleAdd(Phonebook &phonebook) {
	std::string userName, userLastName, userNickName, userDarkestSecret;
    int userPhoneNumber;
	
	while (1) {
		std::cout << "\nPlease enter the following information: " << std::endl << BOLD GREEN << "name: " << RESET;
		std::getline(std::cin, userName);
		std::cout << BOLD GREEN << "last_name: " << RESET;
		std::getline(std::cin, userLastName);
		std::cout << BOLD GREEN << "nick_name: " << RESET;
		std::getline(std::cin, userNickName);
		std::cout << BOLD GREEN << "darkest_secret: " << RESET ;
		std::getline(std::cin, userDarkestSecret);
		std::cout << BOLD GREEN << "phone Number " << RESET << "(for extension, please use this format: " << BOLD << "00XX): " << RESET;
		std::cin >> userPhoneNumber;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << BOLD RED "Invalid input" << RESET ". Please enter a valid number.\n";
			continue;
		}
		if (userName.empty() || userLastName.empty() || userNickName.empty() || userDarkestSecret.empty()) {
			std::cout << BOLD RED << "Invalid input" << RESET << ". Contact can't have empty fields." << std::endl;
			std::cin.ignore(1000, '\n');
			continue ;
		} else {
			if (phonebook.addContact(userName, userLastName, userNickName, userDarkestSecret, userPhoneNumber) != 0) {
				std::cout << "Please check your input and try again." << std::endl;
				std::cin.ignore(1000, '\n');
			}
			std::cout << "\n";
			std::cout << "Contact successfully added!\n" << std::endl;
			break;	
		}
	}
};

void handleSearch(Phonebook &phonebook) {
	int userIndex = 0;
	if (phonebook.printPhonebook() == 0)
	{
		while (1)
		{
			std::cout << "\nPlease enter the index of the contact: ";
			std::cin >> userIndex;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << BOLD RED << "Invalid input" << RESET << ". Please enter a valid number.\n";
			}
			else if (userIndex < 1 || userIndex > 8)
				std::cout << BOLD RED << "Invalid input" << RESET << ". Please enter a valid index number (between 1 and 8)" << std::endl;
			else
			{
				phonebook.displayContact(userIndex);
				break;
			}
		}
	}
	else
		std::cout << "Sorry your mini_phonebook is currently empty. Please add contact to use this command\n"
				  << std::endl;
}

int	main() {
	std::string input = "";
	Phonebook phonebook;
	
	std::cout << BOLD << "****************************\nWELCOME TO MINI_PHONEBOOK\n****************************\n" << RESET << std::endl;
	std::cout << "Please use one of these command " << BOLD RED << "ADD " << "SEARCH " << "EXIT" << RESET << std::endl;
	std::cout	<< BOLD RED << "ADD: " << RESET << "to add contact to your phonebook\n" 
			<< BOLD RED << "SEARCH: " << RESET << "to look for a contact's phone number\n"
			<< BOLD RED << "EXIT: " << RESET << "to quit the Phonebook. " 
			<< BOLD << "! WARNING ! " << RESET << "your contacts will be lost and the program will close\n" << std::endl;

	while (1)
	{
		std::cin >> input;
        std::cin.ignore(1000, '\n');
		if (!input.compare("ADD"))
			handleAdd(phonebook);
		else if (!input.compare("SEARCH"))
			handleSearch(phonebook);
		else if (!input.compare("EXIT")) {
			std::cout << "\nThank you for using " << BOLD << "MINI_PHONEBOOK\n" << RESET << "*********\n" << BOLD << "GOODBYE\n" << RESET "*********" << RESET << std::endl; 
			return (0);
		}
		else
            std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT.\n" << std::endl;
	}
	return (0);
}