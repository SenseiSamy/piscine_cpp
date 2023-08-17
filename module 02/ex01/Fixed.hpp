/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:51:19 by snaji             #+#    #+#             */
/*   Updated: 2023/08/17 21:47:19 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class	Fixed
{
	private:
		static const int	_fixedPoint;
		int					_value;

	public:
		Fixed(void);
		Fixed(const Fixed &fixedNb);
		Fixed(const int n);
		Fixed(const float n);
		~Fixed(void);
		Fixed	&operator=(const Fixed &fixedNb);
		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &os, const Fixed &fixedNb);

#endif