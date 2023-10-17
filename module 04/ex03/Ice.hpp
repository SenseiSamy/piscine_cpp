/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:40:53 by snaji             #+#    #+#             */
/*   Updated: 2023/10/17 17:05:09 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"
# include "ICharacter.hpp"

class	Ice: public AMateria
{
	public:
		Ice(void);
		Ice(const Ice &copy);
		virtual ~Ice(void);
		
		Ice	&operator=(const Ice &copy);

		virtual AMateria	*clone(void) const;
		virtual void		use(ICharacter& target);
};

#endif