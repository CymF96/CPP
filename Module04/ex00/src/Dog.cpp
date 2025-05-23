/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:29:59 by cofische          #+#    #+#             */
/*   Updated: 2025/01/14 17:41:32 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog() {
	std::cout << BOLD BLUE << "Dog has been created" << RESET << std::endl;
	this->setType("Dog");	
}

Dog::~Dog() {
	std::cout << BOLD BLUE << "Dog has been destroy" << RESET << std::endl;

}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << BOLD BLUE << " Dog copy constructor has been created" << RESET << std::endl;	
	this->type = other.type;
};

Dog &Dog::operator=(const Dog &other) {
	std::cout << BOLD BLUE << " Dog copy assignment constructor has been created" << RESET << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		this->setType(other.getType());
		}
	return *this;	
};

void Dog::makeSound() const {
	std::cout << BOLD BLUE << type << RESET << " says Woooooooooooof 🐶" << std::endl;
};