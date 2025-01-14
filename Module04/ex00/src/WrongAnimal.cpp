/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:07:39 by cofische          #+#    #+#             */
/*   Updated: 2025/01/14 16:56:49 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << BOLD RED << "WrongAnimal has been created" << RESET << std::endl;
	this->setType("Devil Animal");
	std::cout << "It's a " << BOLD RED << type << RESET << " 😈" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << BOLD RED << "WrongAnimal has been destroy" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) {
	std::cout << BOLD RED << " WrongAnimal copy constructor has been created" << RESET << std::endl;	
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	std::cout << BOLD RED << " WrongAnimal copy assignment constructor has been created" << RESET << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

std::string WrongAnimal::getType() const {
	return type;
};

void WrongAnimal::setType(const std::string &inputType) {
	type = inputType;
};

void WrongAnimal::makeSound() const {
	std::cout << BOLD RED << type << RESET << " says Mouhahahaha 😈" << std::endl;
};
