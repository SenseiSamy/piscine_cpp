/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:54:36 by snaji             #+#    #+#             */
/*   Updated: 2023/09/07 16:56:23 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <string>

class	WrongAnimal
{
	protected:
		std::string	_type;
	
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &a);
		~WrongAnimal(void);

		WrongAnimal &operator=(const WrongAnimal &a);

		std::string	getType(void) const;
		void		makeSound(void) const;
};

#endif