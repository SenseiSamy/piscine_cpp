/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:54:33 by snaji             #+#    #+#             */
/*   Updated: 2023/09/14 19:04:57 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void): _type("") {}

AMateria::AMateria(const std::string &type): _type(type) {}

AMateria::AMateria(const AMateria &a): _type(a._type) {}

AMateria::~AMateria(void) {}

AMateria	&AMateria::operator=(const AMateria &a)
{
	this->_type = a._type;
	return (*this);
}

const std::string	&AMateria::getType(void) const
{
	return (this->_type);
}
