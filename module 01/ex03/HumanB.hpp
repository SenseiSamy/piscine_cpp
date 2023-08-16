/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:33:55 by snaji             #+#    #+#             */
/*   Updated: 2023/08/03 15:58:32 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <string>
# include "Weapon.hpp"

class	HumanB
{
	private:
		std::string	_name;
		Weapon		_weapon;

	public:
		HumanB(std::string name);
		~HumanB(void);
		void	setWeapon(Weapon &weapon);
		void	attack(void) const;
};

#endif