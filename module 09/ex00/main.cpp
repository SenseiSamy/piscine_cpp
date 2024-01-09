/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 03:11:15 by snaji             #+#    #+#             */
/*   Updated: 2024/01/09 17:53:00 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int	parse_line(std::string line, Date &date, float &value)
{
	std::string	tmp;
	std::size_t	pos;

	pos = line.find(" | ");
	if (pos == std::string::npos)
		return (1);
	tmp = line.substr(0, pos);
	try
	{
		date = Date(tmp);
	}
	catch (std::exception &e)
	{
		return (1);
	}
	tmp = line.substr(pos + 3);
	std::stringstream(tmp) >> value;
	return (0);
}

float	get_exchange_rate(Date date, BitcoinExchange &database)
{
	std::map<Date, float>::const_iterator	it = database.begin();
	std::map<Date, float>::const_iterator	closest_date;

	closest_date = it;
	while (it != database.end())
	{
		if (date == it->first)
 			return (it->second);
		if (it->first < date && it->first > closest_date->first)
			closest_date = it;
		++it;
	}
	return (closest_date->second);
}

bool	analyse_file(char *filename, BitcoinExchange &database)
{
	std::ifstream	file;
	std::string		line;
	Date			date;
	float			value;

	file.open(filename);
	if (!file.is_open())
		return (false);
	std::getline(file, line);
	while (std::getline(file, line))
	{
		if (parse_line(line, date, value) == 1)
			std::cout << "Error: invalid line: '" << line << "'\n";
		else if (!date.isValid())
			std::cout << "Error: invalid date: '" << date.print() << "'\n";
		else if (value > 1000.0f)
			std::cout << "Error: number too large\n";
		else if (value < 0.0f)
			std::cout << "Error: not a positive number\n";
		else
		{
			float	modif = get_exchange_rate(date, database);
			std::cout << date.print() << " => " << value << " * " << modif
				<< " = " << value * modif << "\n";
		}
	}
	return (true);
}

int	main(int ac, char **av)
{
	BitcoinExchange	A;

	if (ac != 2)
		return (std::cout << "This program takes one argument\n", 1);

	try
	{
		A.filldatabase("data.csv");
	}
	catch(const std::exception& e)
	{
		std::cerr << "ERROR: " << e.what() << '\n';
	}

	analyse_file(av[1], A);
}