/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:07:39 by cofische          #+#    #+#             */
/*   Updated: 2025/01/14 16:55:46 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal() {
	std::cout << BOLD MAGENTA << "Animal has been created" << RESET << std::endl;
}

Animal::~Animal() {
	std::cout << BOLD MAGENTA << "Animal has been destroy" << RESET << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
	std::cout << BOLD MAGENTA << " Animal copy constructor has been created" << RESET << std::endl;	
}

Animal &Animal::operator=(const Animal &other) {
	std::cout << BOLD MAGENTA << " Animal copy assignment constructor has been created" << RESET << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

std::string Animal::getType() const {
	return type;
};

void Animal::setType(const std::string &inputType) {
	type = inputType;
};

void Animal::makeSound() const {
	std::cout << BOLD MAGENTA << "Animal " << RESET << " says .... nothing because it doesn't exist (for now)" << std::endl;
};
