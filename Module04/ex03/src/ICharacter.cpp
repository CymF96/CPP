/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:30:26 by cofische          #+#    #+#             */
/*   Updated: 2025/01/15 16:37:53 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ICharacter.hpp"

ICharacter::ICharacter() {
	std::cout << "ICharacter has been created" << std::endl;
};

ICharacter::~ICharacter() {
	std::cout << "ICharacter has been destroy" << std::endl;
};

ICharacter::ICharacter(const ICharacter &other) {
	std::cout << "ICharacter copy constructor has been created" << std::endl;
}

ICharacter &ICharacter::operator=(const ICharacter &other) {
	std::cout << "ICharacter copy assignement constructor has been created" << std::endl;
	return *this;
}
