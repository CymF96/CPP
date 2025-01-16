/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:35:19 by cofische          #+#    #+#             */
/*   Updated: 2025/01/16 13:21:56 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"

Weapon::Weapon(const std::string &inputWeapon) : 
	type(inputWeapon)
	{};

Weapon::~Weapon() {
	std::cout << BOLD RED << getType() << RESET << " has been destroy" << std::endl;
};

const std::string Weapon::getType(void) {
	return (type);
};

void Weapon::setType(const std::string &inputType) {
	type = inputType;
};