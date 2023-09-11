/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:26:04 by snaji             #+#    #+#             */
/*   Updated: 2023/09/11 21:12:46 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include "stdlib.h"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;

	while (true)
	{
		std::cout << "> \e[1m";
		std::getline(std::cin, input);
		std::cout << "\e[0m";
		if (!std::cin)
		{
			if (std::cin.eof())
				std::cout << "Error: EOF was reached in stdin" << std::endl;
			else
				std::cout << "Error: error while getting the input"
					<< std::endl;
			return (1);
		}
		if (input.compare("ADD") == 0)
			phonebook.add();
		else if (input.compare("SEARCH") == 0)
			phonebook.search();
		else if (input.compare("EXIT") == 0)
			break;
		else if (input.compare("") == 0)
			continue;
		std::cout << std::endl;
	}
	return (0);
}