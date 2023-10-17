/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:07:31 by snaji             #+#    #+#             */
/*   Updated: 2023/10/17 18:47:58 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <string>

class	Character: public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_inventory[4];

	public:
		Character(void);
		Character(const std::string &name);
		Character(const Character &copy);
		virtual ~Character(void);

		Character	&operator=(const Character &copy);

		virtual const std::string	&getName(void) const;
		virtual void				equip(AMateria *m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter &target);
};

#endif