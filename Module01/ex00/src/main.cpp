/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:57:32 by cofische          #+#    #+#             */
/*   Updated: 2025/01/08 17:44:12 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int main() {
	
	Zombie *myZombie = newZombie("George");
	myZombie->announce();
	delete myZombie;

	randomChump("Bob");
	return 0;
}