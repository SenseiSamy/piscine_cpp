/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:02:00 by snaji             #+#    #+#             */
/*   Updated: 2023/09/05 16:31:25 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <string>

class ClapTrap
{
	protected:
		std::string	_name;
		int			_HP;
		int			_EP;
		int			_AD;

	public:
		ClapTrap(void);
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &a);
		~ClapTrap(void);

		ClapTrap	&operator=(const ClapTrap &a);

		void	attack(const std::string &target);
		void	takeDamage(unsigned int ammount);
		void	beRepaired(unsigned int ammount);
};

#endif