/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:26:39 by snaji             #+#    #+#             */
/*   Updated: 2023/09/07 18:23:37 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class	Dog: public Animal
{
	private:
		Brain	*_brain;

	public:
		Dog(void);
		Dog(const Dog &d);
		virtual ~Dog(void);

		Dog	&operator=(const Dog &d);

		virtual void	makeSound(void) const;
};

#endif