/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:51:35 by snaji             #+#    #+#             */
/*   Updated: 2023/10/03 16:48:09 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_name = "";
	this->_HP = 100;
	this->_EP = 50;
	this->_AD = 20;
}

ScavTrap::ScavTrap(const std::string &name)
{
	std::cout << "ScavTrap string constructor called" << std::endl;
	this->_name = name;
	this->_HP = 100;
	this->_EP = 50;
	this->_AD = 20;
}

ScavTrap::ScavTrap(const ScavTrap &a)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	this->_name = a._name;
	this->_HP = a._HP;
	this->_EP = a._EP;
	this->_AD = a._AD;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &a)
{
	this->_name = a._name;
	this->_HP = a._HP;
	this->_EP = a._EP;
	this->_AD = a._AD;
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_HP <= 0 || this->_EP <= 0)
		std::cout << "ScavTrap " << this->_name << " can not attack"
			<< std::endl;
	else
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", "
			"causing " << this->_AD << " points of damage!" << std::endl;
		--this->_EP;
	}
}

void	ScavTrap::guardGate(void) const
{
	if (this->_HP > 0)
		std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode"
			<< std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " can not be in Gate keeper "
			"mode" << std::endl;
}
