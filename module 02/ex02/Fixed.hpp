/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:51:19 by snaji             #+#    #+#             */
/*   Updated: 2023/08/18 04:28:27 by snaji            ###   ########.fr       */
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
		Fixed	operator+(const Fixed &fixedNb) const;
		Fixed	operator-(const Fixed &fixedNb) const;
		Fixed	operator*(const Fixed &fixedNb) const;
		Fixed	operator/(const Fixed &fixedNb) const;
		bool	operator>(const Fixed &fixedNb) const;
		bool	operator<(const Fixed &fixedNb) const;
		bool	operator>=(const Fixed &fixedNb) const;
		bool	operator<=(const Fixed &fixedNb) const;
		bool	operator==(const Fixed &fixedNb) const;
		bool	operator!=(const Fixed &fixedNb) const;
		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);

		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed		&min(Fixed &n1, Fixed &n2);
		static const Fixed	&min(const Fixed &n1, const Fixed &n2);
		static Fixed		&max(Fixed &n1, Fixed &n2);
		static const Fixed	&max(const Fixed &n1, const Fixed &n2);
};

std::ostream	&operator<<(std::ostream &os, const Fixed &fixedNb);

#endif