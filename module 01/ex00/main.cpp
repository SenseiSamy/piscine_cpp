/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:12:06 by snaji             #+#    #+#             */
/*   Updated: 2023/09/19 17:28:53 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>
#include <iostream>

int	main(void)
{
	Zombie	*zombie;

	std::cout << "\e[1m\e[3mCreating a Zombie on the heap with newZombie\e[0m"
		<< std::endl;
	zombie = newZombie(std::string("Elina"));
	zombie->announce();
	delete zombie;

	std::cout << std::endl << "\e[1m\e[3mCreating a Zombie on the stack with "
		"randomChump\e[0m" << std::endl;
	randomChump(std::string("Karima"));
}
