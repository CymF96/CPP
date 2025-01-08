/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:04:25 by cofische          #+#    #+#             */
/*   Updated: 2025/01/08 17:51:48 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../Colors.hpp"

int main() {
	std::string brain =  "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;
	
	std::cout << "Memory address of the string BRAIN: " << BOLD GREEN << &brain << RESET << std::endl;
	std::cout << "Memory address held by stringPTR: " << BOLD GREEN << stringPTR << RESET << std::endl;
	std::cout << "Memory address held by stringREF: " << BOLD GREEN << &stringREF << RESET << std::endl;
	std::cout << "\nValue of the string BRAIN: " << BOLD GREEN << brain << RESET << std::endl;
	std::cout << "Value pointed to by stringPTR: " << BOLD GREEN << *stringPTR << RESET << std::endl;
	std::cout << "Value pointed to by stringREF: " << BOLD GREEN << stringREF << RESET << std::endl;

	return (0);
}