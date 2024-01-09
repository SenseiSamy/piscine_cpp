/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 03:11:15 by snaji             #+#    #+#             */
/*   Updated: 2024/01/03 02:42:12 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

bool	analyse_file(std::string filename, BitcoinExchange &database)
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
		std::string		tmp ;
		
	}
}

int	main(int ac, char **av)
{
	BitcoinExchange	A;

	try
	{
		A.filldatabase("data.csv");
	}
	catch(const std::exception& e)
	{
		std::cerr << "ERROR: " << e.what() << '\n';
	}
	
	// std::map<Date, float>::iterator	it = A._database.begin();
	// while (it != A._database.end())
	// {
	// 	std::cout << it->first.print() << "\t" << it->second << "\n";
	// 	++it; 
	// }
}