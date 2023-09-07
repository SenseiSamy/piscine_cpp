/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:19:34 by snaji             #+#    #+#             */
/*   Updated: 2023/09/07 18:23:15 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class	Cat: public Animal
{
	private:
		Brain	*_brain;

	public:
		Cat(void);
		Cat(const Cat &c);
		virtual ~Cat(void);

		Cat	&operator=(const Cat &c);

		virtual void	makeSound(void) const;
};

#endif