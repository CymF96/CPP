/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:18:01 by cofische          #+#    #+#             */
/*   Updated: 2025/02/07 09:52:01 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <iomanip>
#include <sstream>
#include <limits>
#include <map>
#include "../Colors.hpp"

typedef std::map<std::string, float>::iterator keyType;
typedef std::map<std::string, float> map;

class BTC {
	public:
		BTC(const std::string &filename);
		~BTC();
		BTC(const BTC &other);
		BTC &operator=(const BTC &other);
		
		map tempBTC;
		keyType tempMapKey;
		float tempMapValue;

		keyType mapKey;
		float mapValue;

		float getConversion() const;
		keyType getKey() const;
		const map &getMap();
		void findValue(const std::string &key);
		void dataMapping(std::ifstream &base, int flag);
		void Mapping(std::string &line);
		void checkFormat(std::string &line);
		void checkFormatFile(std::string &line);
		keyType findClosest(const std::string &key);
		void printConversion(std::string &temp);
		float convert();
		bool checkDateValidity(int year, int month, int day);
		
		class BTCERROR: public std::exception {
			private:
				const char* message;
			public:
				BTCERROR(const char *msg);
				virtual const char* what() const throw();
		};
	
	private:
		map btc;
		std::ifstream database;
		std::ifstream conversionFile;
};

std::ostream &operator<<(std::ostream &os, BTC &btc);
