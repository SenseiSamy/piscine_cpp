/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:02:00 by snaji             #+#    #+#             */
/*   Updated: 2023/09/07 17:02:42 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->_type = "Cat";
}

WrongCat::WrongCat(const WrongCat &c)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	this->_type = c._type;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &c)
{
	std::cout << "WrongCat copy operator called" << std::endl;
	this->_type = c._type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "meowwㅤ/ᐠ - ˕ -マ" << std::endl;
}
