/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:06:14 by snaji             #+#    #+#             */
/*   Updated: 2023/08/28 13:32:54 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>
#include <iostream>

int	main(int ac, char **argv)
{
	std::string				input;
	enum Harl::e_comment	level;
	Harl					harl;

	if (ac != 2)
	{
		std::cout << "This program takes exactly one parameter" << std::endl;
		return (1);
	}
	input = argv[1];
	if (input == "DEBUG")
		level = Harl::DEBUG;
	else if (input == "INFO")
		level = Harl::INFO;
	else if (input == "WARNING")
		level = Harl::WARNING;
	else if (input == "ERROR")
		level = Harl::ERROR;
	else
	{
		std::cout << "[ Probably complaining about insignificant problems ]"
			<< std::endl;
		return (0);
	}
	harl.complain(level);
	return (0);
}
