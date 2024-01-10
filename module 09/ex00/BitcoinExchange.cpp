/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:32:58 by snaji             #+#    #+#             */
/*   Updated: 2024/01/10 17:14:17 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <stdexcept>
#include <iostream>
#include <iomanip>

Date::Date(void): _year(0), _month(0), _day(0) {}

Date::Date(const std::string &date)
{
	size_t		i = 0;
	std::string	year;
	std::string	month;
	std::string	day;

	while (i < date.size() && date[i] != '-')
		year = year + date[i++];
	++i;
	while (i < date.size() && date[i] != '-')
		month = month + date[i++];
	++i;
	while (i < date.size() && date[i] != '-')
		day = day + date[i++];
	if (year.empty() || month.empty() || day.empty())
		throw std::invalid_argument("invalid date");
	std::stringstream(year) >> _year;
	std::stringstream(month) >> _month;
	std::stringstream(day) >> _day;
}

Date::Date(const Date &copy)
{
	*this = copy;
}

Date::~Date(void) {}

Date	&Date::operator=(const Date &copy)
{
	this->_year = copy._year;
	this->_month = copy._month;
	this->_day = copy._day;
	return (*this);
}

bool	Date::operator==(const Date &other) const
{
	return ((this->_year == other._year) && (this->_month == other._month)
		&& (this->_day == other._day));
}

bool	Date::operator>(const Date &other) const
{
	if (this->_year == other._year)
	{
		if (this->_month == other._month)
			return (this->_day > other._day);
		return (this->_month > other._month);
	}
	return (this->_year > other._year);
}

bool	Date::operator<(const Date &other) const
{
	if (this->_year == other._year)
	{
		if (this->_month == other._month)
			return (this->_day < other._day);
		return (this->_month < other._month);
	}
	return (this->_year < other._year);
}

std::string	Date::print(void) const
{
	std::stringstream	str;

	str << std::setfill('0') << _year << "-" << std::setw(2) << _month
		<< "-" << std::setw(2) << _day;
	return (str.str());
}

bool	Date::isValid(void) const
{
	return (_month <= 12 && _month > 0 && _day <= 31 && _day > 0);
}

BitcoinExchange::BitcoinExchange(void) {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	this->_database = copy._database;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {};

void	BitcoinExchange::filldatabase(const std::string &filename)
{
	std::ifstream	file;
	std::string		line;

	file.open(filename.c_str(), std::ios::in);
	if (!file.is_open())
		throw std::runtime_error("failed to open database file (data.csv)");
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t	i = line.find(',', 0);
		Date	date;
		float	value;
		
		if (i == std::string::npos)
			throw std::runtime_error("invalid line in database");
		date = Date(line.substr(0, i));
		if (!date.isValid())
			throw std::runtime_error("invalid line in database");
		std::stringstream(line.substr(i + 1)) >> value;
		_database[date] = value;
	}
}

std::map<Date, float>::const_iterator	BitcoinExchange::begin(void) const
{
	return (_database.begin());
}

std::map<Date, float>::const_iterator	BitcoinExchange::end(void) const
{
	return (_database.end());
}
