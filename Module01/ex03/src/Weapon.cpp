/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:35:19 by cofische          #+#    #+#             */
/*   Updated: 2025/01/16 17:30:26 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"

Weapon::Weapon(const std::string &inputWeapon) : type(inputWeapon) {
	std::cout << BOLD YELLOW << "Weapon " << RESET << "has been generated" << std::endl;
};

Weapon::~Weapon() {
	std::cout << BOLD YELLOW << getType() << RESET << " has been destroy" << std::endl;
};

const std::string Weapon::getType(void) {
	return (type);
};

void Weapon::setType(const std::string &inputType) {
	type = inputType;
};