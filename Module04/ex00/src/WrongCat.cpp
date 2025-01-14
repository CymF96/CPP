/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:25:04 by cofische          #+#    #+#             */
/*   Updated: 2025/01/14 16:59:13 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << BOLD CYAN << "WrongCat has been created" << RESET << std::endl;
	this->setType("WrongCat");	
}

WrongCat::~WrongCat() {
	std::cout << BOLD CYAN << "WrongCat has been destroy" << RESET << std::endl;

}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << BOLD CYAN << " WrongCat copy constructor has been created" << RESET << std::endl;	

};

WrongCat &WrongCat::operator=(const WrongCat &other) {
	std::cout << BOLD CYAN << " WrongCat copy assignment constructor has been created" << RESET << std::endl;
	if (this != &other)
		type = other.type;
	return *this;	
};

void WrongCat::makeSound() const {
	std::cout << BOLD CYAN << type << RESET << " says Grrrrrrrr 🦁" << std::endl;
};
