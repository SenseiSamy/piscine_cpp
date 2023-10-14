/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:08:16 by snaji             #+#    #+#             */
/*   Updated: 2023/10/14 16:51:08 by snaji            ###   ########.fr       */
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

		Brain		&operator=(const Brain &b);
		std::string	getIdea(const unsigned int n) const;
		void		setIdea(const unsigned int n, const std::string &idea);
		
};

#endif