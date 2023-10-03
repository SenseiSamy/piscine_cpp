/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:53:50 by snaji             #+#    #+#             */
/*   Updated: 2023/10/03 17:56:14 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int	main(void)
{
	DiamondTrap	A("Pierre");
	DiamondTrap	B("Julien");

	std::cout << std::endl << "\e[1m\e[3mCalling .whoAmI() on DiamondTrap A\e[0"
		"m" << std::endl;
	A.whoAmI();
	
	std::cout << std::endl << "\e[1m\e[3mCalling .whoAmI() on DiamondTrap B\e[0"
		"m" << std::endl;
	B.whoAmI();

	std::cout << std::endl << "\e[1m\e[3mCalling .attack() on DiamondTrap B\e[0"
		"m" << std::endl;
	B.attack("Catherine");
	std::cout << std::endl;
}