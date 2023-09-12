/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:09:20 by snaji             #+#    #+#             */
/*   Updated: 2023/09/12 19:39:52 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>

class Harl
{
	private:
		std::string	_comments[4];
		void (Harl::*_functions[4])(void);

		void		debug(void);
		void		info(void);
		void		warning(void);
		void		error(void);

	public:
		Harl(void);
		~Harl(void);
		void	complain(std::string level);
};

#endif