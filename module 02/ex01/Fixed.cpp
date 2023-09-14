/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:01:51 by snaji             #+#    #+#             */
/*   Updated: 2023/09/14 18:16:25 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixedNb)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixedNb;
}

Fixed::Fixed(const int n): _value(n << Fixed::_fixedPoint)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n): _value((int)roundf(n * (1 << Fixed::_fixedPoint)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &fixedNb)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = fixedNb._value;
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	float	f;

	f = (float)this->toInt();
	f += (float)(this->_value & ((1 << Fixed::_fixedPoint)) - 1)
		/ (1 << Fixed::_fixedPoint);
	return (f);
}

int	Fixed::toInt(void) const
{
	return (this->_value >> Fixed::_fixedPoint);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &fixedNb)
{
	os << fixedNb.toFloat();
	return (os);
}

const int	Fixed::_fixedPoint = 8;
