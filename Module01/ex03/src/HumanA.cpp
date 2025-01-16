/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:54:02 by cofische          #+#    #+#             */
/*   Updated: 2025/01/16 13:21:21 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"
	
HumanA::HumanA(const std::string &inputName, const Weapon &inputWeapon) :
	name(inputName),
	weapon(inputWeapon)
	{};

HumanA::~HumanA() {
	std::cout << BOLD RED << name << RESET << " was destroy" << std::endl;
};

void HumanA::attack() {
	std::cout << BOLD GREEN << name << RESET << " attacks with their " << BOLD YELLOW << weapon.getType() << RESET << std::endl;	
};