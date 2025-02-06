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

float value;

/*******************************/
/**********CONSTRUCTORS*********/
/*******************************/

BTC::BTC(const std::string &filename) : mapKey(0), mapValue(0), database("CSV/data.csv"), conversionFile(filename.c_str()) {
	if (database.is_open()) {
		dataMapping(database, 1);
		database.close();
	} else
		throw BTC::BTCERROR("Faild generating database\n");
	if (conversionFile.is_open()) {
		dataMapping(conversionFile, 2);
		conversionFile.close();
	} else
		throw BTC::BTCERROR("Faild reading conversionFile\n");
}
BTC::~BTC() {}
BTC::BTC(const BTC &other) : tempBTC(other.tempBTC), mapKey(other.mapKey), mapValue(other.mapValue), btc(other.btc) {}
BTC &BTC::operator=(const BTC &other) {
	if (this != &other) {
		mapKey = other.mapKey;
		mapValue = other.mapValue;
		btc = other.btc;
		tempBTC = other.tempBTC;
	}
	return *this;
}

/*******************************/
/**********GETTERS**************/
/*******************************/

const std::map<std::string, float> &BTC::getMap() {
	return btc;
}

float BTC::getConversion() const {
	return mapValue;
};

keyType BTC::getKey() const {
	return mapKey;
};

/*******************************/
/**********METHODS**************/
/*******************************/

void BTC::dataMapping(std::ifstream &base, int flag) {
	std::string line;
	std::getline(base, line); 
	if (!isdigit(line[0]))
		std::getline(base, line);
	switch (flag) {
		case 1: 
			while (std::getline(base, line)) {	
				if (checkFormat(line))
					Mapping(line);
				else {
					throw BTC::BTCERROR ("database creation failed\n");
					return ;
				}
			}
		case 2:
			while (std::getline(base, line)) {
				try {
					checkFormatFile(line);
					std::string temp = line.substr(0, 10);
					findValue(temp);
					printConversion(temp);

				} catch (std::exception &e) {
					std::cout << "Error: " << e.what();
				}
			}
	}
};

float BTC::convert() {
	return (value * mapValue);
};

void BTC::Mapping(std::string &line) {
	std::string temp = line.substr(0, 10);
	btc.insert(std::make_pair(temp, value));
}

void BTC::printConversion(std::string &temp) {
	std::cout << BOLD BLUE << temp << RESET " => " << value << " = " << convert() << std::endl;
}

bool BTC::checkFormat(std::string &line) {
	char dash1, dash2, spe;
	int year, month, day;
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

void BTC::findValue(const std::string &key) {
	mapKey = btc.find(key);
	if (mapKey == btc.end()) {
		// std::cout << "key: " << key << ", mapKey: not found" << std::endl;
		findClosest(key);
	}	
	else {
		mapValue = mapKey->second;
		// std::cout << "key: " << key << ", mapKey: " << mapKey->first << std::endl;
	}
};

keyType BTC::findClosest(const std::string &key) {
	keyType closestHigh = btc.begin();
	keyType closestLow = btc.end();
	while (closestHigh != btc.end() && closestHigh->first < key)
		++closestHigh;
	if (closestHigh == btc.end())
		--closestHigh;
	while (closestLow != btc.begin() && closestLow->first > key)
		++closestLow;
	if (closestHigh == btc.end() || 
		(closestHigh->first < key && closestLow->first >= key)) {
		return closestHigh;
	} else {
		return closestLow;
	}
};

void BTC::checkFormatFile(std::string &line) {
	int year, month, day;
	char dash1, dash2, spe;
	int daysInMonth[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	// std::cout << line << std::endl;

	std::istringstream iss(line);
	iss >> year >> dash1 >> month >> dash2 >> day >> spe >> value;

	// std::cout << "year: " << year << std::endl;
	// std::cout << "dash1: " << dash1 << std::endl;
	// std::cout << "month: " << month << std::endl;
	// std::cout << "dash2: " << dash2 << std::endl;
	// std::cout << "day: " << day << std::endl;
	// std::cout << "spe: " << spe << std::endl;
	// std::cout << "value: " << value << std::endl;
	
	if (iss.fail() || dash1 != '-' || dash2 != '-' || spe != '|' || !isdigit(line[0]) || line[10] != ' ' || line[12] != ' ') {
		throw BTC::BTCERROR("invalid input. Format = (YYYY-MM-DD | price)\n");
	}
	else if (month == 2 && day == 29) {
		if ((!(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))) {
			throw BTC::BTCERROR("date isn't correct\n");
		}
	}
	else if ((year < 1900 || year > 2025) && (month < 1 || month > 12) && (day <= daysInMonth[month])) {
		throw BTC::BTCERROR("date isn't correct\n");
	}
	else if (value < 0 || value > 1000)  {
		throw BTC::BTCERROR("value requested isn't positive or too high (0 to 1000 only)\n");
	}		
};

/*******************************/
/**********EXCEPTIONS***********/
/*******************************/

BTC::BTCERROR::BTCERROR(const char* msg) : message(msg) {}
const char* BTC::BTCERROR::what() const throw() { return message; };

/*******************************/
/********OTHER FUNCTIONS********/
/*******************************/

std::ostream &operator<<(std::ostream &os, BTC &data) {
	std::map<std::string, float>::const_iterator it;
	for (it = data.getMap().begin(); it != data.getMap().end(); ++it)
		os << "[" << it->first << "] = " << it->second << std::endl;
	for (it = data.tempBTC.begin(); it != data.tempBTC.end(); ++it)
		os << "[" << it->first << "] = " << it->second << std::endl;
	return os;
};

