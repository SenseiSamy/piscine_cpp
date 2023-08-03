/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:14:15 by snaji             #+#    #+#             */
/*   Updated: 2023/07/31 16:38:48 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class	PhoneBook
{
	private:
		int		curr_id;

	public:
		Contact	contacts[8];

		PhoneBook(void);
		~PhoneBook(void);
		void	add(void);
		void	search(void) const;
};

#endif
