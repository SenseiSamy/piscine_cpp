/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:21:25 by snaji             #+#    #+#             */
/*   Updated: 2023/08/19 17:34:47 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): _x(Fixed()), _y(Fixed()) {}

Point::Point(const float x, const float y): _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(const Fixed &x, const Fixed &y): _x(x), _y(y) {}

Point::Point(const Point &p): _x(p.getx()), _y(p.gety()) {}

Point::~Point(void) {}

Point	&Point::operator=(const Point &p)
{
	(void)p;
	return (*this);
}

Fixed	Point::getx(void) const
{
	return (this->_x);
}

Fixed	Point::gety(void) const
{
	return (this->_y);
}
