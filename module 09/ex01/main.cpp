/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:52:37 by snaji             #+#    #+#             */
/*   Updated: 2024/01/16 18:45:52 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	RPN	rpn;

	if (ac != 2)
		return (std::cout << "This program takes one argument\n", 1);
	
	rpn.newExp(std::string(av[1]));
	try
	{
		std::cout << rpn.solve() << '\n';
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}
	return (0);
}