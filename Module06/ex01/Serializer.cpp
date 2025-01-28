/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:01:40 by cofische          #+#    #+#             */
/*   Updated: 2025/01/28 11:15:41 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {std::cout << "Default constructor" << std::endl;};
Serializer::~Serializer() {std::cout << "Default destructor" << std::endl;};
Serializer::Serializer(const Serializer &other) {(void)other; std::cout << "Copy constructor" << std::endl;};
Serializer &Serializer::operator=(const Serializer &other) {(void)other; std::cout << "Copy assignment" << std::endl; return *this;};

uintptr_t Serializer::serialize(Data *ptr) {
	uintptr_t newPtr = reinterpret_cast<uintptr_t>(ptr);
	return newPtr;
};

Data *Serializer::deserialize(uintptr_t raw) {
	Data *newRaw = reinterpret_cast<Data*>(raw);
	return newRaw;
};
