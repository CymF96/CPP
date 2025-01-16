/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:41:02 by cofische          #+#    #+#             */
/*   Updated: 2025/01/16 13:22:27 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB(const std::string &inputName) :
	weapon(0),
	name(inputName)
	{};

HumanB::~HumanB() {
	std::cout << BOLD RED << name << RESET << " was destroy" << std::endl;
};

void HumanB::setWeapon(Weapon &inputWeapon) {
	weapon = &inputWeapon;
}

void HumanB::attack() {
	std::cout << BOLD GREEN << name << RESET << " attacks with their " << BOLD YELLOW << weapon->getType() << RESET << std::endl;	
};