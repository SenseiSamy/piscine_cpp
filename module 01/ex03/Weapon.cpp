/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:18:02 by snaji             #+#    #+#             */
/*   Updated: 2023/08/03 15:57:35 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

Weapon::Weapon(void) {}

Weapon::Weapon(std::string arme): _type(arme) {}

Weapon::~Weapon(void) {}

const std::string	&Weapon::getType(void) const
{
	const std::string	&type = this->_type;

	return (type);
}

void	Weapon::setType(std::string arme)
{
	this->_type = arme;
}
