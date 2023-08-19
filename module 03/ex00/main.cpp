/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:40:56 by snaji             #+#    #+#             */
/*   Updated: 2023/08/19 18:55:39 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap A("Didier");

	A.attack("Michel");
	A.takeDamage(5);
	A.beRepaired(3);
	for (int i = 0; i < 9; ++i)
		A.attack("Michel");
}