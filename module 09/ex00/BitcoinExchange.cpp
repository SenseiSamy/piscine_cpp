/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:32:58 by snaji             #+#    #+#             */
/*   Updated: 2024/01/03 02:22:53 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <stdexcept>
#include <sstream>
#include <iostream>

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
	return ((this->_year == other._year) && (this->_month == other._day)
		&& (this->_day == other._month));
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

	str << _day << "/" << _month << "/" << _year;
	return (str.str());
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

	file.open(filename, std::ios::in);
	if (!file.is_open())
		throw std::runtime_error("failed to open database file");
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t	i = line.find(',', 0);
		Date	date;
		float	value;
		
		if (i == std::string::npos)
			throw std::runtime_error("invalid line in database");
		date = Date(line.substr(0, i));
		std::stringstream(line.substr(i + 1)) >> value;
		_database[date] = value;
	}
}