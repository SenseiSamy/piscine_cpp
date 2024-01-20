/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:10:11 by snaji             #+#    #+#             */
/*   Updated: 2024/01/20 21:29:51 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "PmergeMe.hpp"

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

int	main(void)
{
	std::list<int>	a;
	
	a.push_back(4);
	a.push_back(2);
	a.push_back(6);
	a.push_back(3);
	a.push_back(9);
	a.push_back(1);
	a.push_back(7);
	a.push_back(5);

	printSeq(a);
	mergeInsertionSort<std::list, int>(a);
	printSeq(a);
}