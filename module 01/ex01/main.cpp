/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:47:39 by snaji             #+#    #+#             */
/*   Updated: 2023/09/12 16:10:48 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>
#include <iostream>

int	main(void)
{
	Zombie	*horde;

	std::cout << "\e[1m\e[3mCreating a horde of 15 zombies\e[0m" << std::endl;
	horde = zombieHorde(15, "Hyppolite");
	for (int i = 0; i < 15; ++i)
		horde[i].announce();

	std::cout << std::endl << "\e[1m\e[3mChanging the name of some zombies\e[0m"
		<< std::endl;
	horde[2].setName("Bastien");
	horde[7].setName("Kevin");
	horde[14].setName("Ulysse");
	for (int i = 0; i < 15; ++i)
		horde[i].announce();

	std::cout << std::endl << "\e[1m\e[3mDeleting the horde\e[0m" << std::endl;
	delete[] horde;
}