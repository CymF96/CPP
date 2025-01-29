/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:52:33 by cofische          #+#    #+#             */
/*   Updated: 2025/01/27 19:15:44 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Scalar.hpp"

ScalarConverter::ScalarConverter() {std::cout << "Default constructor" << std::endl;};
ScalarConverter::~ScalarConverter() {std::cout << "Default destructor" << std::endl;};;
ScalarConverter::ScalarConverter(const ScalarConverter &other) {(void)other; std::cout << "Copy constructor" << std::endl;};
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {(void)other; std::cout << "Copy assignment" << std::endl; return *this;};

void ScalarConverter::convert(const std::string &str) {
	typeData type = findType(str);
	
	switch (type) {
		case CHAR:
			convertToChar(str);
			return;
		case INT: 
			convertToInt(str);
			return ;
		case FLOAT:
			convertToFloat(str);
			return;
		case DOUBLE:
			convertToDouble(str);
			return ;
		case SPE:
			specialCase(str);
			return ;
		default:
			std::cerr << "Error: invalid data input" << std::endl;
	}
};

