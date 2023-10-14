/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:02:50 by snaji             #+#    #+#             */
/*   Updated: 2023/10/14 17:36:15 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>

class	Animal
{
	protected:
		std::string	_type;
	
	public:
		Animal(void);
		Animal(const Animal &a);
		virtual ~Animal(void) = 0;

		Animal &operator=(const Animal &a);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;
};

#endif