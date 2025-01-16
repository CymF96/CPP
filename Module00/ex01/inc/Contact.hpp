/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:20:21 by cofische          #+#    #+#             */
/*   Updated: 2025/01/16 11:58:07 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "../../Colors.hpp"

class Contact{
	private:
		std::string	name;
		std::string	lastName;
		std::string	nickName;
		std::string	darkestSecret;
		int		phoneNumber;
	
	public:
		Contact();
		~Contact();
		void setName(std::string &userName);
		void setLastName(std::string &userLastName);
		void setNickName(std::string &userNickName);
		void setDarkestSecret(std::string &userDarkestSecret);
		void setPhoneNumber(int &userPhoneNumber);
		std::string getName();
		std::string getLastName();
		std::string getNickName();
		std::string getDarkestSecret();
		int getPhoneNumber();
};