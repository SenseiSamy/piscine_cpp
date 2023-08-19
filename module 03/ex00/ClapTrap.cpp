/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:14:47 by snaji             #+#    #+#             */
/*   Updated: 2023/08/19 18:55:26 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap(void): _name(""), _HP(10), _EP(10), _AD(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name): _name(name), _HP(10), _EP(10),
	_AD(0)
{
	std::cout << "ClapTrap string constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &a): _name(a._name), _HP(a._HP), _EP(a._EP),
	_AD(a._AD)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &a)
{
	this->_name = a._name;
	this->_HP = a._HP;
	this->_EP = a._EP;
	this->_AD = a._AD;
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_HP <= 0 || this->_EP <= 0)
		std::cout << "ClapTrap " << this->_name << " can not attack"
			<< std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", "
			"causing " << this->_AD << " points of damage!" << std::endl;
		--this->_EP;
	}
}

void	ClapTrap::takeDamage(unsigned int ammount)
{
	std::cout << "ClapTrap " << this->_name << " is taking " << ammount
		<< " points of damage!" << std::endl;
	this->_HP -= ammount;
	if (this->_HP < 0)
		this->_HP = 0;
}

void	ClapTrap::beRepaired(unsigned int ammount)
{
	if (this->_HP <= 0 || this->_EP <= 0)
		std::cout << "ClapTrap " << this->_name << " can not be repaired"
			<< std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " is repairing himself for a"
			"n ammount of " << ammount << " hit points!" << std::endl;
		this->_HP += ammount;
		--this->_EP;
	}
}