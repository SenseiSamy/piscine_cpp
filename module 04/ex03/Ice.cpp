/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:04:09 by snaji             #+#    #+#             */
/*   Updated: 2023/10/17 18:33:49 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice(void): AMateria("ice") {}

Ice::Ice(const Ice &copy): AMateria(copy._type) {}

Ice::~Ice(void) {}

Ice	&Ice::operator=(const Ice &copy)
{
	return (*this);
}

AMateria	*Ice::clone(void) const
{
	return (new	Ice);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *\n";
}