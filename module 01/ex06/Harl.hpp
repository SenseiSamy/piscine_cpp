/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:50:42 by snaji             #+#    #+#             */
/*   Updated: 2023/08/28 17:51:23 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>

class	Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:
		enum e_comment
		{
			DEBUG,
			INFO,
			WARNING,
			ERROR
		};

		Harl(void);
		~Harl();
		void	complain(enum Harl::e_comment level);
};

#endif