/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:54:02 by cofische          #+#    #+#             */
/*   Updated: 2025/01/07 15:35:36 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void HumanA::attack() {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;	
};
	
HumanA::HumanA(const std::string &inputName, const Weapon &inputWeapon) :
	name(inputName),
	weapon(inputWeapon)
	{};

HumanA::~HumanA() {
	std::cout << name << " was destroy" << std::endl;
};