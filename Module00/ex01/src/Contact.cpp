/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:21:12 by cofische          #+#    #+#             */
/*   Updated: 2025/01/16 11:21:23 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"

Contact::Contact() : name(""), lastName(""), nickName(""), darkestSecret(""), phoneNumber(0) {}; //Constructor to initiate Contact objects
Contact::~Contact() { std::cout << "Contact has been destroy\n";};
void Contact::setName(std::string &userName) {name = userName;}; //Using setter and getter to assign variable from private and readonly variable when used ++ using reference to avoid unecessary copying of variable and overload stack memory
void Contact::setLastName(std::string &userLastName) {lastName = userLastName;};
void Contact::setNickName(std::string &userNickName) {nickName = userNickName;};
void Contact::setDarkestSecret(std::string &userDarkestSecret) { darkestSecret = userDarkestSecret; };
void Contact::setPhoneNumber(int &userPhoneNumber) { phoneNumber = userPhoneNumber; };
std::string Contact::getName() { return name; };
std::string Contact::getLastName() { return lastName; };
std::string Contact::getNickName() { return nickName; };
std::string Contact::getDarkestSecret() { return darkestSecret; };
int Contact::getPhoneNumber() { return phoneNumber; };