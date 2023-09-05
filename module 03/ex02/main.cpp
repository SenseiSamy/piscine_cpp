/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:40:56 by snaji             #+#    #+#             */
/*   Updated: 2023/09/05 16:58:04 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main(void)
{
	FragTrap	S("WILLIAM");

	S.takeDamage(10);
	S.attack("LOUIS");
	S.takeDamage(5);
	S.beRepaired(3);
	S.takeDamage(100);
	S.attack("LOUIS");
	S.highFivesGuys();
}