/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:41:02 by cofische          #+#    #+#             */
/*   Updated: 2025/01/08 17:52:38 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB(const std::string &inputName) :
	weapon(0),
	name(inputName)
	{};

HumanB::~HumanB() {
	std::cout << name << " was destroy" << std::endl;
};

void HumanB::setWeapon(Weapon &inputWeapon) {
	weapon = &inputWeapon;
}

void HumanB::attack() {
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;	
};