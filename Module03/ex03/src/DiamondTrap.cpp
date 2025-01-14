/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:03:26 by cofische          #+#    #+#             */
/*   Updated: 2025/01/14 14:26:54 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &inputName) : 
	ClapTrap(inputName + "_clap_name"), ScavTrap(inputName), FragTrap(inputName), name(inputName) {
	std::cout << BOLD BLUE << inputName << RESET << " --from DiamondTrap class-- has been generated" << std::endl;
	this->energy_points = ScavTrap::getEnergyPoints();
	this->hit_points = FragTrap::getHitPoints();
	this->attack_damage = FragTrap::getAttackDamage();
};

DiamondTrap::~DiamondTrap() {
	std::cout << BOLD BLUE << name << RESET << " --from DiamondTrap class-- has been destroy" << std::endl;
};

void DiamondTrap::whoAmI() {
	std::cout << "my DiamondTrap name is " << BOLD BLUE << name << RESET << "\nmy ClapTrap name is " << BOLD GREEN << ClapTrap::getName() << RESET << std::endl;
};

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
};
