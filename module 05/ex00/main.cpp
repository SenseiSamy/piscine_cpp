/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:15:10 by snaji             #+#    #+#             */
/*   Updated: 2023/10/09 17:28:42 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "\e[1m\e[3mTrying to create a bureaucrat with a grade too low"
		"\e[0m" << std::endl;
	try
	{
		Bureaucrat	a("Simon", 200);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "\e[1m\e[3mCreating a valid bureaucrat\e[0m"
		<< std::endl;
	Bureaucrat	b("Pierre", 2);
	std::cout << b;

	std::cout << std::endl << "\e[1m\e[3mUpgrading him to grade 1\e[0m"
		<< std::endl;
	b.upgrade();
	std::cout << b;

	std::cout << std::endl << "\e[1m\e[3mTrying to upgrade him again\e[0m"
		<< std::endl;
	try
	{
		b.upgrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}