/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:21:32 by snaji             #+#    #+#             */
/*   Updated: 2023/08/02 18:42:30 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit): _accountIndex(Account::_nbAccounts++),
	_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	Account::_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
		<< ";created" << std::endl;
}

Account::Account(): _accountIndex(Account::_nbAccounts++),
	_amount(0), _nbDeposits(0), _nbWithdrawals(0) {}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
		<< ";closed" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int	p_amount = this->_amount;

	this->_amount += deposit;
	Account::_totalAmount += deposit;
	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount
		<< ";deposit:" << deposit << ";amount:" << this->_amount
		<< ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int whithdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:"
		<< this->_amount;
	if (this->_amount < whithdrawal)
		return (std::cout << ";withdrawal:refused" << std::endl, false);
	this->_amount -= whithdrawal;
	Account::_totalAmount -= whithdrawal;
	this->_nbWithdrawals += 1;
	Account::_totalNbWithdrawals += 1;
	std::cout << ";withdrawal:" << whithdrawal << ";amount:" << this->_amount
		<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
		<< ";deposits:" << this->_nbDeposits << ";withdrawals:"
		<< this->_nbWithdrawals << std::endl;
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void)
{
	time_t	now = std::time(NULL);
	std::tm	*time = localtime(&now);

	std::cout << std::setfill('0') << "[" << time->tm_year + 1900
		<< std::setw(2) << time->tm_mon + 1
		<< std::setw(2) << time->tm_mday << "_"
		<< std::setw(2) << time->tm_hour
		<< std::setw(2) << time->tm_min
		<< std::setw(2) << time->tm_sec << "] ";
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:"
		<< Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits
		<< ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}
