/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utility.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-29 10:02:12 by cofische          #+#    #+#             */
/*   Updated: 2025-01-29 10:02:12 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Utility.hpp"

/******************************************************************************************/
//								TYPE FINDER FUNCTIONS
/******************************************************************************************/

typeData findType(const std::string &str){
	if (str.find("+inf") != std::string::npos || str.find("-inf") != std::string::npos || str.find("nan") != std::string::npos )
		return SPE;
	else if ((str.size() == 3 && str[0] == '\'' && str[2] == '\'') || (str.size() == 1 && !isdigit(str[0])))
		return CHAR;
	else if (str.size() > 1 && str.find('.') != std::string::npos) {
		if (str.find('f') != std::string::npos)
			return FLOAT;
		else
			return DOUBLE;
	} else
		return INT;
};

/******************************************************************************************/
//								PRINTING CONVERTION FUNCTIONS
/******************************************************************************************/

template <typename T>
static void printConversion(typeData type, T num) {
	if (num < 32 || num > 126)
		std::cout << "char: " RED << "non displayable" << RESET << std::endl;
	else if (type == CHAR)
		std::cout << "char: " MAGENTA "'" << num << RESET "'" << std::endl;
	else if (isprint(static_cast<char>(num)))
		std::cout << "char: " MAGENTA "'" << static_cast<char>(num) << RESET "'" << std::endl;
	else
		std::cout << "char: " RED "impossible" RESET << std::endl;
	if (std::isnan(num) || (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max()))
		std::cout << "int: " << RED "impossible" RESET << std::endl;
	else {
		if (type == INT)
			std::cout << "int: " << BLUE << num << RESET << std::endl;
		else 
			std::cout << "int: " << BLUE << static_cast<int>(num) << RESET << std::endl;
	}
	if (isnan(num) || (num < -std::numeric_limits<float>::max() || num > std::numeric_limits<float>::max()))
		std::cout << "float: " << RED "impossible" RESET << std::endl;
	else {
		if (type == FLOAT)
			std::cout << "float: " GREEN << std::fixed << std::setprecision(1) << num << "f" RESET << std::endl;
		else
			std::cout << "float: " GREEN << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" RESET << std::endl;
	}
	if (isnan(num) || (num < -std::numeric_limits<double>::max() || num > std::numeric_limits<double>::max()))
		std::cout << "double: " << RED "impossible" RESET << std::endl;
	else {
		if (type == DOUBLE)
			std::cout << "double: " CYAN << std::fixed << std::setprecision(1) << num << RESET << std::endl;
		else
			std::cout << "double: " CYAN << std::fixed << std::setprecision(1) << static_cast<double>(num) << RESET << std::endl;
	}
}

void convertToChar(const std::string &str) {
	char c = str[0];
	printConversion(CHAR, c);
}

void convertToInt(const std::string &str) {
	int int_nbr = stringToInt(str);
	if (str[0] == '0' && int_nbr == 0)
		printConversion(INT, int_nbr);
	else
		printConversion(INT, stringToDouble(str));
}

void convertToFloat(const std::string &str) {
	float float_nbr = stringToFloat(str);
	printConversion(FLOAT, float_nbr);
}

void convertToDouble(const std::string &str) {
	double double_nbr = stringToDouble(str);
	printConversion(DOUBLE, double_nbr);
}

void specialCase(const std::string &str) {
	std::string infinitArrayF[3] = {"+inff", "-inff", "nanf"};
	std::string infinitArrayD[3] = {"+inf", "-inf", "nan"};

	for (int i = 0; i < 3; i++) {
		if (str == infinitArrayF[i] || str == infinitArrayD[i]) {
			std::cout << "char: " RED "impossible" RESET << std::endl;
			std::cout << "int: " RED "impossible" RESET << std::endl;
			std::cout << "float: " GREEN << infinitArrayF[i] << RESET << std::endl;
			std::cout << "double: " CYAN << infinitArrayD[i] << RESET << std::endl;
			return ;
		}
	}
	std::cerr << "Error: invalid data input" << std::endl;
}

/******************************************************************************************/
//								CONVERTION FUNCTIONS
/******************************************************************************************/

int stringToInt(const std::string &str) {
	int int_nbr;
	std::istringstream iss(str);
	iss >> int_nbr;
	if (iss.fail() || !iss.eof())
		return 0; 
	return int_nbr;
};

std::string removeChar(const std::string &str) {
    if (str[str.size() - 1] == 'f') {
        return str.substr(0, str.size() - 1);
    }
    return str;
}

float stringToFloat(const std::string &str) {
	std::string temp = removeChar(str);
	float float_nbr;
	std::istringstream iss(temp);
	iss >> float_nbr;
	if (iss.fail() || !iss.eof())
		return std::numeric_limits<float>::quiet_NaN();
	return float_nbr;
};

double stringToDouble(const std::string &str) {
	double double_nbr;
	std::istringstream iss(str);
	iss >> double_nbr;
	if (iss.fail() || !iss.eof())
		return std::numeric_limits<double>::quiet_NaN();

	return double_nbr;
};
