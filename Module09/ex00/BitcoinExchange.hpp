/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:18:01 by cofische          #+#    #+#             */
/*   Updated: 2025/02/05 16:38:50 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <sstream>
#include <limits>
#include <map>
#include "../Colors.hpp"

class BTC {
	public:
		BTC(const std::string &filename);
		~BTC();
		BTC(const BTC &other);
		BTC &operator=(const BTC &other);
		
		std::string key;
		float conversion;

		float getConversion() const;
		std::string getKey() const;
		std::string findKey(const std::string &key);
		void dataMapping();
		void Mapping(std::string line);
		bool checkFormat(std::string &line);
		
		class BTCERROR: public std::exception {
			private:
				const char* message;
			public:
				BTCERROR(const char* msg);
				virtual const char* what() const throw();
		};
	
	private:
		std::map<const std::string, const float> btc;
		std::ifstream database;
};

std::ostream &operator<<(std::ostream &os, const BTC &btc);