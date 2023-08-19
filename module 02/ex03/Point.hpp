/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:10:36 by snaji             #+#    #+#             */
/*   Updated: 2023/08/19 17:20:19 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class	Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;

	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Fixed &x, const Fixed &y);
		Point(const Point &p);
		~Point(void);

		Point	&operator=(const Point &p);
		Fixed	getx(void) const;
		Fixed	gety(void) const;
};

#endif