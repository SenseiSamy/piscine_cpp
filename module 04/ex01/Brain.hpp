/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:08:16 by snaji             #+#    #+#             */
/*   Updated: 2023/10/13 17:38:33 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>

class	Brain
{
	private:
		std::string	_ideas[100];

	public:
		Brain(void);
		Brain(const Brain &b);
		~Brain(void);

		Brain	&operator=(const Brain &b);
};

#endif