/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:35:45 by cofische          #+#    #+#             */
/*   Updated: 2025/01/15 16:31:14 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"

Cure::Cure() : AMateria("Cure") {
	std::cout << "Cure has been generated" << std::endl;
};

Cure::~Cure() {
	std::cout << "Cure has been destroy" << std::endl;
};

Cure::Cure(const Cure &other) : AMateria(other.type) {
	std::cout << "Cure copy constructor has been generated" << std::endl;
};

Cure &Cure::operator=(const Cure &other) {
	std::cout << "Cure copy assignement has been generated" << std::endl;
	return *this;
};

void AMateria::use(ICharacter &target) {
	std::cout << "* heals " << BOLD GREEN << target.getName() << RESET << " wonds *" << std::endl;
};