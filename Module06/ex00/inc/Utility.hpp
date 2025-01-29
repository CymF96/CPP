/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-29 10:02:57 by cofische          #+#    #+#             */
/*   Updated: 2025-01-29 10:02:57 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <iomanip> 
#include <limits>
#include "Scalar.hpp"
#include "../../Colors.hpp"

enum typeData {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    SPE,
};

typeData findType(const std::string &str);
int stringToInt(const std::string &str);
float stringToFloat(const std::string &str);
std::string removeChar(const std::string &str);
double stringToDouble(const std::string &str);
void convertToChar(const std::string &str);
void convertToInt(const std::string &str);
void convertToFloat(const std::string &str);
void convertToDouble(const std::string &str);
void specialCase(const std::string &str);
