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
		throw BTC::BTCERROR("Failed generating database\n");
	if (conversionFile.is_open()) {
		dataMapping(conversionFile, 2);
		conversionFile.close();
	} else
		throw BTC::BTCERROR("Failed reading conversionFile\n");
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

const map &BTC::getMap() {
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
	std::string fstLine;
	if (!std::getline(base, fstLine)) {
		throw BTC::BTCERROR("Error: Empty database file\n");
		return;
	}
	if (isdigit(fstLine[0]))
		line = fstLine;
	else 
		(std::getline(base, line));
	switch (flag) {
		case 1:
			do {
				if (checkFormat(line))
					Mapping(line);
				else {
					throw BTC::BTCERROR("database creation failed\n");
					return;
				}
			} while (std::getline(base, line));
			break;

		case 2:
			do {
				try {
					checkFormatFile(line);
					std::string temp = line.substr(0, 10);
					findValue(temp);
					printConversion(temp);
				} catch (std::exception &e) {
					std::cout << "Error: " << e.what();
				}
			} while (std::getline(base, line));
			break;

		default:
			throw BTC::BTCERROR("Invalid flag provided\n");
			return;
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
	//CREATE A SEPARATE FUNCTION FOR CHECKING DATE VALIDITY??
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

void BTC::checkFormatFile(std::string &line) {
	int year, month, day;
	char dash1, dash2, spe;
	int daysInMonth[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	std::istringstream iss(line);
	iss >> year >> dash1 >> month >> dash2 >> day >> spe >> value;
	
	if (iss.fail() || dash1 != '-' || dash2 != '-' || spe != '|' || !isdigit(line[0]) || line[10] != ' ' || line[12] != ' ') {
		throw BTC::BTCERROR("invalid input. Format = (YYYY-MM-DD | price)\n");
	}
	else if (value < 0 || value > 1000)  {
		throw BTC::BTCERROR("value requested isn't positive or too high (0 to 1000 only)\n");
	}
	//SEPARATE FUNCTION FOR CHECKING VALIDITY OF DATE ?? STRUCT FOR DATE + VALUE ??
	else if (month == 2 && day == 29) {
		if ((!(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))) {
			throw BTC::BTCERROR("date isn't correct\n");
		}
	}
	else if ((year < 1900 || year > 2025) && (month < 1 || month > 12) && (day <= daysInMonth[month])) {
		throw BTC::BTCERROR("date isn't correct\n");
	}
	
};

void BTC::findValue(const std::string &key) {
	mapKey = btc.find(key);
	if (mapKey == btc.end()) {
		mapKey = findClosest(key);
		mapValue = mapKey->second;
	}	
	else
		mapValue = mapKey->second;
};

keyType BTC::findClosest(const std::string &key) {
	keyType dateAfter = btc.begin();
	keyType dateBefore = btc.end();
	--dateBefore;
	while (dateAfter != btc.end() && dateAfter->first < key)
		++dateAfter;
	if (dateAfter == btc.end())
		--dateAfter;
	while (dateBefore != btc.begin() && dateBefore->first > key)
		--dateBefore;
	if ((dateBefore->first < key)  && dateBefore->first >= key)
		return dateBefore;
	else
		return dateAfter;
};

/*******************************/
/**********EXCEPTIONS***********/
/*******************************/

BTC::BTCERROR::BTCERROR(const char* msg) : message(msg) {}
const char* BTC::BTCERROR::what() const throw() { return message; };

/*******************************/
/********OTHER FUNCTIONS********/
/*******************************/

// std::ostream &operator<<(std::ostream &os, BTC &data) {
// 	std::map<std::string, float>::const_iterator it;
// 	for (it = data.getMap().begin(); it != data.getMap().end(); ++it)
// 		os << "[" << it->first << "] = " << it->second << std::endl;
// 	for (it = data.tempBTC.begin(); it != data.tempBTC.end(); ++it)
// 		os << "[" << it->first << "] = " << it->second << std::endl;
// 	return os;
// };

