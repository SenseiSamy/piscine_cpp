/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:46:40 by snaji             #+#    #+#             */
/*   Updated: 2023/10/19 14:24:31 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include <string>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class	MateriaSource: public IMateriaSource
{
	private:
		AMateria	*_inventory[4];

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &copy);
		virtual ~MateriaSource(void);

		virtual MateriaSource	&operator=(const MateriaSource &copy);

		virtual void		learnMateria(AMateria *materia);
		virtual AMateria	*createMateria(const std::string &type);
};

#endif