/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:04:58 by cofische          #+#    #+#             */
/*   Updated: 2025/01/16 16:46:20 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie *zombieHorde(int N, const std::string &name) {
	Zombie *horde = new Zombie[N];
	
	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
	}
	
	return (horde);
};