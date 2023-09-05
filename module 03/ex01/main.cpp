/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:40:56 by snaji             #+#    #+#             */
/*   Updated: 2023/09/05 16:38:54 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	ScavTrap	S("PAUL");

	S.takeDamage(10);
	S.attack("Michel");
	S.takeDamage(5);
	S.beRepaired(3);
	S.takeDamage(100);
	S.attack("Michel");
	S.guardGate();
}