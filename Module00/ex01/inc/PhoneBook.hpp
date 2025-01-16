/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:25:32 by cofische          #+#    #+#             */
/*   Updated: 2025/01/16 11:57:16 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include "../../Colors.hpp"
#include "Contact.hpp"

class Phonebook{
	private:
		Contact contact[8];
		int currentIndex;
		
	public:
		Phonebook();
		~Phonebook();
		void setIndex(int &i);
		int getIndex();
		void printFields(std::string str);

		int	printPhonebook();
		void increaseIndex(int &index);
		int	addContact(std::string &name, std::string &lastName, std::string &nickName, std::string &darkestSecret, int &phoneNumber);
		void displayContact(int &index);
};
