/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:02:07 by snaji             #+#    #+#             */
/*   Updated: 2023/10/14 18:03:48 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"

class	Cure: public AMateria
{
	public:
		Cure(void);
		Cure(const Cure &copy);
		virtual ~Cure(void);

		Cure	&operator=(const Cure &copy);

		virtual AMateria	*clone(void) const;
		virtual void		use(ICharacter& target);
};

#endif