/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:51:19 by snaji             #+#    #+#             */
/*   Updated: 2023/08/17 19:09:26 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed
{
	private:
		static const int	_fixedPoint;
		int					_value;

	public:
		Fixed(void);
		Fixed(const Fixed &fixedNb);
		~Fixed(void);
		Fixed	&operator=(const Fixed &fixedNb);
		int		getRawBits(void) const;
		void	setRawBits(const int raw);
};

#endif