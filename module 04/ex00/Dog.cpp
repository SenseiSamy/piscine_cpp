/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:39:26 by snaji             #+#    #+#             */
/*   Updated: 2023/09/06 17:53:16 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(void)
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog &d)
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = d._type;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &d)
{
	std::cout << "Animal copy operator called" << std::endl;
	this->_type = d._type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "BARKKK GRRR WAF WAF ARGHHH" << std::endl;
}