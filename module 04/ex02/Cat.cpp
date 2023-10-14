/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:26:14 by snaji             #+#    #+#             */
/*   Updated: 2023/10/14 16:55:09 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void): _brain(new Brain())
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat &c): _brain(new Brain())
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = c;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

Cat	&Cat::operator=(const Cat &c)
{
	std::cout << "Cat copy operator called" << std::endl;
	this->_type = c._type;
	for (int i = 0; i < 50; ++i)
		this->setIdea(i, c.getIdea(i));
	return (*this);
}

std::string	Cat::getIdea(const unsigned int n) const
{
	return (this->_brain->getIdea(n));
}

void		Cat::setIdea(const unsigned int n, const std::string &idea)
{
	this->_brain->setIdea(n, idea);
}

void	Cat::makeSound(void) const
{
	std::cout << "meowwㅤ/ᐠ - ˕ -マ" << std::endl;
}
