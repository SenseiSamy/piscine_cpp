/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:15:59 by snaji             #+#    #+#             */
/*   Updated: 2024/01/20 21:26:47 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <utility>
# include <memory>
# define CONTAINER_TYPE Container<Type, std::allocator<Type> >
# define CONTAINER_PAIR Container<std::pair<Type, Type>, std::allocator<std::pair<Type, Type> > >

template <template<typename, typename> typename Container, typename Type>
void	dumbInsertion(CONTAINER_TYPE &main, CONTAINER_TYPE pend)
{
	typename CONTAINER_TYPE::iterator	pendIt;
	typename CONTAINER_TYPE::iterator	mainIt;

	for (pendIt = pend.begin(); pendIt != pend.end(); ++pendIt)
	{
		for (mainIt = main.begin(); mainIt != main.end(); ++mainIt)
		{
			if (*pendIt < *mainIt)
			{
				main.insert(mainIt, *pendIt);
				break;
			}
		}
		if (mainIt == main.end())
			main.insert(mainIt, *pendIt);
	}
}

template <template<typename, typename> typename Container, typename Type>
CONTAINER_TYPE	makeSeqFromPairs(CONTAINER_PAIR &pairs, bool firstEl)
{
	CONTAINER_TYPE	seq;
	typename CONTAINER_PAIR::iterator	it;
	
	for (it = pairs.begin(); it != pairs.end(); ++it)
		seq.push_back(firstEl ? it->first : it->second);
	return (seq);
}

template <template<typename, typename> typename Container, typename Type>
CONTAINER_PAIR	createSortedPairs(CONTAINER_TYPE &seq)
{
	CONTAINER_PAIR	pairs;
	typename CONTAINER_TYPE::iterator	it;
	typename CONTAINER_TYPE::iterator	it2;
	typename CONTAINER_TYPE::iterator	end;

	end = seq.end();
	if (seq.size() % 2 != 0)
		std::advance(end, -1);
	for (it = seq.begin(); it != end; std::advance(it, 2))
	{
		it2 = it;
		std::advance(it2, 1);
		pairs.push_back((*it < *it2) ? std::make_pair(*it, *it2) :
			std::make_pair(*it2, *it));
	}
	return (pairs);
}

template <template<typename, typename> typename Container, typename Type>
CONTAINER_TYPE	_mergeInsertionSort(CONTAINER_TYPE seq)
{
	if (seq.size() < 2)
		return (seq);

	CONTAINER_PAIR	pairs = createSortedPairs(seq);
	CONTAINER_TYPE	main = _mergeInsertionSort(makeSeqFromPairs(pairs, false));
	dumbInsertion(main, makeSeqFromPairs(pairs, true));
	return (main);
}

// Works with a seq that supports push_back, insert, size and has a
// biderectionnal iterator
template <template<typename, typename> typename Container, typename Type>
void	mergeInsertionSort(CONTAINER_TYPE &seq)
{
	seq = _mergeInsertionSort<Container, Type>(seq);
}

#endif