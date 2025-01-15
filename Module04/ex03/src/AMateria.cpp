/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:12:26 by cofische          #+#    #+#             */
/*   Updated: 2025/01/15 16:32:54 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"

AMateria::AMateria(std::string const &inputType) : type(inputType) {
	std::cout << "AMateria has been generated" << std::endl;
};

AMateria::~AMateria() {
	std::cout << "AMateria has been destroy" << std::endl;
};

AMateria::AMateria(const AMateria &other) : type(other.type) {
	std::cout << "AMateria copy constructor has been generated" << std::endl;
};

AMateria &AMateria::operator=(const AMateria &other) {
	std::cout << "AMateria copy assignement has been generated" << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
};

std::string const &AMateria::getType() const {
	return type;
};

void AMateria::use(ICharacter &target) {
	return ;
};