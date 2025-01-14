/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:53:37 by cofische          #+#    #+#             */
/*   Updated: 2025/01/14 12:57:33 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

FragTrap::FragTrap(const std::string &inputName) : ClapTrap(inputName) {
	std::cout << BOLD MAGENTA << inputName << RESET << " --from FragTrap class-- has been generated" << std::endl;
	setEnergyPoints(100);
	setAttackDamage(30);
	setHitPoints(100);
};

FragTrap::~FragTrap() {
	std::cout << BOLD MAGENTA << this->getName() << RESET << " --from FragTrap class-- has been destroy" << std::endl;
};

void FragTrap::highFivesGuys(void) {
	std::cout << BOLD MAGENTA << this->getName() << RESET << " says: ✋ High five, warriors! Let's reach the gate together!" << std::endl;
};
