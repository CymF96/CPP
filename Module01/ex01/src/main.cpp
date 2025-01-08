/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:57:32 by cofische          #+#    #+#             */
/*   Updated: 2025/01/08 17:51:13 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int main() {
	int nbr = 4;
	std::string name = "Zomb";
	Zombie *horde = zombieHorde(nbr, name);

	for (int i = 0; i < nbr; i++)
		horde[i].announce();

	delete[] horde;
	return (0);
}