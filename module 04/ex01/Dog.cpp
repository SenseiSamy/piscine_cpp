/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:39:26 by snaji             #+#    #+#             */
/*   Updated: 2023/10/14 16:58:23 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(void): _brain(new Brain())
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog &d): _brain(new Brain())
{
	std::cout << "Dog default constructor called" << std::endl;
	*this = d;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

Dog	&Dog::operator=(const Dog &d)
{
	std::cout << "Animal copy operator called" << std::endl;
	this->_type = d._type;
	for (int i = 0; i < 50; ++i)
		this->setIdea(i, d.getIdea(i));
	return (*this);
}

std::string	Dog::getIdea(const unsigned int n) const
{
	return (this->_brain->getIdea(n));
}

void		Dog::setIdea(const unsigned int n, const std::string &idea)
{
	this->_brain->setIdea(n, idea);
}

void	Dog::makeSound(void) const
{
	std::cout << "BARKKK GRRR WAF WAF ARGHHH" << std::endl;
}