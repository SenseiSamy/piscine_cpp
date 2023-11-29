/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 00:11:57 by snaji             #+#    #+#             */
/*   Updated: 2023/11/25 00:24:37 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>

template <typename T>
int	&easyfind(T container, int n)
{
	std::T::iterator	i;

	for	(i = container.begin(); i != container.end(); ++i)
		if (*i == n)
			return (*i);
	throw std::runtime_error("int not found");
}