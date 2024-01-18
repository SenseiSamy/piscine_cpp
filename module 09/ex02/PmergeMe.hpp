/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:23:07 by snaji             #+#    #+#             */
/*   Updated: 2024/01/18 22:21:03 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <algorithm>

template <typename iterator>
void	MergeInsertSort(iterator first, iterator last)
{
	std::size_t	size = std::distance(first, last);
	if (size < 2)
		return;
	
	bool		is_odd = (size % 2 != 0);
	iterator	end = is_odd ? std::prev(last) : last;
	
	for (iterator it = first; it != end; std::advance(it, 2))
	{
		if ()
	}
}

#endif