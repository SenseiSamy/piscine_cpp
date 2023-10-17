/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:29:22 by snaji             #+#    #+#             */
/*   Updated: 2023/10/17 18:34:50 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void): _name(""), _inventory({NULL, NULL, NULL, NULL}) {}

Character::Character(const std::string &name): _name(name),
	_inventory({NULL, NULL, NULL, NULL}) {}

Character::Character(const Character &copy)
{
	*this = copy;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; ++i)
		if (this->_inventory[i])
			delete (this->_inventory[i]);
}

Character	&Character::operator=(const Character &copy)
{
	this->_name = copy._name;
	for (int i = 0; i < 4; ++i)
	{
		if (this->_inventory[i])
			delete (this->_inventory[i]);
		this->_inventory[i] = copy._inventory[i];
	}
	return (*this);	
}

const std::string	&Character::getName(void) const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; ++i)
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			break;
		}
}

void	Character::unequip(int idx)
{
	if (idx < 4 && idx >= 0)
		this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4)
		this->_inventory[idx]->use(target);
}