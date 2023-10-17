/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:04:09 by snaji             #+#    #+#             */
/*   Updated: 2023/10/17 18:32:17 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure(void): AMateria("Cure") {}

Cure::Cure(const Cure &copy): AMateria(copy._type) {}

Cure::~Cure(void) {}

Cure	&Cure::operator=(const Cure &copy)
{
	return (*this);
}

AMateria	*Cure::clone(void) const
{
	return (new	Cure);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}