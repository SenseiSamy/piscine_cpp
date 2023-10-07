/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:15:10 by snaji             #+#    #+#             */
/*   Updated: 2023/10/07 19:26:54 by snaji            ###   ########.fr       */
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

	std::cout << "\e[1m\e[3mTrying to create a bureaucrat with a grade too low"
		"\e[0m" << std::endl;
	Bureaucrat	b("Pierre", 15);
	std::cout << b;
}