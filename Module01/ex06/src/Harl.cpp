/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:33:14 by cofische          #+#    #+#             */
/*   Updated: 2025/01/08 12:42:22 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {};

Harl::~Harl() {
	std::cout << "Harl has been destroy" << std::endl;
};

void Harl::complain(const std::string &level) {
	void (Harl::*levelPtr[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	void (Harl::*switchPtr)() = &Harl::switchOff;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	int check = 0;
	
	for (int i = 0; i < 4; i++) {
		if (levels[i].compare(level) == 0) {
			check = 1;
			for (int j = i; j < 4; j++)
				(this->*levelPtr[j])();
		}
	}
	if (level == "SWITCH") {
		check = 1;
		(this->*switchPtr)();
	}
	if (!check)	
		std::cout <<"Wrong level ID" << std::endl;
};

void Harl::debug(void) {
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n" << std::endl;
};

void Harl::info(void) {
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
};

void Harl::warning(void) {
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n" << std::endl;
};

void Harl::error(void) {
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
};

void Harl::switchOff(void) {
	std::cout << "[ SWITCH ]\nHarl has been switch off. You can breath now" << std::endl;
};