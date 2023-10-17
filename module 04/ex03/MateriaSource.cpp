/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:52:17 by snaji             #+#    #+#             */
/*   Updated: 2023/10/17 19:07:15 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void): _inventory({NULL, NULL, NULL, NULL}) {}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	*this = copy;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; ++i)
		if (this->_inventory[i])
			delete (this->_inventory[i]);
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &copy)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->_inventory[i])
			delete (this->_inventory[i]);
		this->_inventory[i] = copy._inventory[i];
	}
}

void	MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; ++i)
		if (!this->_inventory[i])
		{
			this->_inventory[i] = materia->clone();
			break;
		}
}

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < 4; ++i)
		if (type == this->_inventory[i]->getType())
			return (this->_inventory[i]->clone());
	return (NULL);
}