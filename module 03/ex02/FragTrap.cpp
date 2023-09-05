/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:51:35 by snaji             #+#    #+#             */
/*   Updated: 2023/09/05 16:54:19 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_name = "";
	this->_HP = 100;
	this->_EP = 100;
	this->_AD = 30;
}

FragTrap::FragTrap(const std::string &name)
{
	std::cout << "FragTrap string constructor called" << std::endl;
	this->_name = name;
	this->_HP = 100;
	this->_EP = 100;
	this->_AD = 30;
}

FragTrap::FragTrap(const FragTrap &a)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	this->_name = a._name;
	this->_HP = a._HP;
	this->_EP = a._EP;
	this->_AD = a._AD;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &a)
{
	this->_name = a._name;
	this->_HP = a._HP;
	this->_EP = a._EP;
	this->_AD = a._AD;
	return (*this);
}

void	FragTrap::highFivesGuys(void) const
{
	std::cout << "FragTrap " << this->_name << " is requesting positively a "
		"high fives." << std::endl;
}
