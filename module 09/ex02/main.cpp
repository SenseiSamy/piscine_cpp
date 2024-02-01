/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:10:11 by snaji             #+#    #+#             */
/*   Updated: 2024/02/01 20:26:25 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include "PmergeMe.hpp"

int nbCompVect = 0;
int	nbCompList = 0;

template <typename Container>
void	printSeq(Container seq)
{
	typename Container::iterator	it = seq.begin();
	typename Container::iterator	end = seq.end();

	if (seq.size() > 10)
	{
		end = seq.begin();
		std::advance(end, 10);
	}
	std::cout << "[";
	for (it = seq.begin(); it != end; std::advance(it, 1))
	{
		if (it != seq.begin())
			std::cout << ", ";
		std::cout << *it;
	}
	if (it != seq.end())
		std::cout << ", ...";
	std::cout << "]\n";
}

bool	compareVect(int const& a, int const& b)
{
	nbCompVect += 1;
	return (a < b);
}

bool	compareList(int const& a, int const& b)
{
	nbCompList += 1;
	return (a < b);
}

bool	isNumber(char* str)
{
	unsigned int	i = 0;

	if (str == NULL || str[0] == '\0')
		return (false);
	if (str[0] == '-' && str[1] != '\0')
		++i;
	for (; str[i]; ++i)
		if (str[i] < '0' || str[i] > '9')
			return (false);
	return (true);
}

int	main(int ac, char** av)
{
	std::vector<int>	vector;
	std::list<int>		list;
	clock_t				time_vector;
	clock_t				time_list;

	if (ac == 1)
		return (std::cout << "This program takes at least one argument\n", 1);
	for (int i = 1; i < ac; ++i)
		if (!isNumber(av[i]))
			return (std::cout << "Incorrect arguments\n", 1);
	for (int i = 1; i < ac; ++i)
	{
		vector.push_back(std::atoi(av[i]));
		list.push_back(std::atoi(av[i]));
	}

	std::cout << "Before:\t";
	printSeq(vector);
	
	time_vector = clock();
	mergeInsertionSort<std::vector, int>(vector, &compareVect);
	time_vector = clock() - time_vector;

	time_list = clock();
	mergeInsertionSort<std::list, int>(list, &compareList);
	time_list = clock() - time_list;
	
	std::cout << "After:\t";
	printSeq(vector);
	
	std::cout << "Time to process a range of " << ac - 1 << " elements with std"
		"::vector : " << ((float)time_vector) / CLOCKS_PER_SEC * 1000 << "ms with " <<
		nbCompVect << " comparisons\n";
	std::cout << "Time to process a range of " << ac - 1 << " elements with std"
		"::list :   " << ((float)time_list) / CLOCKS_PER_SEC * 1000 << "ms with " <<
		nbCompList << " comparisons\n";
}










// check maxComp

// template <typename Container>
// bool	isSorted(Container seq)
// {
// 	typename Container::iterator	it;
// 	typename Container::iterator	it2;

// 	for (it = seq.begin(); it != --seq.end(); ++it)
// 	{
// 		it2 = it;
// 		++it2;
// 		if (it > it2)
// 			return (false);
// 	}
// 	return (true);
// }

// template <typename Container>
// Container	generateRandomSeq(int size)
// {
// 	Container	randomSeq;

// 	for (int i = 0; i < size; ++i)
// 		randomSeq.push_back(std::rand() % 1000);
// 	return (randomSeq);
// }


// int	main(int ac, char **av)
// {
// 	if (ac != 2)
// 		return (1);

// 	int	n = std::atoi(av[1]);
// 	int	maxComp;
	
// 	std::srand(std::time(NULL));

// 	for (int seqSize = 1; seqSize < 56; ++seqSize)
// 	{
// 		maxComp = 0;
// 		for (int i = 0; i < n; ++i)
// 		{
// 			std::vector<int> randomSeq = generateRandomSeq<std::vector<int> >(seqSize);
// 			nbCompVect = 0;
// 			mergeInsertionSort<std::vector, int>(randomSeq, &compareVect);
// 			if (!isSorted(randomSeq))
// 			{
// 				std::cout << "THIS SEQUENCE IS NOT SORTED !\n";
// 				printSeq(randomSeq);
// 				return (1);
// 			}
// 			if (nbCompVect > maxComp)
// 				maxComp = nbCompVect;
// 		}
// 		std::cout << "seqSize=" << seqSize << " maxComp="  << maxComp << "\n";
// 	}
// 	return (0);
// }