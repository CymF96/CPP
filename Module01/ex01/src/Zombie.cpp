/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:03:05 by cofische          #+#    #+#             */
/*   Updated: 2025/01/16 13:10:45 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie::Zombie() : name("") {};

Zombie::~Zombie() {
	std::cout << BOLD RED << name << RESET <<  " has been destroy " << std::endl;
}

void Zombie::setName(std::string &inputName) {
	name = inputName;
}

void Zombie::announce(void) {
	std::cout << BOLD GREEN << name << RESET << ": BraiiiiiiinnnzzzZ..." << std::endl;
}