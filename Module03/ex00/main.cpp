/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:36:33 by cofische          #+#    #+#             */
/*   Updated: 2025/01/14 11:48:31 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"

int main() {
	ClapTrap Mandy("Mandy");
	ClapTrap Bob("Bob");
	unsigned int attack_points = 5, heal_points = 2;
	
	
	std::cout << std::endl;
	Bob.setEnergyPoints(1);
	defineClapTrapper(Mandy);
	defineClapTrapper(Bob);
	std::cout << std::endl;
	Bob.attack("Mandy");
	Mandy.takeDamage(attack_points);
	Mandy.beRepaired(heal_points);
	Mandy.attack("Bob");
	Bob.takeDamage(attack_points);
	Bob.beRepaired(heal_points);
	std::cout << std::endl;
	return (0);
}