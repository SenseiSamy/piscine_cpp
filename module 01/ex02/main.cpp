/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:49:19 by snaji             #+#    #+#             */
/*   Updated: 2023/09/12 16:20:50 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << std::setw(25) << "\e[1m&string\e[0m = " << &string
		<< std::endl;
	std::cout << std::setw(25) << "\e[1mstringPTR\e[0m = " << stringPTR
		<< std::endl;
	std::cout << std::setw(25) << "\e[1m&stringREF\e[0m = " << &stringREF
		<< std::endl << std::endl;

	std::cout << std::setw(25) << "\e[1mstring\e[0m = " << string
		<< std::endl;
	std::cout << std::setw(25) << "\e[1m*stringPTR\e[0m = " << *stringPTR
		<< std::endl;
	std::cout << std::setw(25) << "\e[1mstringREF\e[0m = " << stringREF
		<< std::endl;
}
