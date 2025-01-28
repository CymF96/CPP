/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utility.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:20:39 by cofische          #+#    #+#             */
/*   Updated: 2025/01/28 13:51:28 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Utility.hpp"

Base* createA() { return new A;};
Base* createB() { return new B;};
Base* createC() { return new C;};

Base *generate(void) {
	Base *(*consArray[3])() = {&createA, &createB, &createC};
	
	int random = std::rand() % 3;
	
	return consArray[random]();
	throw std::runtime_error("Randomization failed to call a derived class constructor");
};

void identify(Base *p) {
	try {
		if (dynamic_cast<A*>(p)) {
			std::cout << "type of p is: " BOLD RED "A" RESET << std::endl;
		} else if (dynamic_cast<B*>(p)) {
			std::cout << "type of p is: " BOLD GREEN "B" RESET << std::endl;
		} else if (dynamic_cast<C*>(p)) {
			std::cout << "type of p is: " BOLD BLUE "C" RESET << std::endl;
		}
	} catch (std::exception &e) {
		std::cout << "*P cannot be identified: " << e.what() << std::endl;
	}
};

void identify(Base &p) {
    try {
        if (dynamic_cast<A *>(&p))
            std::cout << "type of p is: " BOLD RED "A" RESET << std::endl;
        else if (dynamic_cast<B *>(&p))
            std::cout << "type of p is: " BOLD GREEN "B" RESET << std::endl;
        else if (dynamic_cast<C *>(&p))
            std::cout << "type of p is: " BOLD BLUE "C" RESET << std::endl;
    } catch(const std::exception& e) {
        std::cout << "*P cannot be identified: " << e.what() << std::endl;
    }
};
