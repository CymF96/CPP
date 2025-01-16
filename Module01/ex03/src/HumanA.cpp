/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:54:02 by cofische          #+#    #+#             */
/*   Updated: 2025/01/16 17:28:05 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"
	
HumanA::HumanA(const std::string &inputName, Weapon &inputWeapon) : name(inputName), weapon(inputWeapon) {
	std::cout << BOLD MAGENTA << "HumanA" << RESET << " has been generated" << std::endl;
};

HumanA::~HumanA() {
	std::cout << BOLD GREEN << name << RESET << " from " << BOLD MAGENTA << "HumanA" << RESET <<  " was destroy" << std::endl;
};

void HumanA::setWeapon(Weapon &inputWeapon) {
	weapon = inputWeapon;
}

void HumanA::attack() {
	std::cout << BOLD GREEN << name << RESET << " attacks with their " << BOLD YELLOW << weapon.getType() << BOLD MAGENTA << " -- It's an HumanA" << RESET << std::endl;
};