/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:25:04 by cofische          #+#    #+#             */
/*   Updated: 2025/01/14 18:39:09 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat() {
	std::cout << BOLD BLUE << "Cat has been created" << RESET << std::endl;
	this->setType("Cat");
	this->brain = new Brain();
}

Cat::~Cat() {
	std::cout << BOLD BLUE << "Cat has been destroy" << RESET << std::endl;
	delete this->brain;

}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << BOLD BLUE << " Cat copy constructor has been created" << RESET << std::endl;
	this->type = other.type;
	this->brain = new Brain(*other.brain);	

};

Cat &Cat::operator=(const Cat &other) {
	std::cout << BOLD BLUE << " Cat copy assignment constructor has been created" << RESET << std::endl;
		if (this != &other) {
			Animal::operator=(other);
			this->setType(other.getType());
			delete this->brain;
			this->brain = new Brain(*other.brain);
		}
	return *this;
};

void Cat::makeSound() const {
	std::cout << BOLD BLUE << type << RESET << " says Meeeeeeeeeeeeow 🐱" << std::endl;
};
