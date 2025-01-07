/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:03:05 by cofische          #+#    #+#             */
/*   Updated: 2025/01/07 11:59:05 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(const std::string &inputName) : name(inputName) {};

Zombie::~Zombie() {
	std::cout << name << " has been destroy " << std::endl;
}

void Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}