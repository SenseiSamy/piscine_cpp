/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:40:53 by snaji             #+#    #+#             */
/*   Updated: 2023/09/14 19:05:59 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"

class	Ice: public AMateria
{
	public:
		Ice(void);
		Ice(const Ice &i);
		~Ice(void);
		
		Ice	&operator=(const Ice &i);
		virtual Ice		*clone() const = 0;
		virtual void	use(ICharacter& target);
};

#endif