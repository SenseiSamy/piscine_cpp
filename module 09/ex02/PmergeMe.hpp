/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:15:59 by snaji             #+#    #+#             */
/*   Updated: 2024/02/01 20:17:28 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <utility>
# include <memory>
# include <cstddef>
# include <cmath>
# include <algorithm>
# include <iostream>
# define PairContainer Container<Pair<Type>*, std::allocator<Pair<Type>* > >
# define TypeContainer Container<Type, std::allocator<Type> >

extern int nbCompVect;

template <typename Type>
class	Pair
{	
	public:
		void*	left;
		void*	right;
		bool	(*comp)(Type const&, Type const&);

		Pair(void): left(NULL), right(NULL), comp(NULL) {}
		Pair(Pair *l, Pair *r, bool (*c)(Type const&, Type const&)):
			left(l),
			right(r),
			comp(c) {}
		Pair(Type &r, bool (*c)(Type const&, Type const&)):
			left(NULL),
			right(&r),
			comp(c) {}
		Pair(const Pair &copy, bool (*c)(Type const&, Type const&)):
			left(copy.left),
			right(copy.right),
			comp(c) {}
		~Pair(void) {}
		
		Pair&	operator=(const Pair &copy)
		{
			this->left = copy.left;
			this->right = copy.right;
			return (*this);
		}

		bool	operator<(const Pair &rhs)
		{
			if (containsPairs())
				return (*static_cast<Pair<Type>*>(this->right) <
					*static_cast<Pair<Type>*>(rhs.right));
			else if (containsType())
			{
				Type	a = *static_cast<Type*>(this->right);
				Type	b = *static_cast<Type*>(rhs.right);
				return (comp(a, b));
			}
			return (false);
		}

		bool	containsPairs(void) const
		{
			return (left && right);
		}

		bool	containsType(void) const
		{
			return (!left && right);
		}

		void	sort(void)
		{
			if (!containsPairs())
				return;
			if (*static_cast<Pair<Type>*>(right) <
				*static_cast<Pair<Type>*>(left))
				std::swap(left, right);
		}
};

// for debugging
// template <typename Type>
// std::ostream	&operator<<(std::ostream &os, const Pair<Type> &pair)
// {
// 	if (pair.containsPairs())
// 		os << "<" << *static_cast<Pair<Type>*>(pair.left) << ", "
// 			<< *static_cast<Pair<Type>*>(pair.right) << ">";
// 	else if (pair.containsType())
// 		os << *static_cast<Type*>(pair.right);
// 	else
// 		os << "ERROR";
// 	return (os);
// }

// void	printPair(Pair<int> *pair)
// {
// 	if (pair)
// 		std::cerr << *pair;
// 	else
// 		std::cerr << "nullptr";
// }

// template <template<typename, typename> typename Container, typename Type>
// static void	printPairContainer(PairContainer &seq)
// {
// 	typename PairContainer::iterator	it;

// 	std::cout << "[";
// 	for (it = seq.begin(); it != seq.end(); ++it)
// 	{
// 		if (it != seq.begin())
// 			std::cout << ", ";
// 		std::cout << **it;
// 	}
// 	std::cout << "]\n";
// }

template <typename Type>
static inline bool	compUpperBound(Pair<Type>* a, Pair<Type>* b)
{
	return (*a < *b);
}

template <template<typename, typename> typename Container, typename Type>
static PairContainer	insertion(PairContainer &seq, bool has_stray)
{
	static const int64_t jacobsthal_diff[] =
        {2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u, 2730u, 5462u,
		10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u, 1398102u,
		2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
		178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u,
		5726623062u, 11453246122u, 22906492246u, 45812984490u, 91625968982u,
		183251937962u, 366503875926u, 733007751850u, 1466015503702u,
		2932031007402u, 5864062014806u, 11728124029610u, 23456248059222u,
		46912496118442u, 93824992236886u, 187649984473770u, 375299968947542u,
		750599937895082u, 1501199875790165u, 3002399751580331u,
		6004799503160661u, 12009599006321322u, 24019198012642644u,
		48038396025285288u, 96076792050570576u, 192153584101141152u,
		384307168202282304u, 768614336404564608u, 1537228672809129216u,
		3074457345618258432u, 6148914691236516864u};
	
	PairContainer	main;
	int				n = 0;				
	int64_t			toInsert;
	bool			stop = false;
	typename PairContainer::iterator	it = seq.begin();
	typename PairContainer::iterator	end = seq.end();
	typename PairContainer::iterator	insertBound;

	// Insert the larger element of each pair into main
	if (has_stray)
		std::advance(end, -1);
	for (; it != end; std::advance(it, 1))
		main.push_back(static_cast<Pair<Type>*>((*it)->right));
	
	// Insert the remaining pending elements into main
	it = seq.begin();
	main.insert(main.begin(), static_cast<Pair<Type>*>((*it)->left));
	std::advance(it, 1);
	while (it != seq.end() && !stop)
	{
		toInsert = jacobsthal_diff[n];
		if (toInsert > std::distance(it, seq.end()))
		{
			toInsert = std::distance(it, seq.end());
			stop = true;
		}
		std::advance(it, toInsert);
		for (; toInsert > 0; --toInsert)
		{
			std::advance(it, -1);
			if (std::pow(2.0, n + 2) - 1 > main.size())
				insertBound = main.end();
			else
			{
				insertBound = main.begin();
				std::advance(insertBound, static_cast<int>(std::pow(2.0, n + 2))
					- 1);
			}
			main.insert(std::upper_bound(main.begin(), insertBound,
				static_cast<Pair<Type>*>((*it)->left), compUpperBound<Type>),
				static_cast<Pair<Type>*>((*it)->left));
		}
		if (stop)
			break;
		std::advance(it, jacobsthal_diff[n]);
		++n;
	}
	for (it = seq.begin(); it != seq.end(); std::advance(it, 1))
		delete (*it);
	return (main);
}

template <template<typename, typename> typename Container, typename Type>
static PairContainer	createSortedPairs(PairContainer &seq, bool has_stray,
	bool (*comp)(Type const&, Type const&))
{
	PairContainer	pairs;
	typename PairContainer::iterator	it;
	typename PairContainer::iterator	it2;
	typename PairContainer::iterator	end;

	end = seq.end();
	if (has_stray)
		std::advance(end, -1);
	for (it = seq.begin(); it != end; std::advance(it, 2))
	{
		it2 = it;
		std::advance(it2, 1);
		Pair<Type>*	pair = new Pair<Type>(*it, *it2, comp);
		pair->sort();
		pairs.push_back(pair);
	}
	return (pairs);
}

template <template<typename, typename> typename Container, typename Type>
static PairContainer	_mergeInsertionSort(PairContainer seq,
	bool (*comp)(Type const&, Type const&))
{
	if (seq.size() < 2)
		return (seq);

	bool	has_stray = (seq.size() % 2 != 0);
	PairContainer	pairs = createSortedPairs(seq, has_stray, comp);
	PairContainer	main = _mergeInsertionSort(pairs, comp);
	if (has_stray)
		main.push_back(new Pair<Type>(*--seq.end(), NULL, comp));
	main = insertion(main, has_stray);
	return (main);
}

template <template<typename, typename> typename Container, typename Type>
void	mergeInsertionSort(TypeContainer &seq,
	bool (*comp)(Type const&, Type const&))
{
	PairContainer	pairs;
	TypeContainer	sortedSeq;
	typename TypeContainer::iterator	it;
	typename PairContainer::iterator	it2;

	for (it = seq.begin(); it != seq.end(); ++it)
		pairs.push_back(new Pair<Type>(*it, comp));

	pairs = _mergeInsertionSort<Container, Type>(pairs, comp);

	for (it2 = pairs.begin(); it2 != pairs.end(); ++it2)
	{
		sortedSeq.push_back(*static_cast<Type*>((*it2)->right));
		delete (*it2);
	}

	seq = sortedSeq;
}

#endif