/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:21:42 by cofische          #+#    #+#             */
/*   Updated: 2025/01/14 14:26:29 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Claptrap.hpp"

/*Constructor//Destructor*/
ClapTrap::ClapTrap(const std::string &inputName) : hit_points(10), energy_points(10), attack_damage(5), name(inputName) {
	std::cout << BOLD GREEN << name << RESET << " --from ClapTrap class-- has been generated" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << RED BOLD << name << RESET << " --from ClapTrap class-- has been destroy" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name) {
	std::cout << RED << "Copy constructor called" << RESET << std::endl;
};

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << RED << "Copy Assignment operator called" << RESET << std::endl;
	if (this != &other)
		name = other.name;
	return *this;
};

/*Public Functions*/
std::string ClapTrap::getName() {
	return name;
}

unsigned int ClapTrap::getHitPoints() {
	return hit_points;
}

unsigned int ClapTrap::getEnergyPoints() {
	return energy_points;
}

unsigned int ClapTrap::getAttackDamage() {
	return attack_damage;
}

void ClapTrap::setEnergyPoints(const unsigned int &inputEnergyPoints) {
	energy_points = inputEnergyPoints;
}

void ClapTrap::setHitPoints(const unsigned int &inputHitPoints) {
	hit_points = inputHitPoints;
};

void ClapTrap::setAttackDamage(const unsigned int &inputAttackDamage) {
	attack_damage = inputAttackDamage;
};

void ClapTrap::attack(const std::string &target) {
	if (this->energy_points > 0) {
	this->energy_points--;
	std::cout << "ClapTrap " << BOLD GREEN << name << RESET << " attacks " << BOLD BLUE << target << RESET << ", causing " << BOLD RED << this->attack_damage << RESET << " points of damage!" << std::endl;
	std::cout << "It tooks energy to " << BOLD GREEN << name << RESET << " to attack. They lost " << BOLD RED << "1 " << RESET << "energy points.\nThey got " << BOLD RED << this->energy_points << RESET << " now.\n" << std::endl;
	} else {
		std::cout << "ClapTrap " << BOLD GREEN << name << RESET << " doesn't have enough energy points for this action." << std::endl;
	}
};

void ClapTrap::takeDamage(unsigned int &amount) {
	this->hit_points -= amount;
	std::cout << "ClapTrap " << BOLD GREEN << name << RESET << " was attacked and lost " << BOLD RED << amount << RESET << " hit points!\nThey've got " << BOLD RED << this->hit_points << RESET " now.\n" << std::endl;
};

void ClapTrap::beRepaired(unsigned int &amount) {
	if (this->energy_points > 1) {
		this->hit_points += amount;
		this->energy_points--;
		std::cout << "ClapTrap " << BOLD GREEN << name << RESET << " is repairing themselves and gets " << BOLD RED << amount << RESET << " hit points!" << std::endl;
		std::cout << "It tooks energy to " << BOLD GREEN << name << RESET << " to repair. They lost " << BOLD RED << "1 " << RESET << " energy points.\nThey got " << BOLD RED << this->energy_points << RESET << " now.\n" << std::endl;
	} else {
		std::cout << "ClapTrap " << BOLD GREEN << name << RESET << " doesn't have enough energy points for this action." << std::endl;
	}
};

void defineClapTrapper(ClapTrap &inputClapTrapper) {
	std::cout 	<< "ClapTrapper " << BOLD GREEN << inputClapTrapper.getName() << RESET << " has the following stats:\n- Health: " 
				<< BOLD RED << inputClapTrapper.getHitPoints() << RESET 
				<< "\n- Energy points: " << BOLD RED << inputClapTrapper.getEnergyPoints() << RESET 
				<< "\n- Attack damage: " << BOLD RED << inputClapTrapper.getAttackDamage() << RESET << std::endl << std::endl;
};