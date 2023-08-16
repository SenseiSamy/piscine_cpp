/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:12:06 by snaji             #+#    #+#             */
/*   Updated: 2023/08/02 19:17:16 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

int	main(void)
{
	Zombie	*zombie;

	zombie = newZombie(std::string("Elina"));
	zombie->announce();
	delete zombie;

	randomChump(std::string("Karima"));
}
