/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:26:14 by cofische          #+#    #+#             */
/*   Updated: 2025/01/14 12:45:47 by cofische         ###   ########.fr       */
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

void ScavTrap::guardGate() {
	std::cout << BOLD YELLOW << this->getName() << RESET << " is now guarding the Gate" << std::endl;
};
