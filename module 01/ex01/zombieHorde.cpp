/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:32:23 by snaji             #+#    #+#             */
/*   Updated: 2023/08/02 19:58:43 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

Zombie	*zombieHorde(int n, std::string name)
{
	Zombie	*zombies;

	zombies = new Zombie[n];
	for (int i = 0; i < n; ++i)
		zombies[i].setName(name);
	return (zombies);
}