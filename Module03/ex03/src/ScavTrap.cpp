/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:26:14 by cofische          #+#    #+#             */
/*   Updated: 2025/01/14 18:55:05 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &inputName): ClapTrap(inputName) {
	std::cout << BOLD YELLOW << inputName << RESET << " --from ScavTrap class-- has been generated" << std::endl;
	setEnergyPoints(50);
	setAttackDamage(20);
	setHitPoints(100);
};

ScavTrap::~ScavTrap() {
	std::cout << BOLD YELLOW << this->getName() << RESET << " --from ScavTrap class-- has been destroy" << std::endl;
};

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << BOLD YELLOW << "ScavTrap copy constructor" << RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	std::cout << BOLD YELLOW << "ScavTrap copy assignment constructor" << RESET << std::endl;
	if (this != &other) 
		ClapTrap::operator=(other);
	return *this;
}

void ScavTrap::guardGate() {
	std::cout << BOLD YELLOW << this->getName() << RESET << " is now guarding the Gate" << std::endl;
};
