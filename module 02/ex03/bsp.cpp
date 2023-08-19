/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:51:44 by snaji             #+#    #+#             */
/*   Updated: 2023/08/19 17:32:46 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

static Fixed	side(const Point p, const Point p1, const Point p2)
{
	return ((p2.gety() - p1.gety()) * (p.getx() - p1.getx())
		+ ((-p2.getx() + p1.getx()) * (p.gety() - p1.gety())));
}

bool	bsp(const Point a, const Point b, const Point c, const Point p)
{
	bool	b1, b2, b3;

	b1 = side(p, a, b) >= 0;
	b2 = side(p, b, c) >= 0;
	b3 = side(p, c, a) >= 0;
	return (b1 && b2 && b3);
}
