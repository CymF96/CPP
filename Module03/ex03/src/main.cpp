/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:36:33 by cofische          #+#    #+#             */
/*   Updated: 2025/01/14 14:22:03 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"
#include "../inc/DiamondTrap.hpp"

int main() {
	ClapTrap Mandy("Mandy");
	ClapTrap Bob("Bob");
	unsigned int attack_points = 5, heal_points = 2;
	
	
	std::cout << std::endl;
	Bob.setEnergyPoints(1);
	defineClapTrapper(Mandy);
	defineClapTrapper(Bob);
	Bob.attack("Mandy");
	Mandy.takeDamage(attack_points);
	Mandy.beRepaired(heal_points);
	Mandy.attack("Bob");
	Bob.takeDamage(attack_points);
	Bob.beRepaired(heal_points);
	std::cout << std::endl;
	
	ScavTrap Robot("Warden");
	std::cout << std::endl;
	defineClapTrapper(Robot);
	Robot.guardGate();
	std::cout << std::endl;
	
	FragTrap Cheerleader("Sam the Cheerleader");
	std::cout << std::endl;
	defineClapTrapper(Cheerleader);
	Cheerleader.highFivesGuys();
	std::cout << std::endl;
	
	DiamondTrap Monster("Mephisto the Dark");
	std::cout << std::endl;
	defineClapTrapper(Monster);
	std::cout << std::endl;
    Monster.whoAmI();
    Monster.attack("Enemy");
	std::cout << std::endl;

	return (0);
}