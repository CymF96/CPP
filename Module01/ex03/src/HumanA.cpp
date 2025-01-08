/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:54:02 by cofische          #+#    #+#             */
/*   Updated: 2025/01/08 17:52:28 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"

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