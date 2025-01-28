/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:52:30 by cofische          #+#    #+#             */
/*   Updated: 2025/01/27 18:37:28 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include <cfloat>
#include <cmath>
#include <iomanip> 
#include <limits>
#include "../Colors.hpp"

class ScalarConverter {
	public:
		static void convert(const std::string &str);
		
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
};

int stringToInt(const std::string &str);
float stringToFloat(const std::string &str);
std::string removeChar(const std::string &str);
double stringToDouble(const std::string &str);
void convertToChar(const std::string &str);
void convertToInt(const std::string &str);
void convertToFloat(const std::string &str);
void convertToDouble(const std::string &str);
bool specialCase(const std::string &str);
