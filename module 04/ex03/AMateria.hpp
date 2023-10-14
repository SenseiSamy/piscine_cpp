/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:36:11 by snaji             #+#    #+#             */
/*   Updated: 2023/10/14 17:57:25 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <string>

class	AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria(void);
		AMateria(const std::string &type);
		AMateria(const AMateria &m);
		virtual ~AMateria(void);

		AMateria			&operator=(const AMateria &a);
		const std::string	&getType() const; //Returns the materia type
		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter& target);
};

#endif