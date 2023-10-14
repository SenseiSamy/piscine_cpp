/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:16:30 by snaji             #+#    #+#             */
/*   Updated: 2023/10/14 16:50:45 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &b)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; ++i)
		this->_ideas[i] = b._ideas[i];
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string	Brain::getIdea(const unsigned int n) const
{
	if (n < 50)
		return (this->_ideas[n]);
	return ("");
}

void		Brain::setIdea(const unsigned int n, const std::string &idea)
{
	if (n < 50)
		this->_ideas[n] = idea;
}

Brain	&Brain::operator=(const Brain &b)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	for (int i = 0; i < 100; ++i)
		this->_ideas[i] = b._ideas[i];
	return (*this);
}
