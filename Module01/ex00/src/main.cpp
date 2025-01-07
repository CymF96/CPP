/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:57:32 by cofische          #+#    #+#             */
/*   Updated: 2025/01/07 11:55:16 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	
	Zombie *myZombie = newZombie("George");
	myZombie->announce();
	delete myZombie;

	randomChump("Bob");
	return 0;
}