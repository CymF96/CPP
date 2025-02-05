/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:53:57 by cofische          #+#    #+#             */
/*   Updated: 2025/02/05 16:38:36 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*******************************/
/**********CONSTRUCTORS*********/
/*******************************/

BTC::BTC(const std::string &filename) : conversion(0), key(""), database(filename.c_str()) {
	if (database.is_open()) {
		dataMapping();
		database.close();
	}
	throw BTC::BTCERROR("File reading failed\n");
}

BTC::~BTC() {

}

BTC::BTC(const BTC &other) : conversion(other.conversion), key(other.key) {

}

BTC &BTC::operator=(const BTC &other) {
	if (this != &other) {
		conversion = other.conversion;
		key = other.key;
	}
	return *this;
}

/*******************************/
/**********METHODS**************/
/*******************************/

void BTC::dataMapping() {
	std::string line;
	while (std::getline(database, line)) {
		if (checkFormat(line)) {
			Mapping(line)
		}

	}
};

void BTC::Mapping(std::string line) {
	
}

bool BTC::checkFormat(std::string &line) {
	int year, month, day;
	float value;
	char dash1, dash2, spe;
	int daysInMonth[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	std::istringstream iss(line);
	iss >> year >> dash1 >> month >> dash2 >> day >> spe >> value;
	
	if (iss.fail() || dash1 != '-' || dash2 != '-' || spe != ',') {
		throw BTC::BTCERROR("wrong date format (YYYY-MM-DD)\n");
		return false;
	}
	if (month == 2 && day == 29) {
		if ((!(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))) {
			throw BTC::BTCERROR("date isn't correct\n");
			return false;
		}
	}
	if ((year < 1900 || year > 2025) && (month < 1 || month > 12) && (day <= daysInMonth[month])) {
		throw BTC::BTCERROR("date isn't correct\n");
		return false;
	}
	if (value < 0 || value > std::numeric_limits<float>::max())  {
		throw BTC::BTCERROR("value requested isn't positive or too high (0 to 1000 only)\n");
		return false;
	}
	return true;		
};

float BTC::getConversion() const {

};

std::string BTC::getKey() const {

};

std::string BTC::findKey(const std::string &key) {

};

/*******************************/
/**********EXCEPTIONS***********/
/*******************************/

BTC::BTCERROR::BTCERROR(const char* msg) : message(msg) {}
const char* BTC::BTCERROR::what() const throw() { return message; };

/*******************************/
/********OTHER FUNCTIONS********/
/*******************************/

// std::ostream &operator<<(std::ostream &os, const BTC &btc);

bool checkFormat(std::string &line) {
	int year, month, day;
	float value;
	char dash1, dash2, space, spe;
	int daysInMonth[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	std::istringstream iss(line);
	iss >> year >> dash1 >> month >> dash2 >> day >> space >> spe >> space >> value;
	
	if (iss.fail() || dash1 != '-' || dash2 != '-' || spe != '|') {
		throw BTC::BTCERROR("wrong date format (YYYY-MM-DD)\n");
		return false;
	}
	if (month == 2 && day == 29) {
		if ((!(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))) {
			throw BTC::BTCERROR("date isn't correct\n");
			return false;
		}
	}
	if ((year < 1900 || year > 2025) && (month < 1 || month > 12) && (day <= daysInMonth[month])) {
		throw BTC::BTCERROR("date isn't correct\n");
		return false;
	}
	if (value < 0 || value > 1000)  {
		throw BTC::BTCERROR("value requested isn't positive or too high (0 to 1000 only)\n");
		return false;
	}
	return true;		
};