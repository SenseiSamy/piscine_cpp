/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:12:51 by snaji             #+#    #+#             */
/*   Updated: 2023/11/29 18:00:52 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void	iter(T *tab, unsigned int length, void (*f)(T &))
{
	unsigned int	i;

	for (i = 0; i < length; ++i)
		f(tab[i]);
}

#endif
