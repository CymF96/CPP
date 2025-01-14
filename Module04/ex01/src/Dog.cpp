/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:29:59 by cofische          #+#    #+#             */
/*   Updated: 2025/01/14 17:41:42 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include "../inc/Brain.hpp"

Dog::Dog() {
	std::cout << BOLD BLUE << "Dog has been created" << RESET << std::endl;
	this->setType("Dog");
	this->brain = new Brain();
}

Dog::~Dog() {
	std::cout << BOLD BLUE << "Dog has been destroy" << RESET << std::endl;
	delete this->brain;
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
		delete this->brain;
		this->brain = new Brain(*other.brain);
		}
	return *this;	
};

void Dog::makeSound() const {
	std::cout << BOLD BLUE << type << RESET << " says Woooooooooooof 🐶" << std::endl;
};