/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:41:02 by cofische          #+#    #+#             */
/*   Updated: 2025/01/16 17:48:06 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB(const std::string &inputName) : weapon(0), name(inputName) {
	std::cout << BOLD BLUE << "HumanB" << RESET << " has been generated" << std::endl;
};

HumanB::~HumanB() {
	std::cout << BOLD GREEN << name << RESET << " from " << BOLD BLUE << "Human B" << RESET << " was destroy" << std::endl;
};

void HumanB::setWeapon(Weapon &inputWeapon) {
	weapon = &inputWeapon;
}

void HumanB::attack() {
	if (!weapon)
		std::cout << BOLD GREEN << name << RESET << " attacks with no weapon" << std::endl;
	else
		std::cout << BOLD GREEN << name << RESET << " attacks with their " << BOLD YELLOW << weapon->getType() << BOLD BLUE << " -- It's an HumanB" << RESET << std::endl;
};