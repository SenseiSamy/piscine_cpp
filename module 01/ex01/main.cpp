/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:47:39 by snaji             #+#    #+#             */
/*   Updated: 2023/08/03 14:41:27 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>
#include <iostream>

int	main(void)
{
	Zombie	*horde;

	std::cout << "Creating a horde of 15 zombies" << std::endl;
	horde = zombieHorde(15, "Hyppolite");
	for (int i = 0; i < 15; ++i)
		horde[i].announce();

	std::cout << std::endl << "Changing the name of some zombies" << std::endl;
	horde[2].setName("Bastien");
	horde[7].setName("Kevin");
	horde[14].setName("Ulysse");
	for (int i = 0; i < 15; ++i)
		horde[i].announce();

	std::cout << std::endl << "Deleting the horde" << std::endl;
	delete[] horde;
}