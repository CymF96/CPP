/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:36:05 by cofische          #+#    #+#             */
/*   Updated: 2025/01/15 16:31:10 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice has been generated" << std::endl;
};

Ice::~Ice() {
	std::cout << "Ice has been destroy" << std::endl;
};

Ice::Ice(const Ice &other) : AMateria(other.type) {
	std::cout << "Ice copy constructor has been generated" << std::endl;
};

Ice &Ice::operator=(const Ice &other) {
	std::cout << "Ice copy assignement has been generated" << std::endl;
	return *this;
};

void AMateria::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << BOLD GREEN << target.getName() << RESET << " *" << std::endl;
}