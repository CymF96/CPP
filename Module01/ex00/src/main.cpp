/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:57:32 by cofische          #+#    #+#             */
/*   Updated: 2025/01/16 16:38:05 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int main() {
	Zombie zomb = Zombie("Vick");
	Zombie *myZombie = newZombie("George");
	
	zomb.announce();
	myZombie->announce();

	randomChump("Bob");
	
	delete myZombie;
	return 0;
}