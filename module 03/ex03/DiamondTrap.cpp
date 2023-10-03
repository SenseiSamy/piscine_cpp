/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:23:40 by snaji             #+#    #+#             */
/*   Updated: 2023/10/03 17:46:43 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>
#include <iomanip>

DiamondTrap::DiamondTrap(void): _name("")
{
	this->ClapTrap::_name = "";
	// this->_HP = this->FragTrap::_HP;
	// this->_EP = this->ScavTrap::_EP;
	// this->_AD = this->FragTrap::_AD;
	this->_HP = 100;
	this->_EP = 50;
	this->_AD = 30;
	std::cout << "\e[31mDiamondTrap\e[0m default contructor called"
		<< std::endl;
}

DiamondTrap::DiamondTrap(std::string name): _name(name)
{
	this->ClapTrap::_name = name + "_clap_name";
	// this->_HP = this->FragTrap::_HP;
	// this->_EP = this->ScavTrap::_EP;
	// this->_AD = this->FragTrap::_AD;
	this->_HP = 100;
	this->_EP = 50;
	this->_AD = 30;
	std::cout << "\e[31mDiamondTrap\e[0m string contructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &d)
{
	*this = d;
	std::cout << "\e[31mDiamondTrap\e[0m copy contructor called" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "\e[31mDiamondTrap\e[0m destructor called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &d)
{
	this->_name = d._name;
	this->_HP = d._HP;
	this->_EP = d._EP;
	this->_AD = d._AD;
	return (*this);
}

void	DiamondTrap::whoAmI(void) const
{
	std::cout << std::setw(15) << "Name: " << this->_name << std::endl;
	std::cout << std::setw(15) << "Clap Name: " << this->ClapTrap::_name
		<< std::endl;
}