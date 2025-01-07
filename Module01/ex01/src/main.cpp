/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:57:32 by cofische          #+#    #+#             */
/*   Updated: 2025/01/07 12:49:21 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	int nbr = 4;
	std::string name = "Zomb";
	Zombie *horde = zombieHorde(nbr, name);

	for (int i = 0; i < nbr; i++)
		horde[i].announce();

	delete[] horde;
	return (0);
}