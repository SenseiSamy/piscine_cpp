/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:47:22 by snaji             #+#    #+#             */
/*   Updated: 2023/08/02 19:58:50 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>

class	Zombie
{
	private:
		std::string	_name;

	public:
		Zombie(void);
		~Zombie(void);
		void	setName(std::string name);
		void	announce(void) const;
};

Zombie	*zombieHorde(int n, std::string name);

#endif