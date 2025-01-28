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

#include "Scalar.hpp"

ScalarConverter::ScalarConverter() {std::cout << "Default constructor" << std::endl;};
ScalarConverter::~ScalarConverter() {std::cout << "Default destructor" << std::endl;};;
ScalarConverter::ScalarConverter(const ScalarConverter &other) {(void)other; std::cout << "Copy constructor" << std::endl;};
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {(void)other; std::cout << "Copy assignment" << std::endl; return *this;};

void ScalarConverter::convert(const std::string &str) {
	if (specialCase(str))
		return ;
	if ((str.size() == 3 && str[0] == '\'' && str[2] == '\'') || (str.size() == 1 && !isdigit(str[0])))
		convertToChar(str);
	else if (str.size() > 1 && str.find('.') != std::string::npos) {
		if (str.find('f') != std::string::npos)
			convertToFloat(str);
		else
			convertToDouble(str);
	} else
		convertToInt(str); 
};

void convertToChar(const std::string &str) {
	char c = str[0];
	if (c < 32 || c > 126)
		std::cout << "char: " RED << "non displayable" << RESET << std::endl;
	else if (isprint(c))
		std::cout << "char: " MAGENTA "'" << c << "'" RESET << std::endl;
	else
		std::cout << "char: " RED << "impossible" << RESET << std::endl;
	std::cout << "int: " << BLUE << static_cast<int>(c) << RESET <<std::endl;
	std::cout << "float: " << GREEN << static_cast<float>(c) << ".0f" RESET << std::endl;
	std::cout << "double: " << CYAN << static_cast<double>(c) << ".0" RESET << std::endl;
}

void convertToInt(const std::string &str) {
	int int_nbr = stringToInt(str);
	if (int_nbr < 32 || int_nbr > 126)
		std::cout << "char: " RED << "non displayable" << RESET << std::endl;
	else if (isprint(static_cast<char>(int_nbr)))
		std::cout << "char: " MAGENTA "'" << static_cast<char>(int_nbr) << RESET "'" << std::endl;
	else
		std::cout << "char: " RED "impossible" RESET << std::endl;
	if (int_nbr < std::numeric_limits<int>::min() || int_nbr > std::numeric_limits<int>::max())
		std::cout << "int: " << RED "impossible" RESET << std::endl;
	else
		std::cout << "int: " << BLUE << int_nbr << RESET << std::endl;
	std::cout << "float: " << GREEN << std::fixed << std::setprecision(1) << static_cast<float>(int_nbr) << "f" RESET << std::endl;
	std::cout << "double: " << CYAN << std::fixed << std::setprecision(1) << static_cast<double>(int_nbr) << RESET << std::endl;
}

void convertToFloat(const std::string &str) {
	float float_nbr = stringToFloat(str);
	if (float_nbr < 32 || float_nbr > 126)
		std::cout << "char: " RED << "non displayable" << RESET << std::endl;
	else if (isprint(static_cast<char>(float_nbr)))
		std::cout << "char: " MAGENTA "'" << static_cast<char>(float_nbr) << RESET "'" << std::endl;
	else
		std::cout << "char: " RED "impossible" RESET << std::endl;
	if (float_nbr < std::numeric_limits<int>::min() || float_nbr > std::numeric_limits<int>::max())
		std::cout << "int: " << RED "impossible" RESET << std::endl;
	else
		std::cout << "int: " << BLUE << static_cast<int>(float_nbr) << RESET << std::endl;
	std::cout << "float: " GREEN << std::fixed << std::setprecision(1) << float_nbr << "f" RESET << std::endl;
	std::cout << "double: " CYAN << std::fixed << std::setprecision(1) << static_cast<double>(float_nbr) << RESET << std::endl;
}

void convertToDouble(const std::string &str) {
	double double_nbr = stringToDouble(str);
	if (double_nbr < 32 || double_nbr > 126)
		std::cout << "char: " RED << "non displayable" << RESET << std::endl;
	else if (isprint(static_cast<char>(double_nbr)))
		std::cout << "char: " MAGENTA "'" << static_cast<char>(double_nbr) << RESET "'" << std::endl;
	else
		std::cout << "char: " RED "impossible" RESET << std::endl;
	if (double_nbr < std::numeric_limits<int>::min() || double_nbr > std::numeric_limits<int>::max())
		std::cout << "int: " << RED "impossible" RESET << std::endl;
	else
		std::cout << "int: " << BLUE << static_cast<int>(double_nbr)<< RESET << std::endl;
	std::cout << "float: " GREEN << std::fixed << std::setprecision(1) << static_cast<float>(double_nbr) << "f" RESET << std::endl;
	std::cout << "double: " CYAN << std::fixed << std::setprecision(1) << double_nbr << RESET << std::endl;
}

int stringToInt(const std::string &str) {
	long int_nbr;
	std::istringstream iss(str);
	iss >>int_nbr;
	if (iss.fail() || !iss.eof())
		return std::numeric_limits<int>::min(); 
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
	iss >>float_nbr;
	if (iss.fail() || !iss.eof())
		return std::numeric_limits<float>::quiet_NaN();
	return float_nbr;
};

double stringToDouble(const std::string &str) {
	double double_nbr;
	std::istringstream iss(str);
	iss >>double_nbr;
	if (iss.fail() || !iss.eof())
		return std::numeric_limits<double>::quiet_NaN();

	return double_nbr;
};

bool specialCase(const std::string &str) {
	std::string infinitArrayF[3] = {"+inff", "-inff", "nanf"};
	std::string infinitArrayD[3] = {"+inf", "-inf", "nan"};

	for (int i = 0; i < 3; i++) {
		if (str == infinitArrayF[i] || str == infinitArrayD[i]) {
			std::cout << "char: " RED "impossible" RESET << std::endl;
			std::cout << "int: " RED "impossible" RESET << std::endl;
			std::cout << "float: " GREEN << infinitArrayF[i] << RESET << std::endl;
			std::cout << "double: " CYAN << infinitArrayD[i] << RESET << std::endl;
			return 1;
		}
	}
	return 0;
}


