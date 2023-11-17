/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:32:10 by snaji             #+#    #+#             */
/*   Updated: 2023/11/17 18:13:16 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class	Array
{
	private:
		T				*_array;
		unsigned int	_size;

	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array &copy);
		~Array(void);

		Array	&operator=(const Array &copy);
		int		&operator[](int index);
};

#endif