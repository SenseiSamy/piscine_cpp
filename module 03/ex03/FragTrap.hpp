/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:54:24 by snaji             #+#    #+#             */
/*   Updated: 2023/09/21 17:43:29 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class	FragTrap: virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &a);
		~FragTrap(void);

		FragTrap	&operator=(const FragTrap &t);

		void		highFivesGuys(void) const;
};

#endif