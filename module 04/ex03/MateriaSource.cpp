/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:52:17 by snaji             #+#    #+#             */
/*   Updated: 2023/10/19 14:19:57 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	this->_inventory[0] = NULL;
	this->_inventory[1] = NULL;
	this->_inventory[2] = NULL;
	this->_inventory[3] = NULL;
}

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

#include <iostream>
MateriaSource	&MateriaSource::operator=(const MateriaSource &copy)
{
	std::cout << "MateriaSource copy operator overload called\n";
	for (int i = 0; i < 4; ++i)
	{
		if (this->_inventory[i])
			delete (this->_inventory[i]);
		this->_inventory[i] = copy._inventory[i];
	}
	return (*this);
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
		if (this->_inventory[i] && type == this->_inventory[i]->getType())
			return (this->_inventory[i]->clone());
	return (NULL);
}