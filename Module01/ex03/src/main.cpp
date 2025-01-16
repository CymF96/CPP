/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:43:44 by cofische          #+#    #+#             */
/*   Updated: 2025/01/16 17:50:17 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"
#include "../inc/HumanA.hpp"
#include "../inc/HumanB.hpp"

/*
Reference can't be null so so HumanB which not necessary start with a weapon but can find one during the game has to set the constructor weapon to 0 so using pointer
Human A has always a weapon so it can't be null, therefore using reference which alias the weapon class object.
*/

int main() {
	{
		Weapon club = Weapon("crude spiked club");
		Weapon club2 = Weapon("Axe");
		HumanA bob("Bob", club);
		std::cout << std::endl;
		
		bob.attack();
		std::cout << BOLD GREEN << "Bob " << RESET << "switch weapon" << std::endl;
		bob.setWeapon(club2);
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		std::cout << std::endl;
		
		jim.attack();
		std::cout << BOLD GREEN << "Jim " << RESET << "pick a weapon" << std::endl;
		jim.setWeapon(club);
		jim.attack();
		std::cout << BOLD GREEN << "Jim " << RESET << "switch weapon" << std::endl;
		club.setType("some other type of club");
		jim.attack();
		std::cout << std::endl;
	}
	return 0;
}