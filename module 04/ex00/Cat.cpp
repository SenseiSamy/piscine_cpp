/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:26:14 by snaji             #+#    #+#             */
/*   Updated: 2023/09/07 16:41:21 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void)
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat &c)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_type = c._type;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &c)
{
	std::cout << "Cat copy operator called" << std::endl;
	this->_type = c._type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "meowwㅤ/ᐠ - ˕ -マ" << std::endl;
}
