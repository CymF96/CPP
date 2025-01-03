/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:10:18 by cofische          #+#    #+#             */
/*   Updated: 2025/01/03 19:28:45 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <sys/time.h>
#include <iomanip>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
int index = 0;

void Account::_displayTimestamp() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    time_t now = tv.tv_sec;
    struct tm localTime;
    localtime_r(&now, &localTime);
	
	std::cout 	<< "[" 
				<< (1900 + localTime.tm_year)
				<< std::setw(2) << std::setfill('0') << (1 + localTime.tm_mon)
				<< std::setw(2) << std::setfill('0') << localTime.tm_mday << "_"
				<< std::setw(2) << std::setfill('0') << localTime.tm_hour
				<< std::setw(2) << std::setfill('0') << localTime.tm_min
				<< std::setw(2) << std::setfill('0') << localTime.tm_sec << "] ";
}

Account::Account(int initial_deposit) {
    _amount = initial_deposit;
	_totalAmount += _amount;
	_accountIndex = index;
    index++;
	_nbAccounts++;
    
	_displayTimestamp();
	std::cout	<< "index:"  << _accountIndex  << ";"
				<< "amount:"  << _amount  << ";"
				<< "created" << std::endl;
}

void	Account::displayStatus() const {
	_displayTimestamp();
	std::cout	<< "index:"  << _accountIndex  << ";"
				<< "amount:"  << _amount  << ";"
				<< "deposits:"  << _nbDeposits  << ";"
				<< "withdrawals:"  << _nbWithdrawals  << std::endl;
}

void	Account::makeDeposit(int deposit) {
	int p_amount = _amount;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout	<< "index:"  << _accountIndex  << ";"
				<< "p_amount:"  << p_amount  << ";"
				<< "deposit:"  << deposit  << ";"
				<< "amount:"  << _amount  << ";"
				<< "nb_deposits:"  << _nbDeposits  << std::endl;
}

int	Account::checkAmount() const {
	if (_amount < 0)
		return 1;
	else
		return 0;
}

bool	Account::makeWithdrawal(int withdrawal) {
	int p_amount = _amount;
	_amount -= withdrawal;
	_displayTimestamp();
	std::cout	<< "index:"  << _accountIndex  << ";"
				<< "p_amount:"  << p_amount  << ";";
	if (checkAmount()) {
		std::cout << "withdrawal:refused" << std::endl;
		_amount = p_amount;
		return (false);
	}
	else {
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		std::cout	<< "withdrawal:"  << withdrawal  << ";"
					<< "amount:"  << _amount  << ";"
					<< "nb_withdrawals:"  << _nbWithdrawals  << std::endl;
	}
	return (true);
}

int Account::getNbAccounts() { return _nbAccounts;};
int Account::getTotalAmount() { return _totalAmount;};
int Account::getNbDeposits() { return _totalNbDeposits;};
int Account::getNbWithdrawals() { return _totalNbWithdrawals;};

void	Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout	<< "accounts:"  << getNbAccounts()  << ";"
				<< "total:"  << getTotalAmount()  << ";"
				<< "deposits:"  << getNbDeposits()  << ";"
				<< "withdrawals:"  << getNbWithdrawals()  << std::endl;
}

Account::~Account() {
	_displayTimestamp();
    std::cout	<< "index:"  << _accountIndex  << ";"
				<< "amount:"  << _amount  << ";"
				<< "closed" << std::endl;
}
