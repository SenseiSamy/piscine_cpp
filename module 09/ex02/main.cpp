/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:10:11 by snaji             #+#    #+#             */
/*   Updated: 2024/01/25 01:33:46 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include "PmergeMe.hpp"

int nbComp = 0;

template <typename Container>
void	printSeq(Container seq)
{
	typename Container::iterator	it;

	std::cout << "[";
	for (it = seq.begin(); it != seq.end(); ++it)
	{
		if (it != seq.begin())
			std::cout << ", ";
		std::cout << *it;
	}
	std::cout << "]\n";
}

template <typename Container>
bool	isSorted(Container seq)
{
	typename Container::iterator	it;
	typename Container::iterator	it2;

	for (it = seq.begin(); it != --seq.end(); ++it)
	{
		it2 = it;
		++it2;
		if (it > it2)
			return (false);
	}
	return (true);
}

template <typename Container>
Container	generateRandomSeq(int size)
{
	Container	randomSeq;

	for (int i = 0; i < size; ++i)
		randomSeq.push_back(std::rand() % 1000);
	return (randomSeq);
}

bool	compare(int const& a, int const& b)
{
	nbComp += 1;
	return (a < b);
}

int	main(int ac, char **av)
{
	if (ac != 3)
		return (1);

	int	n = std::atoi(av[1]);
	int	seqSize = std::atoi(av[2]);
	int	maxComp = 0;
	int	minComp = 2147483647;
	int	avrgComp = 0;
	
	std::srand(std::time(NULL));

	for (int i = 0; i < n; ++i)
	{
		std::vector<int> randomSeq = generateRandomSeq<std::vector<int> >(seqSize);
		nbComp = 0;
		mergeInsertionSort<std::vector, int>(randomSeq, compare);
		if (!isSorted(randomSeq))
		{
			std::cout << "THIS SEQUENCE IS NOT SORTED !\n";
			printSeq(randomSeq);
			return (1);
		}
		if (nbComp > maxComp)
			maxComp = nbComp;
		if (nbComp < minComp)
			minComp = nbComp;
		avrgComp += nbComp;
	}
	std::cout << "maxComp = " << maxComp << "\n";
	std::cout << "minComp = " << minComp << "\n";
	std::cout << "avrgComp = " << avrgComp / n << "\n";
	return (0);
}