/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:01:51 by snaji             #+#    #+#             */
/*   Updated: 2023/08/19 17:04:32 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void): _value(0) {}

Fixed::Fixed(const Fixed &fixedNb)
{
	*this = fixedNb;
}

Fixed::Fixed(const int n): _value(n << Fixed::_fixedPoint) {}

Fixed::Fixed(const float n): _value((int)roundf(n * (1 << Fixed::_fixedPoint)))
{}

Fixed::~Fixed(void) {}

Fixed	&Fixed::operator=(const Fixed &fixedNb)
{
	this->_value = fixedNb.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(const Fixed &fixedNb) const
{
	Fixed	res;

	res._value = this->_value + fixedNb.getRawBits();
	return (res);
}

Fixed	Fixed::operator-(const Fixed &fixedNb) const
{
	Fixed	res;

	res._value = this->_value - fixedNb.getRawBits();
	return (res);
}

Fixed	Fixed::operator-(void) const
{
	Fixed	res;

	res._value = -this->_value;
	return (res);
}

Fixed	Fixed::operator*(const Fixed &fixedNb) const
{
	Fixed	res;

	res._value = (long)(this->_value * fixedNb.getRawBits())
		>> Fixed::_fixedPoint;
	return (res);
}

Fixed	Fixed::operator/(const Fixed &fixedNb) const
{
	Fixed	res;

	res._value = (long)(this->_value << Fixed::_fixedPoint)
		/ fixedNb.getRawBits();
	return (res);
}

bool	Fixed::operator>(const Fixed &fixedNb) const
{
	return (this->_value > fixedNb.getRawBits());
}

bool	Fixed::operator<(const Fixed &fixedNb) const
{
	return (this->_value < fixedNb.getRawBits());
}

bool	Fixed::operator>=(const Fixed &fixedNb) const
{
	return (this->_value >= fixedNb.getRawBits());
}

bool	Fixed::operator<=(const Fixed &fixedNb) const
{
	return (this->_value <= fixedNb.getRawBits());
}

bool	Fixed::operator==(const Fixed &fixedNb) const
{
	return (this->_value == fixedNb.getRawBits());
}

bool	Fixed::operator!=(const Fixed &fixedNb) const
{
	return (this->_value != fixedNb.getRawBits());
}

Fixed	&Fixed::operator++(void)
{
	this->_value += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;

	this->_value += 1;
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	this->_value -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;

	this->_value -= 1;
	return (tmp);
}

int		Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	float	f;

	f = (float)this->toInt();
	f += (float)(this->_value & (((1 << Fixed::_fixedPoint)) - 1))
		/ (1 << Fixed::_fixedPoint);
	return (f);
}

int	Fixed::toInt(void) const
{
	return (this->_value >> Fixed::_fixedPoint);
}

Fixed	&Fixed::min(Fixed &n1, Fixed &n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

const Fixed	&Fixed::min(const Fixed &n1, const Fixed &n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

Fixed	&Fixed::max(Fixed &n1, Fixed &n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

const Fixed	&Fixed::max(const Fixed &n1, const Fixed &n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &fixedNb)
{
	os << fixedNb.toFloat();
	return (os);
}

const int	Fixed::_fixedPoint = 8;
