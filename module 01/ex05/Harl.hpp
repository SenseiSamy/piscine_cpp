/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:09:20 by snaji             #+#    #+#             */
/*   Updated: 2023/08/16 19:28:38 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <map>
#include <string>

class Harl
{
	private:
		typedef std::map<std::string, void (Harl::*)(void)> harlmap;
		static harlmap	_comments;

		static harlmap	init_map(void);
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:
		Harl(void);
		~Harl(void);
		void	complain(std::string level);
};

#endif